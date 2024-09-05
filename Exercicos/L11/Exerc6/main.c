#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define READ_WRITE_CREATE  "w+b"
#define READ_WRITE_OPEN    "r+b"
#define FILENAME_1           "aluno.dat"
#define FILENAME_2           "aluno.ind"

typedef struct {
    char nome[40];
    char sexo;
    int n_horas_estudo;
} TDADOS;

void GravaRegistroOrdenadoNome (TDADOS e, FILE *f);  //detalhar
void GravaOrdenadoHorasEstudo(TDADOS e, FILE *f);  //detalhar
void OrdenaHorasEstudo(FILE *f1, FILE *f2);   //detalhar
void ImprimeQuantosPorHorasEstudo(FILE *f);  //detalhar
void GeraNome(char nome[], int tam);  //detalhar
char GeraSexo();  //detalhar
void GeraHorasEstudo(int *horas);  //detalhar
void LeRegistro(TDADOS *aluno);  //detalhar


void FechaArq(FILE *pfile) {
    if(pfile!=NULL)
        fclose(pfile);
}

int ExisteArq(char *fileame) {
    FILE *pfile;
    int existe=1;
    if ((pfile = fopen(fileame, READ_WRITE_OPEN)) == NULL)
        existe=0;
    else
        FechaArq(pfile);
    return(existe);
}

FILE *AbreArq(char *filename) {
    FILE *pfile;
    char modo[3];

    if(ExisteArq(filename))
        strcpy(modo,READ_WRITE_OPEN);
    else
        strcpy(modo,READ_WRITE_CREATE);

    if ((pfile = fopen(filename, modo)) == NULL) {
        printf("\nERRO criando e abrindo %s\n",filename);
        exit (100);
    }

    return(pfile);
}

int EmptyFile(FILE *f) {
    long l=ftell(f);
    int resul;
    fseek(f, 0, SEEK_END);
    resul=ftell(f)==0;
    fseek(f, l, SEEK_SET);
    return(resul);
}

int CountRecords(FILE *f) {
    long temp=ftell(f);
    fseek(f,0,SEEK_END);
    long end=ftell(f);
    fseek(f,temp,SEEK_SET);
    return((end/sizeof(TDADOS)));
}

int RecordCurrent(FILE *f) {
    return((ftell(f)/sizeof(TDADOS))+1);
}

void SeekNext(FILE *f) {
    fseek(f,sizeof(TDADOS),SEEK_CUR);
}

void SeekPrior(FILE *f) {
    fseek(f,sizeof(TDADOS)*-1,SEEK_CUR);
}

void SeekEnd(FILE *f) {
    fseek(f,0,SEEK_END);
}

void SeekFirst(FILE *f) {
    fseek(f,0,SEEK_SET);
}

int isEOF(FILE *f) {
    return(feof(f));
}

int isFirst(FILE *f) {
    return(ftell(f)==0);
}

int ReadRecord(FILE *f, TDADOS *record) {
    int n=fread(record,sizeof(TDADOS),1,f);
    return(n);
}

void WriteRecord(FILE *f, TDADOS record) {
    fwrite(&record,sizeof(TDADOS),1,f);
    fflush(f);
}

void WriteRecordEnd(FILE *f, TDADOS record) {
    fseek(f,0,SEEK_END);
    WriteRecord(f,record);
}

void GravaRegistroOrdenadoNome(TDADOS e, FILE *f) {
    TDADOS reg, ant, prox;
    int frente=0;
    int nrecords=0;
    int nrecord_current=0;

    if(EmptyFile(f)) {
        WriteRecordEnd(f,e); //gravando o primeiro registro
    } else {
        SeekFirst(f);
        do {
            if( ReadRecord(f,&reg) > 0 ) {
                if(strcmp(reg.nome,e.nome)>0) {
                    frente=1;
                    SeekPrior(f);
                }
            }
        } while(!isEOF(f) && !frente);
        if(frente) {
            ant=e;
            nrecords=CountRecords(f);
            nrecord_current=RecordCurrent(f);
            int cont=nrecords - nrecord_current+1;
            do {
                ReadRecord(f,&prox);
                SeekPrior(f);
                WriteRecord(f,ant);
                ant=prox;
                cont--;
            } while(cont > 0);
            WriteRecordEnd(f,prox);
        } else {
            WriteRecordEnd(f,e);
        }
    }
}

void GravaOrdenadoHorasEstudo(TDADOS e, FILE *f) {
    TDADOS reg, ant, prox;
    int frente=0;
    int nrecords=0;
    int nrecord_current=0;

    if(EmptyFile(f)) {
        WriteRecordEnd(f,e);
    } else {
        SeekFirst(f);
        do {
            if( ReadRecord(f,&reg) > 0 ) {
                if(reg.n_horas_estudo<e.n_horas_estudo) {
                    frente=1;
                    SeekPrior(f);
                }
            }
        } while(!isEOF(f) && !frente);
        if(frente) {
            ant=e;
            nrecords=CountRecords(f);
            nrecord_current=RecordCurrent(f);
            int cont=nrecords - nrecord_current+1;
            do {
                ReadRecord(f,&prox);
                SeekPrior(f);
                WriteRecord(f,ant);
                ant=prox;
                cont--;
            } while(cont > 0);
            WriteRecordEnd(f,prox);
        } else {
            WriteRecordEnd(f,e);
        }
    }
}

void OrdenaHorasEstudo(FILE *f1, FILE *f2) {
    TDADOS t;

    if(!EmptyFile(f1)) {
            SeekFirst(f1);
            do {
                if( ReadRecord(f1,&t) > 0 ) {
                    GravaOrdenadoHorasEstudo(t,f2);
                }
            } while( !isEOF(f1) );
    }
}
void ImprimeQuantosPorHorasEstudo(FILE *f) {
    TDADOS t, ant;
    int c=0, total=0;

    ant.n_horas_estudo=-1;
    if(!EmptyFile(f)) {
            SeekFirst(f);
            do {
                if( ReadRecord(f,&t) > 0 ) {
                    if(ant.n_horas_estudo==-1) {
                        c=1;
                        ant.n_horas_estudo=t.n_horas_estudo;
                    }
                    else {
                        if(ant.n_horas_estudo==t.n_horas_estudo)
                            c++;
                        else {
                            printf("\nHoras de %d tem %d alunos.",ant.n_horas_estudo,c);
                            total+=c;
                            c=1;
                            ant.n_horas_estudo=t.n_horas_estudo;
                        }
                    }
                }
            } while( !isEOF(f) );
            if(c>0) {
                total+=c;
                printf("\nHoras de %d tem %d alunos.",ant.n_horas_estudo,c);
            }
    }
    printf("\n\nTotal de alunos %d\n\n",total,c);
}

void flush_in() {
   int ch;
   while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

char geraAlfabeto() {
    int i;
    char letras[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    i=rand()%26;
    return(letras[i]-32);
}

char geraNumero() {
    int i;
    char numeros[] = { '0','1','2','3','4','5','6','7','8','9'};

    i=rand()%9;
    return(numeros[i]);
}

void GeraNome(char nome[], int tam) {
    int i;

    for(i=0;i<tam-1;i++)
        nome[i]=geraAlfabeto();
    nome[tam-1]='\0';
}

char GeraSexo() {
    char s;

    do {
        s=geraNumero();
    } while( s!='0' && s!='1' );
    switch (s) {
        case '0': s = 'm'; break;
        case '1': s = 'f'; break;
    };
    return(s);
}

void GeraHorasEstudo(int *horas) {
    char h[2];

    do {
        h[0]=geraNumero();
        h[1]='\0';
        *horas=atoi(h);
    } while( *horas > 8 );
}

void LeRegistro(TDADOS *aluno) {

    GeraNome(aluno->nome,40);
    aluno->sexo=GeraSexo();
    GeraHorasEstudo(&aluno->n_horas_estudo);
    ImprimeRegistro(*aluno);
}

void ImprimeRegistro(TDADOS p) {
    printf("\nNOME: %s SEXO:%c HORAS:%d" ,p.nome,p.sexo,p.n_horas_estudo);
}

void ImprimeRegistros(FILE *f) {
    TDADOS p;

    printf("\n\nRELATORIO (%d registros)",CountRecords(f));
    SeekFirst(f);
    do {
        if( ReadRecord(f,&p) > 0 )
            ImprimeRegistro(p);
    } while( !isEOF(f) );
    printf("\n\nRegistros (%d)\n",CountRecords(f));
}

int main(int argc, char** argv) {
    FILE *f1=NULL, *f2=NULL;
    TDADOS a;
    int i;

    srand(time(NULL));

    f1=AbreArq(FILENAME_1);
    for(i=0;i<10;i++) {
        LeRegistro(&a);
        GravaRegistroOrdenadoNome(a,f1);
    }
    ImprimeRegistros(f1);

    f2=AbreArq(FILENAME_2);
    OrdenaHorasEstudo(f1,f2);
    ImprimeRegistros(f2);

    ImprimeQuantosPorHorasEstudo(f2);

    FechaArq(f1);
    FechaArq(f2);

    return 0;
}

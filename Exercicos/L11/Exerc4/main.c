//4.	Escreva um algoritmo que, dados dois arquivos ordenados
//      por um campo NOME, gere um terceiro arquivo também ordenado.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define READ_WRITE_CREATE  "w+b"
#define READ_WRITE_OPEN    "r+b"
#define FILENAME_1           "pessoa1.ind"
#define FILENAME_2           "pessoa2.ind"
#define FILENAME_3           "pessoa3.ind"

typedef struct {
    char nome[40];
    int idade;
} PESSOA;

void JuntaArquivos(FILE *f1, FILE *f2, FILE *f3);  //detalhar

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
    return((end/sizeof(PESSOA)));
}

int RecordCurrent(FILE *f) {
    return((ftell(f)/sizeof(PESSOA))+1);
}

void SeekNext(FILE *f) {
    fseek(f,sizeof(PESSOA),SEEK_CUR);
}

void SeekPrior(FILE *f) {
    fseek(f,sizeof(PESSOA)*-1,SEEK_CUR);
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

int ReadRecord(FILE *f, PESSOA *record) {
    int n=fread(record,sizeof(PESSOA),1,f);
    return(n);
}

void WriteRecord(FILE *f, PESSOA record) {
    fwrite(&record,sizeof(PESSOA),1,f);
    fflush(f);
}

void WriteRecordEnd(FILE *f, PESSOA record) {
    fseek(f,0,SEEK_END);
    WriteRecord(f,record);
}

void GravaRegistroOrdenadoNome(PESSOA e, FILE *f) {
    PESSOA reg, ant, prox;
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

void JuntaArquivos(FILE *f1, FILE *f2, FILE *f3) {
    PESSOA reg1, reg2;
    int n1, n2;

    SeekFirst(f1);
    SeekFirst(f2);
    n1=ReadRecord(f1,&reg1);
    n2=ReadRecord(f2,&reg2);
    do {
        //printf("\n%d %d --> %s   %s",n1,n2,reg1.nome,reg2.nome);
        if( n1>0 && n2==0 ) {
            WriteRecord(f3,reg1);
            n1=ReadRecord(f1,&reg1);
        }
        if( n1==0 && n2>0 ) {
            WriteRecord(f3,reg2);
            n2=ReadRecord(f2,&reg2);
        }
        if( n1>0 && n2>0 ) {
            if(strcmp(reg1.nome,reg2.nome)>=0) {
                WriteRecord(f3,reg2);
                n2=ReadRecord(f2,&reg2);
            } else {
                WriteRecord(f3,reg1);
                n1=ReadRecord(f1,&reg1);
            }
        }
    } while(n1>0 || n2>0);
    //printf("\n%d %d --> %s   %s",n1,n2,reg1.nome,reg2.nome);
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

void GeraIdade(int *idade) {
    char id[3];

    id[0]=geraNumero();
    id[1]=geraNumero();
    id[2]='\0';
    *idade=atoi(id);
}

void LeRegistro(PESSOA *empr) {

    GeraNome(empr->nome,40);
    GeraIdade(&empr->idade);
    //ImprimeRegistro(*empr);
}

void ImprimeRegistro(PESSOA p) {
    printf("\nNOME: %s IDADE:%d",p.nome,p.idade);
}

void ImprimeRegistros(FILE *f) {
    PESSOA p;

    printf("\n\nRELATORIO (%d registros)",CountRecords(f));
    SeekFirst(f);
    do {
        if( ReadRecord(f,&p) > 0 )
            ImprimeRegistro(p);
    } while( !isEOF(f) );
    printf("\n\nRegistros (%d)",CountRecords(f));
}

int main(int argc, char** argv) {
    FILE *f1=NULL, *f2=NULL, *f3=NULL;
    PESSOA e;
    int i;

    srand(time(NULL));

    f1=AbreArq(FILENAME_1);
    for(i=0;i<10;i++) {
        LeRegistro(&e);
        GravaRegistroOrdenadoNome(e,f1);
    }
    ImprimeRegistros(f1);
    getch();

    f2=AbreArq(FILENAME_2);
    for(i=0;i<5;i++) {
        LeRegistro(&e);
        GravaRegistroOrdenadoNome(e,f2);
    }
    ImprimeRegistros(f2);
    getch();

    f3=AbreArq(FILENAME_3);
    JuntaArquivos(f1,f2,f3);
    ImprimeRegistros(f3);

    FechaArq(f1);
    FechaArq(f2);
    FechaArq(f3);

    return 0;
}

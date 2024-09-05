//3.	Escreva uma rotina que inclua um registro num arquivo de
//      registros ordenado pelo campo NOME de modo que o
//      arquivo se mantenha ordenado, sem utilizar um arquivo auxiliar.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define READ_WRITE_CREATE  "w+b"
#define READ_WRITE_OPEN    "r+b"
#define FILENAME           "pessoa.ind"

typedef struct {
    char nome[40];
    int idade;
} PESSOA;

void FechaArq(FILE *pfile);
int ExisteArq();
FILE *AbreArq();
int EmptyFile(FILE *f);
 int CountRecords(FILE *f);  //devolve quantos registros existem
int RecordCurrent(FILE *f); //devolve a posição do registro 1, 2, 3, ...
void SeekNext(FILE *f);	//aponta para próximo registro
void SeekPrior(FILE *f);	//aponta para registro anterior
void SeekEnd(FILE *f); 	//aponta para final do arquivo
void SeekFirst(FILE *f);	//aponta para primeiro registro
int isEOF(FILE *f);  //devolve 1 se apontador esta final arquivo ou 0 caso contrario
int isFirst(FILE *f);  //devolve 1 se apontar esta no primeiro registro ou 0 caso contrario
int ReadRecord(FILE *f, PESSOA *record);  //le registro do arquivo e devolve quantos bytes lidos
void WriteRecord(FILE *f, PESSOA record); //grava um registro na posição corrente do arquivo
void WriteRecordEnd(FILE *f, PESSOA record);	//grava um registro no final do arquivo
void GravaRegistroOrdenadoNome(PESSOA e, FILE *f);  //detalhar
void flush_in();
char geraAlfabeto();  //devolve uma letra aleatória do alfabeto ‘a’..’z’
char geraNumero();  //devolve um número aleatório 0..9
void GeraNome(char nome[], int tam); //detalhar
void GeraIdade(int *idade); //detalhar
void LeRegistro(PESSOA *empr);   //detalhar
void ImprimeRegistro(PESSOA p);
void ImprimeRegistros(FILE *f);
char LeOpcao();  //detalhar


void FechaArq(FILE *pfile) {
    fclose(pfile);
}

int ExisteArq() {
    FILE *pfile;
    int existe=1;
    if ((pfile = fopen(FILENAME, READ_WRITE_OPEN)) == NULL)
        existe=0;
    else
        FechaArq(pfile);
    return(existe);
}

FILE *AbreArq() {
    FILE *pfile;
    char modo[3];

    if(ExisteArq())
        strcpy(modo,READ_WRITE_OPEN);
    else
        strcpy(modo,READ_WRITE_CREATE);

    if ((pfile = fopen(FILENAME, modo)) == NULL) {
        printf("\nERRO criando e abrindo %s\n",FILENAME);
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

    GeraNome(empr->nome,4);
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
    printf("\n\n");
}

char LeOpcao() {
    char op;

    printf("\na-Incluir");
    printf("\nb-exibir");
    printf("\nc-sair");
    do {
        printf("\n\nOpcao: ");
        scanf("%c",&op);
        flush_in();
        if(op<97 || op>99)
            printf("Opcao invalida!");
    } while(op<97 || op>99);
    return(op);
}

int main(int argc, char** argv) {
    FILE *f;
    PESSOA e;
    char opcao;
    int i;

    f=AbreArq();
    do {
        opcao=LeOpcao();
        switch(opcao) {
            case 'a':   for(i=0;i<1;i++) {
                            LeRegistro(&e);
                            GravaRegistroOrdenadoNome(e,f);
                        }
                        ImprimeRegistros(f);
                        break;
            case 'b':   ImprimeRegistros(f); printf("Registros (%d)\n",CountRecords(f)); break;
        };
    } while(opcao!='c');
    FechaArq(f);
    return 0;
}

//2.	Escreva uma rotina que reúna dois arquivos de
//      registros de mesma estrutura em um terceiro arquivo.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define READ_WRITE_CREATE  "w+b"
#define READ_WRITE_OPEN    "r+b"

typedef struct {
    char nome[40];
    int idade;
} PESSOA;

void FechaArq(FILE *pfile);
int ExisteArq(char name[]);
FILE *AbreArq(char name[]);
void GravaRegistro(PESSOA *e, FILE *f);
void flush_in();
void ImprimeRegistro(PESSOA p);
void ImprimeRegistros(FILE *f);
void AdicionaRegistros(FILE *f, int codinicial, int quantos);
void ReuneArquivos(FILE *f1, FILE *f2, FILE *f3); //detalhar


void FechaArq(FILE *pfile) {
    fclose(pfile);
}

int ExisteArq(char name[]) {
    FILE *pfile;
    int existe=1;
    if ((pfile = fopen(name, READ_WRITE_OPEN)) == NULL)
        existe=0;
    else
        FechaArq(pfile);
    return(existe);
}

FILE *AbreArq(char name[]) {
    FILE *pfile;
    char modo[3];

    if(ExisteArq(name))
        strcpy(modo,READ_WRITE_OPEN);
    else
        strcpy(modo,READ_WRITE_CREATE);
    if ((pfile = fopen(name, modo)) == NULL) {
        printf("\nERRO criando e abrindo %s\n",name);
        exit (100);
    }

    return(pfile);
}

void sleep(time_t delay) {
    time_t time0, time1;
    time(&time0);
    do {
        time(&time1);
    } while( (time1-time0) < delay);
}

void GravaRegistro(PESSOA *e, FILE *f) {
        fseek(f,0,SEEK_END);
        fwrite(e,sizeof(PESSOA),1,f);
        fflush(f);
        //printf(".");
        //sleep(1);
}

void flush_in() {
   int ch;
   while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

void GeraRegistro(PESSOA *p, int c) {

    sprintf(p->nome,"NOME-(%d)",c);
    p->idade=c*18;
}

void ImprimeRegistro(PESSOA p) {
    printf("\nNOME: %s IDADE:%d",p.nome,p.idade);
}

void ImprimeRegistros(FILE *f) {
    PESSOA p;

    printf("\n\nRELATORIO-------------------------------------------------------");
    fseek(f,0,SEEK_SET);
    while(!feof(f)) {
        if( fread(&p,sizeof(PESSOA),1,f) > 0 )
        ImprimeRegistro(p);
    };
    printf("\n\n");
}

void AdicionaRegistros(FILE *f, int codinicial, int quantos) {
    int i;
    PESSOA p;
    for(i=0;i<quantos;i++) {
        GeraRegistro(&p,codinicial+i);
        GravaRegistro(&p,f);
        //printf("%d",i+1);
    }
}
//adiconar f1 arquivo e depois o f2 arquivo em f3
void ReuneArquivos(FILE *f1, FILE *f2, FILE *f3) {
    PESSOA p;

    fseek(f1,0,SEEK_SET);
    do {
        if( fread(&p,sizeof(PESSOA),1,f1) > 0 )
            GravaRegistro(&p,f3);
    } while( !feof(f1) );

    fseek(f2,0,SEEK_SET);
    do {
        if( fread(&p,sizeof(PESSOA),1,f2) > 0 )
            GravaRegistro(&p,f3);
    } while( !feof(f2) );
}

int main(int argc, char** argv) {
    FILE *fcli1, *fcli2, *fcli3;
    char *cli1="cliente_1", *cli2="cliente_2", *cli3="cliente_3";

    fcli1=AbreArq(cli1);
    fcli2=AbreArq(cli2);
    fcli3=AbreArq(cli3);

    printf("\n\n\nAdicionando registros em %s ",cli1);
    AdicionaRegistros(fcli1,1,2000);
    ImprimeRegistros(fcli1);
    getch();

    printf("\n\n\nAdicionando registros em %s ",cli2);
    AdicionaRegistros(fcli2,4000,50);
    ImprimeRegistros(fcli2);
    getch();

    ReuneArquivos(fcli1,fcli2,fcli3);
    printf("\n\n\nRegistros juntados em %s ",cli3);
    ImprimeRegistros(fcli3);

    FechaArq(fcli1);
    FechaArq(fcli2);
    FechaArq(fcli3);

    return 0;
}


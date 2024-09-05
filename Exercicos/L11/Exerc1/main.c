/*
a) criar e gravar dados num arquivo de registros;
b) exibir o conteúdo de um arquivo;
c) alterar dados de um registro de um arquivo;
d) incluir novos registros em um arquivo;
e) excluir um registro de um arquivo.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define READ_WRITE_CREATE  "w+b"
#define READ_WRITE_OPEN    "r+b"
#define FILENAME            "pessoa.dat"

typedef struct {
    char nome[40];
    int idade;
    int ativo;
} PESSOA;

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

void GravaRegistro(PESSOA *e, FILE *f) {
        fseek(f,0,SEEK_END);
        fwrite(e,sizeof(PESSOA),1,f);
        fflush(f);
}

void AlteraRegistro(FILE *f) {
    PESSOA p1, p2;
    int achou=0;

    printf("\nAlterar idade de quem ");
    LeNome(p1.nome);
    fseek(f,0,SEEK_SET);
    do {
        if( fread(&p2,sizeof(PESSOA),1,f) > 0 ) {
            if(strcmp(p1.nome,p2.nome)==0 && p2.ativo==1) {
                LeIdade(&p2.idade);
                fseek(f,-1*sizeof(PESSOA),SEEK_CUR);
                fwrite(&p2,sizeof(PESSOA),1,f);
                achou=1;
            }
        }
    } while( !feof(f) && !achou );
}


void ExcluiRegistro(FILE *f) {
    PESSOA p1, p2;
    int achou=0;

    printf("\nExcluir qual ");
    LeNome(p1.nome);
    fseek(f,0,SEEK_SET);
    do {
        if( fread(&p2,sizeof(PESSOA),1,f) > 0 ) {
            if(strcmp(p1.nome,p2.nome)==0 && p2.ativo==1) {
                p2.ativo=0;
                fseek(f,-1*sizeof(PESSOA),SEEK_CUR);
                fwrite(&p2,sizeof(PESSOA),1,f);
                achou=1;
            }
        }
    } while( !feof(f) && !achou );
}

void flush_in() {
   int ch;
   while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

void LeNome(char nome[]) {
    printf("\nNOME: ");
    scanf("%s", nome);
    flush_in();
}

void LeIdade(int *idade) {
    do {
        printf("\nIDADE: ");
        scanf("%d", idade);
        flush_in();
        if (*idade < 1) {
            printf("Idade deve estar acima de ZERO!");
        }
    } while (*idade < 1);
}

PESSOA *LeRegistro() {
    PESSOA *empr = (PESSOA*) malloc(sizeof (PESSOA));

    if (empr != NULL) {
        LeNome(empr->nome);
        LeIdade(&empr->idade);
        empr->ativo=1;
    }
    return (empr);
}

void ImprimeRegistro(PESSOA p) {
    if(p.ativo)
        printf("\nNOME: %s IDADE:%d",p.nome,p.idade);
}

void ImprimeRegistros(FILE *f) {
    PESSOA p;

    printf("\n\nRELATORIO");
    fseek(f,0,SEEK_SET);
    do {
        if( fread(&p,sizeof(PESSOA),1,f) > 0 )
            ImprimeRegistro(p);
    } while( !feof(f) );
    printf("\n\n");
}

char LeOpcao() {
    char op;

    printf("\na-criar e gravar dados num arquivo de registros");
    printf("\nb-exibir o conteúdo de um arquivo");
    printf("\nc-alterar dados de um registro de um arquivo");
    printf("\nd-incluir novos registros em um arquivo");
    printf("\ne-excluir um registro de um arquivo");
    printf("\nf-sair");
    do {
        printf("\n\nOpcao: ");
        scanf("%c",&op);
        flush_in();
        if(op<97 || op>102)
            printf("Opcao invalida!");
    } while(op<97 || op>102);
}

int main(int argc, char** argv) {
    FILE *f;
    PESSOA *e;
    char opcao;

    f=AbreArq();
    do {
        opcao=LeOpcao();
        switch(opcao) {
            case 'a':   break;
            case 'b':   ImprimeRegistros(f); break;
            case 'c':   AlteraRegistro(f); break;
            case 'd':   e=LeRegistro(); GravaRegistro(e,f); free(e); break;
            case 'e':   ExcluiRegistro(f); break;
        };
    } while(opcao!='f');

    FechaArq(f);
    return 0;
}


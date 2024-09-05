#include <stdlib.h>
#include <stdio.h>

//CODICO COM INTUITO DE APRENDER STRUC


struct Ficha_aluno
{
    char nome[40];
    int numero;
    float nota;
}; // definição da str

struct Ficha_aluno aluno;

int main(){
    printf("nome do aluno: \n");
    fgets(aluno.nome,40,stdin);

    printf("nota do aluno\n");
    scanf("%f",&aluno.nota);

    printf("Numero do aluno\n");
    scanf("%d",&aluno.numero);

    printf("\n\n\n nome: %s",aluno.nome);
    printf("\nNumero: %d",aluno.numero);
    printf("\n Nota : %f",aluno.nota);






    return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

void gerar_nome_principal(char *ptr_principal)
{
    srand(time(NULL));

    char nome_1[20] = {"Jose"};
    char nome_2[20] = {"Max"};
    char nome_3[20] = {"Leo"};

    int a = rand() % 3;

    if (a == 0)
    {
        strcpy(ptr_principal, nome_1);
    }
    else if (a == 1)
    {
        strcpy(ptr_principal, nome_2);
    }
    else if (a == 2)
    {
        strcpy(ptr_principal, nome_3);
    }
}

void gerar_sobrenome(char *ptr_sobrenome)
{
    srand(time(NULL));
    char nome_1[20] = {"Gabriel"};
    char nome_2[20] = {"Ogawa"};
    char nome_3[20] = {"Delboni"};
    int a = rand() % 2;

    if (a == 0)
    {
        strcpy(ptr_sobrenome, nome_1);
    }
    else if (a == 1)
    {
        strcpy(ptr_sobrenome, nome_2);
    }
    else if (a == 2)
    {
        strcpy(ptr_sobrenome, nome_3);
    }
}

void gerar_nome_valido(char *ptr_nome)
{
    char nome_principal[11];
    char nome_sobrenome[11];
    char finalizador[3]= "\0";

    gerar_nome_principal(nome_principal);
    gerar_sobrenome(nome_sobrenome);

    strcpy(ptr_nome, nome_principal);
    strcat(ptr_nome, nome_sobrenome);
    strcat(ptr_nome,finalizador);
}

int main()
{
    char nome[11];

    gerar_nome_valido(nome);

    printf("%s",nome);
    return 0;
}
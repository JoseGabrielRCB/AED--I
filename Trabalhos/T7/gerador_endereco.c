#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>


int conversor_int(char a)
{
    // Recebe um argumento(numero) CHAR e converte  para um numero do tipo INT.
    int num;
    char val[10] = "0123456789";
    for (int i = 0; i < 10; i++)
    {
        if (a == val[i]) // verifica a qual nuemero de 1 a 9 ele pertence.
        {
            num = i; // insere o numero condizente.
            i = 10;  // finaliza o for.
        }
    }
    return (num);
}

char conversor_char(int a)
{

    // recebe um argumento do tipo INT e converte para um CHAR
    char aux[11] = "0123456789";
    char valor_char;
    for (int i = 0; i < 10; i++)
    {
        if (a == i) // verifica a qual nuemero de 1 a 9 ele pertence.
        {
            valor_char = aux[i]; // insere o numero condizente.
            i = 10;              // finaliza o for.
        }
    }

    return (valor_char);
}

void gerar_rua(char *ptr_rua)
{
    srand(time(NULL));
    int a = 0;
    char rua_1[20] = "São pedro\0";
    char rua_2[20] = "Brigadeiro\0";
    char rua_3[20] = "Antonio Emilio\0";

    a = rand() % 3;

    if (a == 2)
    {
        strcpy(ptr_rua, rua_1);
    }
    else if (a == 1)
    {
        strcpy(ptr_rua, rua_2);
    }
    else if (a == 0)
    {
        strcpy(ptr_rua, rua_3);
    }
}

void gerar_bairro(char *ptr_bairro)
{
    srand(time(NULL));
    char bairro_1[20] = "Santo Antonio\0";
    char bairro_2[20] = "Centro\0";
    char bairro_3[20] = "Santa catarina\0";

    int a = rand() % 3;

    if (a == 2)
    {
        strcpy(ptr_bairro, bairro_1);
    }
    else if (a == 1)
    {
        strcpy(ptr_bairro, bairro_2);
    }
    else if (a == 0)
    {
        strcpy(ptr_bairro, bairro_3);
    }
}

void gerar_estado(char *ptr_estado)
{
    srand(time(NULL));
    char estado_1[20] = "Mato Grosso\0";
    char estado_2[20] = "Mato Grosso do Sul\0";
    char estado_3[20] = "Ceara\0";

    int a = rand() % 3;

    if (a == 2)
    {
        strcpy(ptr_estado, estado_1);
    }
    else if (a == 1)
    {
        strcpy(ptr_estado, estado_2);
    }
    else if (a == 0)
    {
        strcpy(ptr_estado, estado_3);
    }
}

void gerar_cidade(char *ptr_cidade)
{
    srand(time(NULL));
    char cidade_1[20] = "Campo grande\0";
    char cidade_2[20] = "Cuiabá\0";
    char cidade_3[20] = "Fortaleza\0";

    int a = rand() % 3;

    if (a == 2)
    {
        strcpy(ptr_cidade, cidade_1);
    }
    else if (a == 1)
    {
        strcpy(ptr_cidade, cidade_2);
    }
    else if (a == 0)
    {
        strcpy(ptr_cidade, cidade_3);
    }
}

void gerar_cep_valido(char *ptr_cep)
{
    srand(time(NULL));
    int cep_int[10];

    for (int i = 0; i < 10; i++)
    {
        cep_int[i] = rand() % 10;
    }

    for (int i = 0; i < 10; i++)
    {
        if (i == 2)
        {
            ptr_cep[2] = 46;
        }
        if (i == 6)
        {
            ptr_cep[6] = 45;
        }
        else
        {

            ptr_cep[i] = conversor_char(cep_int[i]);
        }
    }
}

int gera_numero_casa()
{
    srand(time(NULL));
    int a = rand() % 727;
    return (a);
}
// int casa,char rua,char bairro,char estado,char cidade,char cep
void gerar_endereço_valido(int *ptr_numero_casa, char *ptr_rua, char *ptr_bairro, char *ptr_estado, char *ptr_cidade, char *ptr_cep)
{
    int a = gera_numero_casa();
    *ptr_numero_casa = a;
    gerar_rua(ptr_rua);
    gerar_bairro(ptr_bairro);
    gerar_estado(ptr_estado);
    gerar_cidade(ptr_cidade);
    gerar_cep_valido(ptr_cep);
}

int main()
{
    int numero_casa=2;
    char rua[20];
    char bairro[20];
    char estado[20];
    char cidade[20];
    char cep[11];

    gerar_endereço_valido(&numero_casa, rua, bairro, estado, cidade, cep);

    printf("RUA: %s\n", rua);
    printf("BAIRRO: %s\n", bairro);
    printf("estado: %s\n", estado);
    printf("cidade: %s\n", cidade);
    printf("cep: %s\n", cep);
    printf("NUMERO CASA:%d\n", numero_casa);

    return 0;
}

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

int DDD()
{
    // Distrito Federal (61)
    // Goiás (62 e 64)
    // Mato Grosso (65 e 66)
    // Mato Grosso do Sul (67)

    srand(time(NULL));

    int a = rand() % 6;
    int ddd[6] = {61, 62, 64, 65, 66, 67};

    return (ddd[a]);
}

char gerar_telefone(char *telefone_char)
{
    srand(time(NULL));
    int telefone_int[11]; // sem -
    int ddd = DDD();
    // inserir o DDD nos dois primeiros valores
    telefone_int[0] = ddd / 10;
    ddd = ddd - telefone_int[0] * 10;
    telefone_int[1] = ddd;

    for (int i = 2; i < 11; i++)
    {
        telefone_int[i] = rand() % 9;
    }

    for (int i = 0; i < 12; i++)
    {
        if (i == 8)
        {
            telefone_char[8] = 45; // valor de - na tabela asc
        }
        else
        {
            telefone_char[i] = conversor_char(telefone_int[i]);
        }
    }
}



int main()
{

    char telefone[14];
    gerar_telefone(telefone);

    printf("telefone MOvel: \n");

    for (int i = 0; i < 12; i++)
    {
        printf("%c", telefone[i]);
    }

    return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void flush_in()
{
    int ch;

    while ((ch = fgetc(stdin)) != EOF && ch != '\n')
    {
    }
}

int main()
{
    // matrix para assentos
    int v[12][10];
    int b = 0;
    int i = 0;
    int d = 0;

    char local[999];
    char chegada[999];
    int cont = 0;
    int cont2 = 0;
    char resposta[999];
    // necessario colocar a mais do \0
    char comp0[10] = "sim";
    char comp1[10] = "nao";
    // inserir assentos vazios na matrix
    for (int i = 0; i < 11; i++)
    {
        for (int b = 0; b < 9; b++)
        {
            v[i][b] = 1;
        }
    }
    // menu do usuario
    do
    {
        cont = 0;
        b = 0;
        i = 0;

        printf("Qual o locar de origem?\n");
        gets(local);
        printf("Qual o numero do voo?\n");
        scanf("%d", &b);
        printf("Qual o destino?\n");
        flush_in();
        gets(chegada);
        // validacao do assento do voo
        for (int i = 0; i < 11; i++)
        {
            if (v[b][i] == 1)
            {
                cont++;
            }
        }
        // finalizacao e saida
        if (cont >= 1)
        {
            do
            {
                printf("ha assentos dispoiniveis neste voo!\nGostaria de reservar sua passagem?\n");
                gets(resposta);
                i = strcmp(comp0, resposta);
                d = strcmp(comp1, resposta);
                if (d == 0)
                {
                    printf("Voce nao reservou nenhuma passagem\n");
                }
                if (i == 0)
                {
                    printf("voce reservou a passagem\n");
                    for (int a = 0; a < 11; a++)
                    {
                        if (v[b][a] == 1)
                        {
                            v[b][a] = 0;
                            cont2 = a + 1;
                            a = 12;
                        }
                    }
                    printf("\nlocal de saida: %s\ndestino final : %s\n numero do voo: %d\n numero do assento: %d\n;", local, chegada, b, cont2);
                }
                if (i != 0 && d != 0)
                {
                    printf("insira sim ou nao\n");
                }
            } while (d != 0 && i != 0);
        }
        else
        {
            printf("Nao temos assentos disponiveis nesse voo");
        }

        // reinicio para o menu principal
        do
        {
            cont = 0;
            printf("Gostaria de reservar mais passagens?\n");

            gets(resposta);
            i = strcmp(comp0, resposta);
            d = strcmp(comp1, resposta);
            if (d == 0)
            {
                printf("fim do sistema\n");
            }
            if (i == 0)
            {
                cont++;
            }
            if (i != 0 && d != 0)
            {
                printf("insira sim ou nao\n");
            }
        } while (d != 0 && i != 0);

    } while (cont >= 1);
}

    /* verificar matrix
        for (int i = 0; i < 11; i++)
        {
            for (int b = 0; b < 9; b++)
            {
                printf("valor da matrix %d : %d\n",i, v[i][b]);
            }
        }
        return 0 ;
        */

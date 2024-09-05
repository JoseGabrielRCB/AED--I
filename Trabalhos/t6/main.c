#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "myList.h"

int quantDig(int n)
{
    int tam = 0;
    while (n != 0)
    {
        tam++;
        n /= 10;
    }
    return tam;
}

// O sistema não está reconhecendo a função pow(), então essa função faz o mesmo calculo
// função de potencia
int expo(int n1, int n2)
{
    int num = n1;
    if (n2 == 0)
    {
        return 1;
    }
    else
    {
        for (int i = 0; i < n2 - 1; i++)
        {
            num = num * n1;
        }
        return num;
    }
}

// acha os numeros narcisistas dentro da sequencia solicitada
int numNarc(int num)
{
    int tam, total, val;
    int n = 0;
    for (int i = 10; i <= num; i++) // varre ate a quantidade de nuemros solicitados
    {
        total = 0;
        tam = quantDig(i);
        for (int j = 0; j < tam; j++) // verifica se o nuemro é narcisita
        {
            val = (int)(i / expo(10, j)) % 10; // N = d1^b + d2^b + d3^b + ... + dn^b
            total += expo(val, tam);
        }
        if (total == i) // caso total == i, o numero é nercisista
        {
            insereOrdem(i); // insere o numero na ordem
            n++;            // conta quantidade de numeros narcisistas
        }
    }
    return n; //retorna quantidade de numeros narcistas
}

//averigua valor de entrada do usario
int entVal(char val[])
{
    int cont = 0;
    int tam = strlen(val);
    for (int i = 0; i < tam; i++)
    {
        if (isdigit(val[i]) != 0) //varifica se é digito
        {
            cont++;
        }
    }
    if (cont == tam) //caso seja um valor retorna 1(TRUE)
    {
        return 1;
    }
    else //caso n seja retorna 0 (FALSE)
    {
        return 0;
    }
}
// mensagem de erro 
void err(char text[])
{
    printf("[ERRO] %s\n\n", text);
}

int main()
{
    char escolha[2];
    int conf = -1;
    int cont = 0;
    while (conf != 0)
    {
        printf("1 - Armazenar na estrutura os números narcisistas entre 10 e N.\n"); //menu de escolha do usuario
        printf("2 - Mostre os números narcisistas armazenados na estrutura.\n");
        printf("3 - Excluir um número narcisista da estrutura.\n");
        printf("0 - Encerrar o sistema.\n");
        scanf("%s", escolha); //entrada de valores do usuario
        if (entVal(escolha) == 1)
        {
            conf = atoi(escolha); // coverte escolha em um int caso seja uma letra
        }
        else
        {
            conf = -1;
        }
        if (conf == 1)
        {
            int num;
            char val[10];
            system("clear");
            printf("Digite o valor de N:\n"); 
            scanf("%s", val); //entrada do valor do usario, para ver ate qual numero sera analisado
            system("clear");
            if (entVal(val) == 1)
            {
                num = atoi(val);
                if (num > 10 && num <= 1000000) //verifica se o numero esta entre o intervalo solicitado
                {
                    if (cont != 0)
                    {
                        esvazia(); //limpa o struct
                        system("clear");
                        cont = 0;
                    }
                    inicializa(); //inicializa o struct
                    cont = numNarc(num); //insere o numero na ordem
                    if (cont != 0)
                    {
                        printf("Valor(es) inserido(s) com sucesso.\n\n"); //confirma que o valor foi inserido no struct
                    }
                    else
                    {
                        printf("[ERRO] Nao houve nenhum numero narcisista entre 10 a %d\n\n", num); //caso n haja valores narcisistas no intervalo
                    }
                }
                else
                {
                    err("Valor inserido invalido! Digite um numero entre 11 a 1000000"); //caso o valor esteja fora intervalo
                }
            }
            else
            {
                err("Entrada de valor invalida!");  //caso o valor da entrada seja invalido
            }
        }
        else if (conf == 2)
        {
            system("clear");
            if (cont != 0)
            {
                imprime(); //imprime os numeros narcisistas na estrutura
                printf("\n");
            }
            else
            {
                err("Nao ha nenhum numero inserido no sistema."); //caso n tenha numeros salvos na estrutura
            }
        }
        else if (conf == 3)
        {
            system("clear");
            if (cont != 0)
            {
                char ent[10];
                int val;
                printf("Digite o numero que deseja excluir:\n");
                scanf("%s", ent); //entrada do usuario
                system("clear");
                if (entVal(ent) == 1) //varifica valor de entrada e valido
                {
                    val = atoi(ent);
                    if (busca(val) == 1) //verifica se o numero esta na estrutura
                    {
                        retira(val); //exclui numero da estrutura
                        printf("Numero excluido com sucesso.\n\n");
                        cont--; //reduz no contador 
                    }
                    else
                    {
                        printf("[ERRO] O numero \"%d\" nao esta presente no sistema.\n\n", val); //caso não exista o numero solicitado
                    }
                }
                else
                {
                    err("Valor inserido invalido!");
                }
            }
            else
            {
                err("Nao ha nenhum numero inserido no sistema."); //caso não tenha valores na estrutura
            }
        }
        else if (conf < 0 || conf > 3)
        {
            system("clear");
            err("Valor inserido invalido"); //caso o valor de menu seja invalido
        }
        else
        {
            esvazia();// limpa estrutura
        }
    }
    return 0;
}
/*  Fazer um programa que receba via argumento dois conjuntos de numeros inteiros onde
    cada conjunto tem 5 numeros. O primeiro conjunto deve ser armazenado no vetor A e o
    segundo conjunto no vetor B. Construa um vetor C com os numeros repetidos entre
    A e B. O numero repetido deve aparecer uma unica vez no vetor C. Informe os repetidos.

    Ex. app 1 2 3 4 5 4 20 2 1 2

        SAIDA_1 = Os numeros do conjunto A sao: 1 2 3 4 5
        SAIDA_2 = Os numeros do conjunto B sao: 4 20 2 1 2
        SAIDA_3 = O numero 1 eh repetido!
        SAIDA_3 = O numero 2 eh repetido!
        SAIDA_3 = O numero 4 eh repetido!


    Ex. app 6 3 2 5 3 9 30 66 3 70

        SAIDA_1 = Os numeros do conjunto A sao: 6 3 2 5 3
        SAIDA_2 = Os numeros do conjunto B sao: 9 30 66 3 70
        SAIDA_3 = O numero 3 eh repetido!


*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int A[5];
    int B[5];
    int C[5];
    int i, j, k;
    int count = 0;

    // Verifica se foram fornecidos argumentos suficientes
    if (argc < 11)
    {
        printf("Argumentos insuficientes!\n");
        return 1;
    }

    // Lê os conjuntos A e B dos argumentos
    for (i = 1; i <= 5; i++)
    {
        A[i - 1] = atoi(argv[i]);
        B[i - 1] = atoi(argv[i + 5]);
    }

    printf("SAIDA_1 = Os numeros do conjunto A sao:");
    for (i = 0; i < 5; i++)
    {
        printf(" %d", A[i]);
    }
    printf("\n");

    printf("SAIDA_2 = Os numeros do conjunto B sao:");
    for (i = 0; i < 5; i++)
    {
        printf(" %d", B[i]);
    }
    printf("\n");

    // Constrói o vetor C com os números repetidos
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (A[i] == B[j])
            {
                // Verifica se o número já está em C
                int duplicate = 0;
                for (k = 0; k < count; k++)
                {
                    if (C[k] == A[i])
                    {
                        duplicate = 1;
                        k = count;
                    }
                }
                // Se não estiver, adiciona a C
                if (!duplicate)
                {
                    C[count] = A[i];
                    count++;
                }
                break;
            }
        }
    }

    // Informa os números repetidos
    for (i = 0; i < count; i++)
    {
        printf("SAIDA_3 = O numero %d eh repetido!\n", C[i]);
    }

    return 0;
}
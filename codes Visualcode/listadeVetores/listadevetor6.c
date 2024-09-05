#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//. Encontrar o maior elemento e sua respectiva posição, de um vetor A com 1000 elementos. Não existem
// elementos repetidos.

int main()
{
    // vetor solicitado.
    // teste feito com 5 valores, se funciona para este vai para outros tambem.
    int num[5] = {3, 55, 6, 88, 45};
    int maior = -9999;
    int menor = 9999;
    printf("Lista de vetores item 6\n");
    // analisar as casas do vetor
    for (int i = 0; i < 5; i++)
    {
        if (num[i] > maior)
        {
            maior = num[i];
        }
        if (num[i] < menor)
        {
            menor = num[i];
        }
    }
    // saidas
    printf("o maior valor e: %d", maior);
    printf("o menor numero e : %d", menor);

    return 0;
}
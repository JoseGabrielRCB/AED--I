#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    int num[5];
    int maior = -99999;
    int menor = 99999;

    printf("Analise o menor e maior numero da sequencia");

    for (int i = 1; i < 5; i++)
    {
        printf("\nInforme o numero da sequencia: \n");
        scanf("%d", &num[i]);
    }
    for (int i = 1; i < 5; i++)
    {
        if (num[i] < menor)
        {
            menor = num[i];
        }
        if (num[i] > maior)
        {
            maior = num[i];
        }
    }
    printf("\no maior numero e %d", maior);
    printf("\no menor valor e %d", menor);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*5. Dados três conjuntos de números, de tamanho N, calcular a média entre suas médias*/

int main()
{
   float lista1[5];
   float lista2[5];
   float lista3[5];
   float media1 = 0;
   float media2 = 0;
   float media3 = 0;

    printf("item 5 da lista de vetores\n");
    printf("Calcular media da media das lista solicitadas\n");
    // Incio lista1
    for (int i = 0; i < 5; i++)
    {
        printf("insira o valor para primera lista:\n");
        scanf("%f", &lista1[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        media1 += lista1[i];
    }
    media1 = media1 / 5;
    // fim lista1

    // Incio lista2
    for (int i = 0; i < 5; i++)
    {
        printf("insira o valor para segunda lista:\n");
        scanf("%f", &lista2[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        media2 += lista2[i];
    }
    media2 = media2 / 5;
    // fim lista2

    // Incio lista3
    for (int i = 0; i < 5; i++)
    {
        printf("insira o valor para terceira lista:\n");
        scanf("%f", &lista3[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        media3 += lista3[i];
    }
    media3 = media3 / 5;
    // fim lista3

    //calculo geral
    media1 = (media1 + media2 + media3)/3;
    printf("o calculo da media das listas vale %.2f",media1);

    return 0;
}

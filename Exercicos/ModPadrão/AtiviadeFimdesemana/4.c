#include <stdlib.h>
#include <stdio.h>

void ver_par(int *p1, int *p2)
{
    if (*p1 > *p2)
    {
        printf("Insira primeiro o maior");
    }
    else
    {
        for (int i = *p1; i < *p2 + 1; i++)
        {
            if (i % 2 == 0)
            {
                printf("Valor par : %d\n", i);
            }
        }
    }
}

int main()
{
    int num1, num2;
    printf("item 4 lista fim se semana\n");
    printf("\nEscreva dois numeros(menor/maior)e veja os pares entre eles\n");
    scanf("%d %d", &num1, &num2);
    ver_par(&num1,&num2);

    return 0;
}
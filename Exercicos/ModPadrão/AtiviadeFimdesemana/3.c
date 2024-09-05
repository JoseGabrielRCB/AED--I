#include <stdlib.h>
#include <stdio.h>

void sequencia(int *p1, int *p2)
{
    for (int i = *p1; i < *p2+1; i++)
    {
        printf("valor: %d\n", i);
    }
}

int main()
{
    int num1, num2;
    printf("Item 3 lista fim de semana\n");
    printf("\nInsira os valores de inicio e fim da sequencia\n");
    scanf("%d", &num1);
    scanf("%d", &num2);
    sequencia(&num1, &num2);

    return 0;
}
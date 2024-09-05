#include <stdio.h>
#include <stdlib.h>

void Finacci(int limite)
{

    int a = 1;
    int b = 0;
    int c = 1; // 1 1 2 3 5 8

    printf("%d ", a);
    printf("%d ", a);

    for (int i = 0; i < limite-2; i++)
    {
        b = a;
        a = c;
        c = a + b;
        printf("%d ", c);
    }
}

int main()
{
    int a = 0;
    while (a <= 0)
    {
        printf("INSIRA O VALOR PARA SEQUANCIA\n");
        scanf("%d",&a);
        if (a <= 0)
        {
            printf("INSIRA UM NUMERO MAIOR QUE 0");
        }
    }
    Finacci(a);
}

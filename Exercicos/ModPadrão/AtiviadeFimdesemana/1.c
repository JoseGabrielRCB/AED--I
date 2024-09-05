#include <stdlib.h>
#include <stdio.h>

// varificar paridade
void par(int *p)
{
    if (*p % 2 == 0)
    {

        printf("par\n");
    }
    else
    {
        printf("impar\n");
    }
}

int main()
{
    int num;
    printf("Item 1 lista do fimd e semana\n");
    printf("\n Verifique se o numeor e par\n");
    printf("Informe o nuemro a ser analisado\n");
    scanf("%d", &num);
    // executar funcao
    par(&num);
    return 0;
}
#include <stdlib.h>
#include <stdio.h>

void nota()
{
    int n;
    scanf("%d", &n);
    if (n >= 7)
    {
        printf("APROVADO \n");
    }
    else
    {
        printf("REPROVADO\n");
    }
}

int main()
{
    printf("Vaja se o aluno foi reprovado ou aprovado:\n");
    nota();
    return 0;
}
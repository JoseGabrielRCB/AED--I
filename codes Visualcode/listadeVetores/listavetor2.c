#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    int listnum[5];
    // valores de chutes iniciais.
    int maior = 999;
    int menor = 9999;

    printf("lista vetor item 3\n ");
    printf("Descubra um numero maior da sequancia(imbutido 999)\n");
    // ultimo argumento como 999 , solicitado pelo item.
    listnum[4] = 999;
    // entrada de elementos no sistema.
    for (int i = 1; i < 4; i++)
    {
        printf("Informe o numero:\n");
        scanf("%d", &listnum[i]);
        // avaliar maior menor numero.
        if (listnum[i] > listnum[4])
        {
            maior = listnum[i];
        }
        if (listnum[i] < menor)
        {
            menor = listnum[i];
        }
    }
    //saidas correspondentes das analises
    printf("menor: %d\n", menor);
    printf("maior : %d", maior);

    return 0;
}
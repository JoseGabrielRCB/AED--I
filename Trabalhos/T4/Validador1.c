#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int validador(char bacteria[])
{
    char confirmar[10] = {'a', 'u', 'c', 'g'};
    int i = 0;
    int b = 0;
    int cont = 0;
    int a = strlen(bacteria);
    for (i = 0; i < a; i++)
    {
        for (b = 0; b < 4; b++)
        {
            if (bacteria[i] != confirmar[b])
            {
                cont = 1;// errado
            }
        }
    }

    return (cont);
}
int main()
{
    int a;
    char bac[20];
    printf("coloque a bacteria : \n");
    scanf("%s",bac);
    a = validador(bac);
    printf("\n%d\n",a);

    return 0;
}
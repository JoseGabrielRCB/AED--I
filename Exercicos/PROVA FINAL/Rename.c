#include <stdio.h>
#include <stdlib.h>


int meia_vida(float *vida)
{
    int cont = 0;
    while (*vida >= 0.5)
    {
        *vida = *vida / 2;
        cont++;
    }

    return (cont);
}
float leitura()
{
    float a = 0;
    while (a <= 0)
    {
        printf("INSIRA O VALOR DESEJADO\n");
        scanf("%f", &a);
        if (a <= 0)
        {
            printf("VALOR INSERIDO MENOR OU IGUAL A 0\n");
            system("pause");
            system("cls");
        }
    }
    return (a);
}

int main()
{
    float a = leitura();
    float b = a;
    int tempo = meia_vida(&a);

    printf("VALOR INICIAL: %.0f\n", b);
    printf("VALOR FINAL:%.1f\n", a);
    printf("TEMPO TOTAL:%d", tempo);

    return 0;
}
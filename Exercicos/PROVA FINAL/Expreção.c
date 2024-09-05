#include <stdio.h>
#include <stdlib.h>

void Exprecao(float *a)
{
    float numerador = 1;
    float denominador = 225;
    float decrementador = 27;
    *a = numerador / denominador;

    for (int i = 0; i < 999; i++)
    {
        if (decrementador == 1)
        {
            i = 1000;
        }
        else
        {
            decrementador -= 2;
            denominador -= decrementador;
            numerador = numerador * 2 * -1;
            *a += numerador / denominador;
        }
    }
}

int main()
{
    float resultado;
    Exprecao(&resultado);
    printf("REsultado %.2f", resultado);

    return 0;
}
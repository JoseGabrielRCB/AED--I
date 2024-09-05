#include <stdio.h>
#include <stdlib.h>

float ler_massa()
{
    int massa;
    scanf("%d", &massa);
    return (massa);
}

int tempo_ate_meio(float *a)
{
    int tempo = 0;
    if (*a > 0.5)
    {

        do
        {
            *a = *a / 2;
            tempo += 50;
        } while (*a >= 0.5);

        return (tempo);
    }
    else
    {
        return tempo;
    }
}

void escrever_resposta(float massa_incial, int tempo, float massa_final)
{
    printf("tempo %d\n", tempo);
    printf("massa incial %.2f\n", massa_incial);
    printf("massa final %.2f\n", massa_final);
}

int main()
{
    float massa = 0;
    int tempo = 0;
    float massa_incial = 0;
    printf("Medir o tempo\n");
    printf("INFORME A  MASSA DO MATERIAL\n");

    massa = ler_massa();
    massa_incial = massa;

    tempo = tempo_ate_meio(&massa);
    escrever_resposta(massa_incial, tempo, massa);

    return 0;
}
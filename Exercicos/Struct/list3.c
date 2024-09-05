#include <stdlib.h>
#include <stdio.h>

// 3. Tendo dois horários (horas, minutos e segundos) em registro:
// a. Ler as informações.
// b. Obter a diferença entre os dois horários.
// c. Mostrar a diferença entre os dois horários.

typedef struct tempo
{
    float hora;
    float minuto;
    float segundo;

} tempo[2];

// ler valor decimar
float ler_decimal()
{
    float decimal = 0;
    scanf("%f", &decimal);
    return (decimal);
}

float diferança()
{
}

float hora_segundo(float hora)
{
    float conversao;
    conversao = hora * 60 * 60;
    return (conversao);
}

float minuto_segundo(float minuto)
{
    float conversao;
    conversao = minuto * 60;
    return (conversao);
}

int main()
{
    tempo lista;
    float diferenca[3];

    // entrada de dados
    for (int i = 0; i < 2; i++)
    {
        printf("Hora:\n");
        lista[i].hora = ler_decimal();
        printf("Minuto:\n");
        lista[i].minuto = ler_decimal();
        printf("Segundo:\n");
        lista[i].minuto = ler_decimal();
        diferenca[i] = hora_segundo(lista[i].hora) + minuto_segundo(lista[i].minuto) + lista[i].segundo;
    }

    // calculo da diferença

    diferenca[2] = diferenca[0] - diferenca[1];
    if (diferenca[2] < -1)
    {
        diferenca[2] = diferenca[2] * -1;
    }

    printf("\nA diferenca foi de : %.2f", diferenca[2]);

    return 0;
}

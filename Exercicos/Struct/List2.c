#include <stdlib.h>
#include <stdio.h>


// 2. Tendo horas, minutos e segundos em um registro:
// a. Ler as informações.
// b. Mostrar as informações.
// c. Transformar as informações em segundos.
// d. Mostrar as informações em segundos

typedef struct tempo
{
    int horas;
    int minutos;
    int segundos;

} tempo;

int ler_int()
{
    int inteiro;
    scanf("%d", &inteiro);
    return (inteiro);
}
// converter hora em segundo
int hora_segundo(int hora)
{
    int conversao;
    conversao = hora * 60 * 60;
    return (conversao);
}
// converter minuto em segundo
int minuto_segundo(int minuto)
{
    int conversao;
    conversao = minuto * 60;
    return (conversao);
}

int main()
{
    tempo tempo_gasto;
    int soma = 0;
    // entrada de dados
    printf("Hora:\n");
    tempo_gasto.horas = ler_int();
    printf("Minutos:\n");
    tempo_gasto.minutos = ler_int();
    printf("segundos:\n");
    tempo_gasto.segundos = ler_int();
    // print das saidas
    printf("Hora:%d\n", tempo_gasto.horas);
    printf("Minuto:%d\n", tempo_gasto.minutos);
    printf("segundo:%d\n", tempo_gasto.segundos);

    // conversão em segundos
    soma += hora_segundo(tempo_gasto.horas) + hora_segundo(tempo_gasto.minutos) + tempo_gasto.segundos;

    printf("Conversao em segundos: %d", soma);

    return 0;
}

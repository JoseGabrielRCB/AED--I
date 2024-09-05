/*  Fazer um programa que receba via argumento 5 numeros inteiros e guarde-os em um vetor A.
    Depois construa um vetor B onde cada valor em B � o fatorial de cada n�mero de A.
    Informe o vetor B.

    Ex. app 4 8 -8 0 6

	SAIDA_1 = Para o numero 4 o fatorial vale: 24
	SAIDA_1 = Para o numero 8 o fatorial vale: 40320
	SAIDA_2 = Nao existe fatorial para o numero: -8
	SAIDA_1 = Para o numero 0 o fatorial vale: 1
	SAIDA_1 = Para o numero 6 o fatorial vale: 720

*/
#include <stdio.h>
#include <stdlib.h>

#define SAIDA_1 "\nSAIDA_1 = Para o numero %d o fatorial vale: %d"
#define SAIDA_2 "\nSAIDA_2 = Nao existe fatorial para o numero: %d"
#define SAIDA_3 "\nSAIDA_3 = A quantidade invalida de argumentos!"

int main(int argc, char *argv[]) {
    int i, j, a[5];
    int b[5] = {1, 1, 1, 1, 1};
    if(argc == 6) { //verifica a quantidade de argumentos inseridos
        //insere os valores inseridos no vetor
        for (i = 1; i <= 5; i++)
        {
            a[i - 1] = atoi(argv[i]);
        }

        //envia os valores no vetor de a para o vetor b com seus valores em fatorial
        for (i = 0; i < 5; i++)
        {
            for (j = 1; j <= a[i]; j++) // fatoriza os numeros
            {
                b[i] *= j;
            }
        }

        //define se o valor do vetor a é um valor válido para demonstrar seu fatorial
        for (i = 0; i < 5; i++)
        {
            if(a[i] >= 0){
                printf(SAIDA_1, a[i], b[i]);
            } else {
                printf(SAIDA_2, a[i]);
            }
        }
    } else {
        printf(SAIDA_3);//ocorre caso a quantidade de argumentos desejada seja invalida
    }
    return 0;
}
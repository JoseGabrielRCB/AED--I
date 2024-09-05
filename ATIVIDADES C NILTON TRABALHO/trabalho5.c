#include <stdio.h>
#include <stdlib.h>

//Construa um programa para resolver o exercicio 8 da lista 3.1 (parte 1).
//O programa deve receber a entrada pela linha de comando.

//Exemplo de execucao: prog 478.90

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//sa�das permitidas e que NAO PODEM ser modificadas
#define SAIDA_1 "\nSAIDA_1 = O salario antes do reajuste: R$ %.2f"
#define SAIDA_2 "\nSAIDA_2 = O salario reajustado ficou: R$ %.2f"
#define SAIDA_3 "\nSAIDA_3 = O percentual de reajuste foi de: %d%%"
#define SAIDA_4 "\nSAIDA_4 = O salario deve estar entre R$ 0,00 e R$ 1.000,00"

int main(int argc, char *argv[]) {
    int percentual;
    if( argc == 2 ) {
        float salario = atoi(argv[1]);
        if((salario > 0) && (salario < 1000)){
            printf(SAIDA_1, salario);
            if(salario <= 300){
                percentual = 35;
                salario += salario * 0.35;
                printf(SAIDA_2, salario);
                printf(SAIDA_3, percentual);
            } else {
                percentual = 15;
                salario += salario * 0.15;
                printf(SAIDA_2, salario);
                printf(SAIDA_3, percentual);
            }
        } else {
            printf(SAIDA_4);
        }
    }
    return 0;
}
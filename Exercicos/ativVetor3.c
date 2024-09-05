/*  Dados dois conjuntos A e B de M e N posi  es, respectivamente, sendo N<=M,
    informar se B est  contido em A. M e N devem estar entre 1 e 10. Todos os valores
    devem ser obtidos via argumentos do programa.


    Ex. app M N m1 m2 m3 ... mX n1 n2 ... nY

    app 1 1
    SAIDA_8 = Quantidade invalida de argumentos.

    app 1 1 5
    SAIDA_8 = Quantidade invalida de argumentos.

    app 3 1 5 5 1 1
    SAIDA_1 = O numero 5 pertence ao conjunto A.
    SAIDA_1 = O numero 5 pertence ao conjunto A.
    SAIDA_1 = O numero 1 pertence ao conjunto A.
    SAIDA_2 = O numero 1 pertence ao conjunto B.
    SAIDA_3 = B esta contido em A!

    app 1 3 5 5 1 1
    SAIDA_7 = N invalido, ele deve ser menor ou igual a M.

    app 6 2 3 3 3 99 22 4 33 3
    SAIDA_1 = O numero 3 pertence ao conjunto A.
    SAIDA_1 = O numero 3 pertence ao conjunto A.
    SAIDA_1 = O numero 3 pertence ao conjunto A.
    SAIDA_1 = O numero 99 pertence ao conjunto A.
    SAIDA_1 = O numero 22 pertence ao conjunto A.
    SAIDA_1 = O numero 4 pertence ao conjunto A.
    SAIDA_2 = O numero 33 pertence ao conjunto B.
    SAIDA_2 = O numero 3 pertence ao conjunto B.
    SAIDA_4 = B NAO esta contido em A!

    app 1 11
    SAIDA_8 = Quantidade invalida de argumentos.

    app 1 11 1 1 2 3 4 5 6 7 8 9 10 11
    SAIDA_6 = N invalido. Deve estar entre 1 e 10.
*/

#include <stdio.h>
#include <stdlib.h>

#define SAIDA_1 "\nSAIDA_1 = O numero %d pertence ao conjunto A."
#define SAIDA_2 "\nSAIDA_2 = O numero %d pertence ao conjunto B."
#define SAIDA_3 "\nSAIDA_3 = B esta contido em A!"
#define SAIDA_4 "\nSAIDA_4 = B NAO esta contido em A!"
#define SAIDA_5 "\nSAIDA_5 = M invalido. Deve estar entre 1 e 10."
#define SAIDA_6 "\nSAIDA_6 = N invalido. Deve estar entre 1 e 10."
#define SAIDA_7 "\nSAIDA_7 = N invalido, ele deve ser menor ou igual a M."
#define SAIDA_8 "\nSAIDA_8 = Quantidade invalida de argumentos."

int main(int argc, char *argv[]) {
    int i, j, quantArg, M, N, cont = 0, quant = 0;
    M = atoi(argv[1]); //Recebe o primeiro valor inserido
    N = atoi(argv[2]); //Recebe o segundo valor inserido
    quantArg = M + N; //Soma a quantidade de argumentos que será necessário
    int conjA[M]; //Cria o vetor de acordo com a quantidade de valores desejado para m
    int conjB[N]; //Cria o vetor de acordo com a quantidade de valores desejado para n
    if(atoi(argv [1])== 0){//faz validacao do valor m
        printf(SAIDA_5);
        quant++;
    } if(atoi (argv [2])== 0){// faz validacao do valor n
        printf(SAIDA_6);
        quant++;
    }
    //incio do processamento
    if(quant == 0){
        if(argc == quantArg + 3){ //Verifica se a quantidade de argumentos desejado coicide com a inserida
            if(M <= 0 || M > 10){ //Verifica se M nao esta entre 1 a 10
                printf(SAIDA_5);
                if(N <= 0 || N > 10){ //Verifica se N nao esta entre 1 a 10
                    printf(SAIDA_6);
                }
            } else {//Caso M esteja entre 1 a 10
                if(N <= 0 || N > 10){ //Verifica de N esta entre 1 a 10
                    printf(SAIDA_6);
                } else { //Caso N esteja entre 1 a 10
                    if(M >= N){ //Verifica se M e maior que N
                        j = 0;
                        for (i = 3; i < argc - N; i++)
                        {
                            //insere  os valores solicitados em M  
                            conjA[j] = atoi(argv[i]);
                            printf(SAIDA_1, conjA[j]);
                            j++;
                        }
                        j = 0;
                            //insere  os valores solicitados em N
                        for (i = M + 3; i < argc; i++)
                        {
                            conjB[j] = atoi(argv[i]);
                            printf(SAIDA_2, conjB[j]);
                            j++;
                        }
                            //solicita as casas de M
                        for (i = 0; i < M; i++)
                        {
                           //solicita as casa de N
                            for (j = 0; j < N; j++)
                            {
                                 //Caso valor de N esteja em M, iguala o valor a 0
                                if(conjB[j] == conjA[i]){
                                    conjB[j] = 0;
                                }
                            }
                        }
                           //solicita as casa de N
                        for (i = 0; i < N; i++)
                        {
                            // varifica qunatas casas de N sao iguais a 0
                            if(conjB[i] == 0){
                                cont++;
                            }
                        }
                        if(N == cont){
                            //caso todos as casas de N sejam 0 , impre SAIDA_3
                            printf(SAIDA_3);
                        } else {
                            //Caso nao sejam todos igual  a zero imprime SAIDA_4
                            printf(SAIDA_4);
                        }
                    } else {
                        //N nao corresponde aos criterios de
                        printf(SAIDA_7);
                    }
                }
            }
            // fim do processamento
        } else {
            printf(SAIDA_8);
        }
    } else {
        if(argc != quantArg + 3){
            //finaliza programa caso N ou M = 0
            printf(SAIDA_8);
        }
    }
    return 0;
}
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int gabarito[100];
    int ra[100];
    int resposta[1000];
    int i = 0;
    int j = 0;
    int cont = 0;
    int nota =0;


    //codigo do professor//



    // leitor do gabrito
    for (i = 1; i <= 10; i++)
    {
        printf("insira a resposta do gabarito:\n");
        scanf("%d", &gabarito[i]);
    }

    // ler RA dos alunos e suas respostas.
    for (i = 1; i <= 100; i++)
    {
        printf("Insira o RA:\n");
        scanf("%d", &ra[i]);
        for (j = 1; j <= 10; j++)
        {
            cont++;
            scanf("%d", &resposta[cont]);
        }
    }
    // impressao do gabarito
    for (i = 1; i <= 10; i++)
    {
        printf("Gabarito %d e %d", i, gabarito[i]);
    }
    // imprimindo RA seguido das respostas.
    for (i = 1; i <= 100; i++)
    {
        printf("Aluno de RA:%d\n",ra[j]);
        for(j=1;j<=10;j++){
            cont++;
            printf("%d \n",resposta[cont]);
        }
    }



    //codigo de Jose Gabriel//
    //Dentre as respostas “A” “B” “C” “D” “E” qual resposta teve a maior quantidade de alunos que a acertaram?

    for(i=1;i<=100;i++){
        for(j=1;j<=10;j++){
            cont+=10;
            if ((resposta[i+cont]) == (gabarito[j])){
                nota++;
                if ((resposta[i+cont]) == 'd'){
                    
            }

        }

    }



    return 0;
}
}
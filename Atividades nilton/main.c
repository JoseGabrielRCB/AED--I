#include <stdio.h>
#include <stdlib.h>

int main(){
    int Teste;
    printf("Calcular area da cricunferencia\n");
    printf("Informe o numero");
        scanf("%d",&Teste);
         if (Teste<=0){
            printf("Selecione um numero maior que 0");
         }
         else{
            Teste = 3,14 * Teste*Teste;
            printf("o valor da area e %d",Teste);
         }
    return 0;
}

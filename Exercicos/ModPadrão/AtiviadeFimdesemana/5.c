#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void basc(int *p1, int *p2, int *p3)
{
    int aux;
    aux = pow(*p2, 2) + (-4 * *p1 * *p3);
    if(aux < 0){
        printf("Equacao sem raizes reais\n");
    }
    else
    {
        for(int i =1;i<3;i++){
            int aux2 =  ((*p2*-1) + (sqrt(aux)*pow(-1,i) )) / (2**p1);
            printf(" Raiz vale de X(%d) %d",i,aux2);
        }
    }
}

int main()
{
    int a, b, c;
    printf("Insira os coeficiente A, B , C da equaçao\n");
    scanf("%d %d %d", &a, &b, &c);
    basc(&a, &b, &c);

    return 0;
}
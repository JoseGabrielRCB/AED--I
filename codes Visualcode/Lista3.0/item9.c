#include <stdio.h>
#include <stdlib.h>

/*10. A conversão de graus Farenheit para centígrados é obtida por C = 5 (F – 32) / 9. Escrever um
algoritmo que calcule e escreva uma tabela de centígrados em função de graus Farenheit, que variam
de 50 a 150 de 1 em 1. */
int main(){
    int f=50;
    int c=0;

  printf("Veja a tabela de transformacao de F para C\n");
  
  for (f = 50; f < 150 ; f++)
  {
    c= (5*(f-32)/9);
    printf("Valor %d F ----> Valor %d C\n",f,c);
  }
  return 0;
  
}


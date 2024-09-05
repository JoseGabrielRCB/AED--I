#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int menor1(int n1,int n2)
{
    if (n1 > n2)
    {
        n1 = n2;
    }
    return (n1);
}
int maior2(int n1,int n2)
{
    if (n1 < n2)
    {
        n1 = n2;
    }
    return (n1);
}
void flush_in()
{
    int ch;
    do
    {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}
int resp(char resposta[100])
{
    char comp_a[10] = {'A'};
    char comp_b[10] = {'B'};
    char comp_c[10] = {'C'};
    char comp_d[10] = {'D'};
    int n1,n2;

    int i = strcmp(comp_a, resposta);
    int a = strcmp(comp_b, resposta);
    int b = strcmp(comp_c, resposta);
    int d = strcmp(comp_d, resposta);
    int aux = 0;

    if (i == 0)
    {
        aux = 1;
        printf("TESTAR FUNCAO 1\n");
        printf("INFORME OS NUMEROS A SEREM ANALISADOS\n");
        scanf("%d %d",&n1,&n2);
        int g = menor1(n1,n2);
        printf("VALOR DO MENOR: %d\n", g);
    }
    else if (a == 0)
    {
        aux = 1;
        printf("TESTAR FUNCAO 2\n");
        printf("INFORME OS NUMEROS A SEREM ANALISADOS\n");
        scanf("%d %d",&n1,&n2);
        int g = maior2(n1,n2);
        printf("VALOR DO MAIOR: %d\n", g);
    }
    else if (b == 0)
    {
        aux = 1;
        printf("TESTE AS DUAS\n");
        printf("INFORME OS NUMEROS A SEREM ANALISADOS\n");
        scanf("%d %d",&n1,&n2);
        int g = menor1(n1,n2);
        int h = maior2(n1,n2);
        printf("VALOR DO MENOR %d\n VALOR DO MAIOR %d\n",g,h);
    }
    else if (d == 0)
    {
        printf("FINALIZADO\n");
    }
    else
    {
        printf("responda A,B,C\n");
    }
    return (aux);
}

int main()
{
    int i;
    char resposta[100];
    printf("Veja os maior e menor numemro\n");
    do
    {
        printf("\nA) testar funcao 1\n B)testar funcao 2\n C) TESTAR AS DUAS\n D)terminar\n");
        gets(resposta);
        i = resp(resposta);
        flush_in();
    } while (i == 0);

    return 0;
}
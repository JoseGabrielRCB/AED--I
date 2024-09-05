// conside um  int vetor x com y elementos, descubra a soma do maior par impar, respctivamente

#include <stdio.h>
#include <stdlib.h>

int par_impar(int a)
{
    int verificador = 0;

    verificador = a % 2;

    if (verificador == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int acha_maior_soma(int vetor[])
{
    int maior = 0;

    for (int i = 0; i < 12; i++)
    {
        if (i == 12)
        {
        }
        else
        {
            int ver_1 = par_impar(vetor[i]);
            int ver_2 = par_impar(vetor[i + 1]);

            if (ver_1 == 1 && ver_2 == 0)
            {
                int soma = vetor[i] + vetor[i + 1];
                if (soma > maior)
                {
                    maior = soma;
                }
            }
        }
    }

    return (maior);
}

int main()
{
    int vetor[12] = {5, 10, 3, 36, 55, 2, 11, 9, 8, 6, 22, 5};

    int soma_maior = acha_maior_soma(vetor);

    printf("SOMA MAIOR: %d\n", soma_maior);

    return 0;
}
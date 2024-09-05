#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deletarCaracter(char *str, const char *palavra)
{
    size_t tamanhoPalavra = strlen(palavra);
    char *posicao = str;

    while ((posicao = strstr(posicao, palavra)) != NULL)
    {
        memmove(posicao, posicao + tamanhoPalavra, strlen(posicao + tamanhoPalavra) + 1);
    }
}

int isPalindromo(char nome[100])
{
    int aux = 0;
    int tamanho = strlen(nome);
    printf("\n\n\n%d\n\n\n", tamanho);
    aux = tamanho - 1;
    int cont = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (nome[i] == nome[aux])
        {
            cont++;
            printf("%d", cont);
        }
        aux--;
    }
    if (cont == tamanho)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Printa(int is)
{
    if (is == 1)
    {
        printf("\nEh um palindromo.\n");
    }
    else
    {
        printf("\nNao eh um palindromo.\n");
    }
}

int main()
{
    char nome[] = "SOCORRAM-ME SUBI NO ONIBUS EM MARROCOS";
    deletarCaracter(nome, " ");
    deletarCaracter(nome, ",");
    deletarCaracter(nome, ".");
    deletarCaracter(nome, "-");
    printf("\n\n\n\n%s\n\n\n\n", nome);
    Printa(isPalindromo(nome));

    return 0;
}
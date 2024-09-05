/*  Resolva T4 usando modularização. Os dados de execução deverão ser
    recebidos via argumento do programa na linha de comando.

    Exemplos de execuçães

    app 3 GCTTTCGACGAT GATCGAGCTTCGAA GGTCTAGCTAAT TCGA
    app 3 GATCGAGCTTCGAA GCTTTCGACGAT GGTCTAGCTAAT TCGA
    app 3 GGTCTAGCTAAT GCTTTCGACGAT GATCGAGCTTCGAA  TCGA
    app 3 GGTCTAGCTAAT GATCGAGCTTCGAA  GCTTTCGACGAT TCGA
    app 3 GCTTTCGACGAT GATCGAGCTTCGAA GGTCTAGCTAAT TCGA
    app 3 GCTTTCGACGAT GATCGAGCTTCGAA GGTCTAGCTAAT TCGA
    

    SAIDA_2 = Quantidade de bacterias: 3
    SAIDA_3 = Bacteria: GCTTTCGACGAT
    SAIDA_3 = Bacteria: GATCGAGCTTCGAA
    SAIDA_3 = Bacteria: GGTCTAGCTAAT
    SAIDA_4 = Virus: TCGA
    SAIDA_5 = Bacteria infectada: GCTT
    SAIDA_5 = Bacteria infectada: GAGCTA
    SAIDA_5 = Bacteria infectada: GGTCTAGCTAAT
    SAIDA_6 = DNA resultante: GCT

    app 5 AGCT TGC CGCAA TGTC ATGTTC T

    SAIDA_2 = Quantidade de bacterias: 5
    SAIDA_3 = Bacteria: AGCT
    SAIDA_3 = Bacteria: TGC
    SAIDA_3 = Bacteria: CGCAA
    SAIDA_3 = Bacteria: TGTC
    SAIDA_3 = Bacteria: ATGTTC
    SAIDA_4 = Virus: T
    SAIDA_5 = Bacteria infectada: AGC
    SAIDA_5 = Bacteria infectada: GC
    SAIDA_5 = Bacteria infectada: CGCAA
    SAIDA_5 = Bacteria infectada: GC
    SAIDA_5 = Bacteria infectada: AGC
    SAIDA_6 = DNA resultante: GC
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LIMITE_BACTERIAS 10
#define COMPR_BACTERIAS 1000
#define COMPR_VIRUS 1000

#define SAIDA_2 "\nSAIDA_2 = Quantidade de bacterias: %d"
#define SAIDA_3 "\nSAIDA_3 = Bacteria: %s"
#define SAIDA_4 "\nSAIDA_4 = Virus: %s"
#define SAIDA_5 "\nSAIDA_5 = Bacteria infectada: %s"
#define SAIDA_6 "\nSAIDA_6 = DNA resultante: %s"

void deletarProteina(char *str, const char *palavra)
{
    //função para deletar e sequencia do virus da Bacteria

    size_t tamanhoPalavra = strlen(palavra); //recebe tamanho da palavra
    char *posicao = str;

    while ((posicao = strstr(posicao, palavra)) != NULL)
    {
        memmove(posicao, posicao + tamanhoPalavra, strlen(posicao + tamanhoPalavra) + 1);//reorganiza a string
    }
}

void maiorSubstringComum(char BACTERIAS[][1000], int nBacterias)
{ // função que encontra a maior substring em comum
    char maiorSubStringComum[1000] = "";
    int tamanhoRec = 0;
    int len = strlen(BACTERIAS[0]);
    // a função percorre dois for comparando "pedaços" da string até seja encontrado a maior SSC
    for (int m = 1; m <= len; m++)
    {
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j <= len - m; j++)
            {
                char comparacao[1000];
                strncpy(comparacao, BACTERIAS[i] + j, m);
                // string comparacao recebe a string bacteria, mas o loop faz "armazena" pedaços da string.
                comparacao[m] = '\0';
                int comum = 1;
                // neste loop for, é checado se o pedaço da string está nas outras BACTERIAS
                for (int l = 1; l < nBacterias; l++)
                {
                    if (strstr(BACTERIAS[l], comparacao) == NULL)
                    {
                        comum = 0;
                        l = nBacterias;
                    }
                }
                if (comum && m > tamanhoRec)// Armazena o tamanho maior, para comparação
                {
                    tamanhoRec = m;
                    strcpy(maiorSubStringComum, comparacao);
                }
            }
        }
    }

    printf(SAIDA_6, maiorSubStringComum); //Escreve a maior substring 
}

void imprime(char BACTERIAS[][1000], int argc, char VIRUS[], int nBacterias)
{
    for (int k = 0; k < 727; k++) //garantir que remove a sequancia do virus.
    {
        for (int i = 0; i < argc - 2; i++)
        {
            deletarProteina(BACTERIAS[i], VIRUS);// deleta a sequencia(string) do virus das bacterias
        }
    }
    for (int i = 0; i < nBacterias; i++)
    {
        printf(SAIDA_5, BACTERIAS[i]);// printa as bacteias alteradas
    }
}

int main(int argc, char *argv[])
{
    int nBacterias;
    char BACTERIAS[LIMITE_BACTERIAS][COMPR_BACTERIAS];
    char VIRUS[COMPR_VIRUS];
    nBacterias = atoi(argv[1]);
    printf(SAIDA_2, nBacterias);
    for (int i = 2; i < argc - 1; i++)
    {
        strcpy(BACTERIAS[i - 2], argv[i]);
        printf(SAIDA_3, BACTERIAS[i - 2]);
    }
    strcpy(VIRUS, argv[argc - 1]);
    printf(SAIDA_4, VIRUS);
    imprime(BACTERIAS, argc, VIRUS, nBacterias);//Incia a função de impressão
    maiorSubstringComum(BACTERIAS, nBacterias);// incia função para substring comum
    return 0;
}

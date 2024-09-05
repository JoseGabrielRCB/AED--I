#include <stdio.h>
#include <stdlib.h>

int main ()
{

    int linha = 99, coluna = 8;
    int m[linha][coluna], somatoria[linha], soma=0;
    int menor = 99999, linha_menor, maior_linha = 0, maior = 0;
    int cont, frequencia=0, freq_max = 0,cont_freq, max[linha*coluna], freq_dois=0;
    float media, media1, media3;
    int freq1 = 0, freq3 = 0, cont1 = 0, cont3 = 0;

    for (int i=0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            scanf ("%d", &m[i][j]);
            if (m[i][j] < menor)
            {
                menor = m[i][j];
                linha_menor = i;
            }
            if (m[i][j]==18600)
            {
                frequencia += 1;
            }
            
            
        }
    }
    printf ("\nO menor numero eh: %d e se encontra na linha: %d", menor, linha_menor+1);
    
    printf("\n\nFrequencia do numero 18600: %d", frequencia);
    frequencia = 0;

    for (int i = 0; i < coluna; i++)
    {
        if (m[linha_menor][i] > maior_linha)
        {
            maior_linha = m[linha_menor][i];
        }
        
    }
    printf("\n\nE o maior numero desta linha eh: %d", maior_linha);

    for (int i = 0; i < linha; i++)
    {
        for (int k = 0; k < coluna; k++)
        {
            soma += m[i][k];
        }
        somatoria[i] = soma;
        soma = 0;
        printf("\n\nA soma da linha %d eh de: %d", i+1, somatoria[i]);
    }

    printf("\n\nSoma da linha 67: %d", somatoria[66]);
    
    soma = 0;
    cont = 0;

    for (int i = 0; i < linha; i++)
    {
        soma += m[i][4];
        cont += 1;
    }
    media = soma/cont;
    soma = 0;
    cont = 0;
    printf("\n\nMedia dos numeros da coluna 5 da matriz: %0.f", media);
    
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            frequencia = 0;
            for (int k = 0; k < linha; k++)
            {
                for (int l = 0; l < coluna; l++)
                {
                    if (m[i][j]==m[k][l])
                    {
                        frequencia ++;
                    }
                }
                 
            }
            if (frequencia > freq_max)
            {
                freq_max = frequencia;
            } 
            if (frequencia == 2)
            {
                freq_dois += m[i][j];
                cont++;
            } 
            if(frequencia == 1){
                freq1 += m[i][j];
                cont1++;
            }
        }
    }
    if (cont > 0)
    {
        media = freq_dois / cont;
        media1 = freq1 / cont1;
        media3 = freq3 / cont;
    } else {
        media = 0;
        media1 = 0;
        media3 = 0;
    }
    
    freq_dois=0;
    cont=0;
    printf("\n\nA media dos numeros com frequencia 2 eh de %0.f", media);
    printf("\n\nA media dos numeros com frequencia 1 eh de %d", cont1);
    printf("\n\nA media dos numeros com frequencia 3 eh de %d", cont3);
    
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            frequencia = 0;
            for (int k = 0; k < linha; k++)
            {
                for (int l = 0; l < coluna; l++)
                {
                    if (m[i][j]==m[k][l])
                    {
                        frequencia ++;
                    }
                }
                 
            }
            if (frequencia == freq_max)
            {
                max[cont] = m[i][j];
                cont++;
            } 
        }
    }

    menor = 99999;
    for (int i = 0; i < cont; i++)
    {
        if (max[i] > maior)
        {
            maior = max[i];
        }
        if (max[i] < menor)
        {
            menor = max[i];
        }
    }
    printf("\n\nO maior numero com a maior frequencia eh: %d", maior);
    printf("\n\nO menor numero com a maior frequencia eh: %d", menor);
    
    printf("\n\nMatriz 99*8\n");
    for (int i = 0; i < linha; i++)
    {
        printf("Linha: %d ", i+1);
        for (int j = 0; j < coluna; j++)
        {
            printf("%d|%d|  ", j+1, m[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}
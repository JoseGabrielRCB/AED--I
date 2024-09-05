#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct consulta
{
    int data;
    char nome_do_medico[100];
    char nome_do_paciente[100];
} consulta[5000];

struct paciente
{
    char nome[100];
    int idade;
} paciente[100];

struct medico
{
    char nome[100];
    char telefone[12];
} medico[20];

void INCLUI_CONSULTA(int cont)
{
    int loop = 0;
    char paciente_entrada[100];
    char medico_entrada[100];
    int aux2;

    printf("MARCAR CONSULTA\n");
    while (loop < 3)
    {

        int aux = 0;
        printf("INFORME O NOME DO PACIENTE_entrada\n");
        scanf("%s", paciente_entrada);

        for (int i = 0; i < 100; i++)
        {
            aux = strcmp(paciente[i].nome, paciente_entrada);
            if (aux == 1)
            {
                i = 100;
                strcpy(consulta[cont].nome_do_paciente, paciente_entrada);
                loop++;
            }
        }

        if (aux == 1)
        {

            printf("INSIRA O NOME DO MEDICO\n");
            scanf("%s", medico_entrada);

            for (int i = 0; i < 20; i++)
            {
                aux2 = strcmp(medico[i].nome, medico_entrada);
                if (aux2 == 1)
                {
                    loop++;
                    i = 100;
                    strcpy(consulta[cont].nome_do_medico, medico_entrada);
                }
            }
            if (aux2 == 1)
            {
                int dia, mes;

                printf("INSIRA A DATA DE CONSULTA\n");
                printf("INFORME O DIA: ");
                scanf("%d", &dia);

                printf("INFORME O MES: ");
                scanf("%d", &mes);
                loop++;

                // Supondo que 'consulta' seja um array de estruturas e 'cont' seja o índice
                consulta[cont].data = dia * 100 + mes; // Armazenando dia e mês em um único inteiro
            }
            else
            {
                printf("NOME DO MEDICO INVALIDO\n");
            }
        }
        else
        {
            printf("NOME DO PACIENTE INVALIDO");
        }
    }
}
int main()
{
    int cont = 0;
    int loop = 0;
    int continuar = 0;
    while (loop == 0)
    {
        int loop2 = 0;
        INCLUI_CONSULTA(cont);
        cont++;
        while (loop2 == 0)
        {

            printf("MARCAR MAIS UMA CONSULTA?1-sim / 2-nao\n");
            scanf("%d", &continuar);
            if (continuar == 2)
            {
                loop = 999;
            }
        }
    }

    return 0;
}



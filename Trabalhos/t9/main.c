#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define TAM 50

typedef struct
{
    long int id_reg;
    char placa[9];
    char modelo[TAM];
    char fabricante[TAM];
    int ano_fabricacao;
    int ano_modelo;
    char combustivel[TAM];
    char cor[TAM];
    int opcional[8];
    float preco_compra;
} CARRO;

char opcionais[][TAM] = {
    "4.portas",
    "cambio.automatico",
    "vidros.eletricos",
    "abs",
    "air.bag",
    "ar.condicionado",
    "banco.couro",
    "sensor.estacionamento"};

// função que lê a entrada do usuário e executa as devidas funções.

int entrada()
{
    long int entrada;
    char input[100];
    do
    {
        printf("\n==========================================\n[1] - Informar quantos registros tem carro.dbf\n");
        printf("[2] - Ordenar os registros de carro.dbf de forma crescente pelo campo placa e armazena-los no arquivo carro.ord.\n");
        printf("[3] - Mostrar os registros de carro.ord.\n");
        printf("[4] - Para cada tipo de combustivel informar a quantidade de carros.\n");
        printf("[5] - Para cada tipo de opcional informar a quantidade de carros.\n==========================================\n");
        printf("[0] - Sair \n\n");
        if (fgets(input, sizeof(input), stdin) != NULL)
        {
            if (sscanf(input, "%d", &entrada) == 1)
            {
                if (entrada == 1)
                {
                    system("cls");
                    printf("\n[%d] ", entrada);
                    contarRegistros();
                }
                if (entrada == 2)
                {
                    system("cls");
                    ordenarRegistros();
                    printf("\n[%d]", entrada);
                    printf(" - FUNCAO AINDA NAO IMPLEMENTADA \n");
                }
                if (entrada == 3)
                {
                    system("cls");
                    printf("\n[%d]", entrada);
                    printf(" - FUNCAO AINDA NAO IMPLEMENTADA \n");
                }
                if (entrada == 4)
                {
                    system("cls");
                    informarCombustivel();
                }
                if (entrada == 5)
                {
                    system("cls");
                    informarOpcionais();
                }
                if (entrada == 0)
                {
                    system("cls");
                    printf("\n[%d]", entrada);
                    printf(" Adeus =D\n");
                }
                if (entrada < 0 || entrada > 5)
                {
                    system("cls");
                    printf("[%d] Input invalido\n", entrada);
                }
            }
            else
            {
                printf("Input invalido \n");
            }
        }
    } while (entrada != 0);
}

// função queconta os registros do arquivo

void contarRegistros()
{
    int registros = 0;
    int contador = 0; // Inicializar o contador
    CARRO carro;
    FILE *leitor = fopen("carro.dbf", "rb");
    if (leitor == NULL)
    {
        printf("Erro ao abrir o arquivo carro.dbf, por favor coloque ele na mesma pasta do output.\n");
    }

    // Contar registros
    while (fread(&carro, sizeof(CARRO), 1, leitor) == 1)
    {
        registros++;
    }

    printf("Ha um total de %d registros\n", registros);
}

void ordenarRegistros()
{
    int registros = 0, contador = 0;
    CARRO carro;
    FILE *leitor = fopen("carro.dbf", "rb");
    if (leitor == NULL)
    {
        printf("Erro ao abrir o arquivo carro.dbf, por favor coloque ele na mesma pasta do output.\n");
    }

    // Contar registros
    while (fread(&carro, sizeof(CARRO), 1, leitor) == 1)
    {
        registros++;
    }

    // Voltar para o início do arquivo
    fseek(leitor, 0, SEEK_SET);

    // salvo os dados  em vetores e matrizes para fácil manupulação

    char placas[registros][10];
    long int id_reg[registros];
    char placa[registros][9];
    char modelo[registros][TAM];
    char fabricante[registros][TAM];
    int ano_fabricacao[registros];
    int ano_modelo[registros];
    char combustivel[registros][TAM];
    char cor[registros][TAM];
    int opcional[registros][8];
    float preco_compra[registros];

    // Ler registros e salvar em suas respectivas matrizes
    while (fread(&carro, sizeof(CARRO), 1, leitor) == 1)
    {

        strcpy(placas[contador], carro.placa);
        id_reg[contador] = carro.id_reg;
        strcpy(modelo[contador], carro.modelo);
        strcpy(fabricante[contador], carro.fabricante);
        ano_fabricacao[contador] = carro.ano_fabricacao;
        ano_modelo[contador] = carro.ano_modelo;
        strcpy(combustivel[contador], carro.combustivel);
        strcpy(cor[contador], carro.cor);
        for (int i = 0; i < 8; i++)
        {
            opcional[contador][i] = carro.opcional[i];
        }
        preco_compra[contador] = carro.preco_compra;
        contador++;
    }

    fclose(leitor);

    // TODO Fazer organizador

    for (int i = 0; i < registros; i++)
    {
        int comparador = 0;
        if (i < registros)
        {
            comparador = strcmp(placa[i], placa[i + 1]);
        }

        if (comparador > 0)
        {
        }
    }

    // TODO apagar isso
    //  for (int i = 0; i < 5; i++)
    //  {
    //      printf("\n[5] - Carro %d \n", i);
    //      printf("Placa: %s\n", placas[i]);
    //      printf("Id: %d\n", id_reg[i]);
    //      printf("Modelo: %s\n", modelo[i]);
    //      printf("Fabricante: %s\n", fabricante[i]);
    //      printf("Ano fabricacao: %d\n", ano_fabricacao[i]);
    //      printf("Ano Modeo: %d\n", ano_modelo[i]);
    //      printf("Combustivel : %s\n", combustivel[i]);
    //      printf("Cor : %s\n", cor[i]);
    //      printf("Opcionais: ");
    //      for (int j = 0; j < 8; j++)
    //      {
    //          if (opcional[i][j] == 1)
    //          {
    //              printf("%s ", opcionais[j]);
    //          }
    //      }
    //      printf("\n");
    //      printf("Preco Compra: %f\n", preco_compra[i]);
    //  }
}

void escreverRegistro()
{
}

void mostrarRegistro()
{
}

void informarCombustivel()
{
    int registros = 0, contador = 0, contflex = 0, contalcool = 0, contgasolina = 0, contdiesel = 0;

    CARRO carro;
    FILE *leitor = fopen("carro.dbf", "rb");
    if (leitor == NULL)
    {
        printf("Erro ao abrir o arquivo carro.dbf, por favor coloque ele na mesma pasta do output.\n");
    }

    while (fread(&carro, sizeof(CARRO), 1, leitor) == 1)
    {
        registros++;
    }

    fseek(leitor, 0, SEEK_SET);

    char combustivel[registros][TAM];

    while (fread(&carro, sizeof(CARRO), 1, leitor) == 1)
    {
        strcpy(combustivel[contador], carro.combustivel);
        contador++;
    }

    for (int i = 0; i < registros; i++)
    {
        if (strcmp(combustivel[i], "alcool") == 0)
        {
            contalcool++;
        }
        if (strcmp(combustivel[i], "gasolina") == 0)
        {
            contgasolina++;
        }
        if (strcmp(combustivel[i], "flex") == 0)
        {
            contflex++;
        }
        if (strcmp(combustivel[i], "diesel") == 0)
        {
            contdiesel++;
        }
    }
    fclose(leitor);

    printf("\n==========================================\n[4] - Carros que usam gasolina: %d\n[4] - Carros que usam alcool: %d\n[4] - Carros que sao flex: %d\n[4] - Carros que usam diesel: %d\n==========================================\n", contgasolina, contalcool, contflex, contdiesel);
}

void informarOpcionais()
{
    int registros = 0, contador = 0, contportas = 0, contcambio = 0, contvidros = 0, contabs = 0, contair = 0, contar = 0, contbanco = 0, contsensor = 0;
    CARRO carro;
    FILE *leitor = fopen("carro.dbf", "rb");
    if (leitor == NULL)
    {
        printf("Erro ao abrir o arquivo carro.dbf, por favor coloque ele na mesma pasta do output.\n");
    }

    // Contar registros
    while (fread(&carro, sizeof(CARRO), 1, leitor) == 1)
    {
        registros++;
    }

    // Voltar para o início do arquivo
    fseek(leitor, 0, SEEK_SET);

    // salvo os dados  em vetores e matrizes para fácil manupulação

    int opcional[registros][8];

    while (fread(&carro, sizeof(CARRO), 1, leitor) == 1)
    {

        for (int i = 0; i < 8; i++)
        {
            opcional[contador][i] = carro.opcional[i];
        }

        contador++;
    }
    fclose(leitor);

    for (int i = 0; i < registros; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (opcional[i][j] == 1)
            {

                if (strcmp(opcionais[j], "4.portas") == 0)
                {
                    contportas++;
                }
                if (strcmp(opcionais[j], "cambio.automatico") == 0)
                {
                    contcambio++;
                }
                if (strcmp(opcionais[j], "vidros.eletricos") == 0)
                {
                    contvidros++;
                }
                if (strcmp(opcionais[j], "abs") == 0)
                {
                    contabs++;
                }
                if (strcmp(opcionais[j], "air.bag") == 0)
                {
                    contair++;
                }
                if (strcmp(opcionais[j], "ar.condicionado") == 0)
                {
                    contar++;
                }
                if (strcmp(opcionais[j], "banco.couro") == 0)
                {
                    contbanco++;
                }
                if (strcmp(opcionais[j], "sensor.estacionamento") == 0)
                {
                    contsensor++;
                }
            }
        }
    }
    fclose(leitor);
    printf("\n==========================================\n[5] - Carros com 4 portas: %d\n[5] - Carros com cambio automatico: %d\n[5] - Carros com vidros eletricos: %d\n[5] - Carros com abs: %d\n[5] - Carros com air bag: %d\n[5] - Carros com ar condicionado: %d\n[5] - Carros com banco de couro: %d\n[5] - Carros com sensor de estacionamento: %d\n==========================================\n", contportas, contcambio, contvidros, contabs, contair, contar, contbanco, contsensor);
}

int main()
{
    entrada();
    return 0;
}
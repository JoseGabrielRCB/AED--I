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

struct CARROS_ORGANIZADOS
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
};

char opcionais[][TAM] = {
    "4.portas",
    "cambio.automatico",
    "vidros.eletricos",
    "abs",
    "air.bag",
    "ar.condicionado",
    "banco.couro",
    "sensor.estacionamento"};

void contarRegistros();
void ordenarCarros();
void lerCarrosLimpos();
void informarCombustivel();
void informarOpcionais();

// Função que le a escolha do usuário em relação ao menu.

void entrada()
{
    int entrada;
    char input[100];
    system("cls");
    do
    {
        printf("===============================================\n[1] - Informar quantos registros tem carro.dbf\n");
        printf("[2] - Ordenar os registros de carro.dbf de forma crescente pelo campo placa e armazena-los no arquivo carro.ord.\n");
        printf("[3] - Mostrar os registros de carro.ord.\n");
        printf("[4] - Para cada tipo de combustivel informar a quantidade de carros.\n");
        printf("[5] - Para cada tipo de opcional informar a quantidade de carros.\n");
        printf("[0] - Sair");
        printf("\n===============================================\n");
        if (fgets(input, sizeof(input), stdin) != NULL)
        {
            if (sscanf(input, "%d", &entrada) == 1)
            {
                if (entrada == 1)
                {
                    system("cls");
                    printf("\n[%d] - ", entrada);
                    contarRegistros();
                }
                if (entrada == 2)
                {
                    system("cls");
                    printf("\n[%d] - ", entrada);
                    ordenarCarros();
                }
                if (entrada == 3)
                {
                    system("cls");
                    printf("\n[%d] - ", entrada);
                    lerCarrosLimpos();
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
                    printf("\n\n[%d]", entrada);
                    printf(" Adeus =D\n\n");
                }
                if (entrada < 0 || entrada > 5)
                {
                    system("cls");
                    printf("\n[%d] Input invalido\n\n", entrada);
                }
            }
            else
            {
                system("cls");
                printf("\nInput invalido \n\n");
            }
        }
    } while (entrada != 0);
}

// Função que conta a quantidade de registros
void contarRegistros()
{
    int registros = 0;
    CARRO carro;
    FILE *leitor = fopen("carro.dbf", "rb");
    if (leitor == NULL)
    {
        printf("Erro ao abrir o arquivo carro.dbf, por favor coloque ele na mesma pasta do output.\n");
        return;
    }

    while (fread(&carro, sizeof(CARRO), 1, leitor) == 1)
    {
        registros++;
    }

    fclose(leitor);

    printf("Ha um total de %d registros\n\n", registros);
}

// Funcao para ordenar os carros

void ordenarCarros()
{
    int quant = 0;
    CARRO carro;
    FILE *leitor = fopen("carro.dbf", "rb");
    if (leitor == NULL)
    {
        printf("Erro ao abrir o arquivo carro.dbf, por favor coloque ele na mesma pasta do output.\n");
        return;
    }

    while (fread(&carro, sizeof(CARRO), 1, leitor) == 1)
    {
        quant++;
    }
    fseek(leitor, 0, SEEK_SET);

    // Cria e armazena os dados de carro.dbf em uma structure auxiliar, afim de facilitar o processo de ordenação dos carros.

    struct CARROS_ORGANIZADOS carros_limpos[quant];

    fread(carros_limpos, sizeof(struct CARROS_ORGANIZADOS), quant, leitor);

    fclose(leitor);

    // Ordenação dos carros por placa, esse for irá comparar todos os elementos e se algum deles acionar  o if, suas posiçãos são trocadas.

    for (int i = 0; i < quant - 1; i++)
    {
        for (int j = 0; j < quant - i - 1; j++)
        {
            if (strcmp(carros_limpos[j].placa, carros_limpos[j + 1].placa) > 0)
            {
                struct CARROS_ORGANIZADOS temp = carros_limpos[j];
                carros_limpos[j] = carros_limpos[j + 1];
                carros_limpos[j + 1] = temp;
            }
        }
    }

    // Escrita do arquivo carro.ord

    FILE *escritor = fopen("carro.ord", "wb");
    for (int u = 0; u < quant; u++)
    {
        fwrite(&carros_limpos[u], sizeof(carros_limpos[u]), 1, escritor);
    }
    fclose(escritor);
    system("cls");
    printf("\n");
    printf("[2] - Ordenacao e escrita do arquvio.ord concluida com sucesso!\n\n");
}

// Função que lê os dados do arquivo carro.ord

void lerCarrosLimpos()
{
    int quant = 0;
    CARRO carro;
    FILE *leitor = fopen("carro.ord", "rb");
    if (leitor == NULL)
    {
        printf("Erro ao abrir o arquivo carro.ord, por favor coloque ele na mesma pasta do output.\n");
        return;
    }
    while (fread(&carro, sizeof(CARRO), 1, leitor) == 1)
    {
        quant++;
    }
    fseek(leitor, 0, SEEK_SET);
    struct CARROS_ORGANIZADOS carros_limpos[quant];

    fread(carros_limpos, sizeof(struct CARROS_ORGANIZADOS), quant, leitor);
    fclose(leitor);

    // Imprime os dados organizados.

    printf("\n==========================================\n");
    for (int i = 0; i < quant; i++)
    {
        printf("\n[3] - Id: %ld", carros_limpos[i].id_reg);
        printf("\n[3] - Placa: %s", carros_limpos[i].placa);
        printf("\n[3] - Modelo: %s", carros_limpos[i].modelo);
        printf("\n[3] - Fabricante: %s", carros_limpos[i].fabricante);
        printf("\n[3] - Ano Fabricacao: %d", carros_limpos[i].ano_fabricacao);
        printf("\n[3] - Ano Modelo: %d", carros_limpos[i].ano_modelo);
        printf("\n[3] - Combustivel: %s", carros_limpos[i].combustivel);
        printf("\n[3] - Cor: %s", carros_limpos[i].cor);
        int tamanhoOpcionais = sizeof(opcionais) / sizeof(opcionais[0]);
        printf("\n[3] - Opcionais: ");
        for (int m = 0; m < tamanhoOpcionais; m++)
        {
            if (carros_limpos[i].opcional[m] != 0)
            {
                printf("\n    %s", opcionais[m]);
            }
        }
        printf("\n[3] - Preco de compra %.2f\n\n", carros_limpos[i].preco_compra);
    }
    printf("\n==========================================\n");
}

// Funcao que informa a quantidade de combustiveis.

void informarCombustivel()
{
    int registros = 0, contador = 0, contflex = 0, contalcool = 0, contgasolina = 0, contdiesel = 0;

    CARRO carro;
    FILE *leitor = fopen("carro.dbf", "rb");
    if (leitor == NULL)
    {
        printf("Erro ao abrir o arquivo carro.dbf, por favor coloque ele na mesma pasta do output.\n");
        return;
    }

    // Determina a quantidade de registros.

    while (fread(&carro, sizeof(CARRO), 1, leitor) == 1)
    {
        registros++;
    }

    // Volta o ponteiro para o início do arquivo

    fseek(leitor, 0, SEEK_SET);

    // Salva em uma matriz

    char combustivel[registros][TAM];

    while (fread(&carro, sizeof(CARRO), 1, leitor) == 1)
    {
        strcpy(combustivel[contador], carro.combustivel);
        contador++;
    }

    // Contagem dos carros pelo tipo de combustível.

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

    printf("===============================================\n[4] - Carros que usam gasolina: %d\n[4] - Carros que usam alcool: %d\n[4] - Carros que sao flex: %d\n[4] - Carros que usam diesel: %d\n===============================================\n", contgasolina, contalcool, contflex, contdiesel);
}

// Funcao que informa a quantidade de carros que tem opcionais
void informarOpcionais()
{
    int registros = 0, contador = 0, contportas = 0, contcambio = 0, contvidros = 0, contabs = 0, contair = 0, contar = 0, contbanco = 0, contsensor = 0;
    CARRO carro;
    FILE *leitor = fopen("carro.dbf", "rb");
    if (leitor == NULL)
    {
        printf("Erro ao abrir o arquivo carro.dbf, por favor coloque ele na mesma pasta do output.\n");
        return;
    }

    // Conta a quantidade de registros
    while (fread(&carro, sizeof(CARRO), 1, leitor) == 1)
    {
        registros++;
    }

    // Volta no começo do arquivo
    fseek(leitor, 0, SEEK_SET);

    // Armazena os dados em uma matriz para leitura
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

    // Contagem dos carros pelo tipo opcional.

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
    printf("\n===============================================\n");
    printf("[5] - Carros com 4 portas: %d\n[5] - Carros com cambio automatico: %d\n[5] - Carros com vidros eletricos: %d\n[5] - Carros com abs: %d\n[5] - Carros com air bag: %d\n[5] - Carros com ar condicionado: %d\n[5] - Carros com banco de couro: %d\n[5] - Carros com sensor de estacionamento: %d\n==============================================\n", contportas, contcambio, contvidros, contabs, contair, contar, contbanco, contsensor);
}

int main()
{
    entrada();
    return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define TAM 50
char opcionais[][TAM] = {{"4.portas"}, {"cambio.automatico"}, {"vidros.eletricos"}, {"abs"}, {"air.bag"}, {"ar.condicionado"}, {"banco.couro"}, {"sensor.estacionamento"}};

struct CARRO
{
    char placa[9];         // AAA-1234
    char modelo[TAM];      // gol, celta, palio, ...
    char fabricante[TAM];  // chevrolet, fiat, ...
    int ano_fabricacao;    // 1980 à 2016
    int ano_modelo;        // 1980 à 2017
    char combustivel[TAM]; // alcool, gasolina, flex, diesel
    char cor[TAM];         // branca, prata, preta
    int opcional[8];       // ver matriz opcionais
    float preco_compra;
} CARRO;
struct ENDERECO
{
    char rua[TAM];
    int numero;
    char bairro[TAM];
    char cidade[TAM];
    char estado[3];
    char cep[11]; // 99.999-999
} ENDERECO;
struct TELEFONE
{
    char telefone[14]; // 99 99999-9999
} TELEFONE;
struct CLIENTE
{
    char nome[TAM];
    char cpf[15]; // 999.999.999-99
    struct ENDERECO endereco;
    struct TELEFONE residencial;
    struct TELEFONE celular[5];
    float renda_mensal;
} CLIENTE;
struct DATA
{
    int dia, mes, ano;
} DATA;
struct VENDA_CARRO
{
    char placa_car[9];
    char cpf_cli[15];
    float preco_venda;
    struct DATA data_venda;
} VENDA_CARRO;

char conversor_char(int a)
{

    // recebe um argumento do tipo INT e converte para um CHAR
    char aux[11] = "0123456789";
    char valor_char;
    for (int i = 0; i < 10; i++)
    {
        if (a == i) // verifica a qual nuemero de 1 a 9 ele pertence.
        {
            valor_char = aux[i]; // insere o numero condizente.
            i = 10;              // finaliza o for.
        }
    }

    return (valor_char);
}

int conversor_int(char a)
{
    // Recebe um argumento(numero) CHAR e converte  para um numero do tipo INT.
    int num;
    char val[10] = "0123456789";
    for (int i = 0; i < 10; i++)
    {
        if (a == val[i]) // verifica a qual nuemero de 1 a 9 ele pertence.
        {
            num = i; // insere o numero condizente.
            i = 10;  // finaliza o for.
        }
    }
    return (num);
}

void gerar_placa(char *ptr_placa)
{
    srand(time(NULL));
    char alfabeto[27] = {"abcdefghijklmnopqrstuvwxyz"};
    char placa[4];
    int num_int[3];
    char num_char[4];

    for (int i = 0; i < 3; i++)
    {
        placa[i] = alfabeto[rand() % 26];
    }
    strcat(placa, "-");
    for (int i = 0; i < 3; i++)
    {
        num_int[i] = rand() % 9;
        num_char[i] = conversor_char(num_int[i]);
    }

    strcat(placa, num_char);

    strcpy(ptr_placa, placa);
}

void gerar_modelo(char *ptr_modelo)
{
    srand(time(NULL));
    char modelos[4][100] = {"celta", "gol", "Uno", "Sorento"};
    int a = rand() % 3;

    strcpy(ptr_modelo, modelos[a]);
}

void gerar_fabricante(char *ptr_fabricante)
{
    srand(time(NULL));
    char fabricantes[4][100] = {"Honda", "Ferrari", "Lamborghini", "Kia"};
    int a = rand() % 3;

    strcpy(ptr_fabricante, fabricantes[a]);
}

void ano_fabricacao(int **ptr_fabricacao)
{
    srand(time(NULL));
    **ptr_fabricacao = (rand() % 32) + 1980;
}

void ano_modelo(int **ptr_modelo)
{
    srand(time(NULL));
    **ptr_modelo = (rand() % 33) + 1980;
}

void combustivel(char *ptr_combustivel)
{
    srand(time(NULL));
    char aux_combustivel[4][100] = {"alcool", "disel", "flex", "disel"};
    int a = rand() % 3;
    strcpy(ptr_combustivel, aux_combustivel[a]);
}

void opcional(char *ptr_opcional)
{
    srand(time(NULL));
    int a = rand() % 7;
    strcpy(ptr_opcional, opcionais[a]);
}

void preco(float **ptr_preco)
{
    srand(time(NULL));
    float a = rand() % 30;
    **ptr_preco = a * 1000;
}

int salvar_carro()
{
    int a = 0;
    printf("\ndeseja salvar o carro?(0-nao,1-sim)\n");
    scanf("%d", &a);
    return (a);
}

void gerar_carro_valido(char *ptr_placa, char *ptr_modelo, char *ptr_fabricante, int *ptr_ano_fabrica, int *ptr_ano_modelo, char *ptr_combustivel, char *ptr_opcial, float *ptr_preco)
{
    int salvar = 0;
    gerar_placa(ptr_placa);
    gerar_modelo(ptr_modelo);
    gerar_fabricante(ptr_fabricante);
    ano_fabricacao(&ptr_ano_fabrica);
    ano_modelo(&ptr_ano_modelo);
    combustivel(ptr_combustivel);
    opcional(ptr_opcial);
    preco(&ptr_preco);

    printf("\nPLACA: %s\n", ptr_placa);
    printf("MODELO: %s\n", ptr_modelo);
    printf("FABRICANTE: %s\n", ptr_fabricante);
    printf("ANO DE FABRICA: %d\n", *ptr_ano_fabrica);
    printf("ANO DE MODELO: %d\n", *ptr_ano_modelo);
    printf("TIPO DE COMBUSTIVEL: %s\n", ptr_combustivel);
    printf("ITEM OPCINAL: %s\n", ptr_opcial);
    printf("PRECO: %.2f\n", *ptr_preco);

    salvar = salvar_carro();
    if (salvar == 1)
    {
        system("cls");
        printf("\nCARRO SALVO\n");
        strcpy(CARRO.placa, ptr_placa);
        strcpy(CARRO.modelo, ptr_modelo);
        strcpy(CARRO.fabricante, ptr_fabricante);
        CARRO.ano_fabricacao = *ptr_ano_fabrica;
        CARRO.ano_modelo = *ptr_ano_modelo;
        strcpy(CARRO.combustivel, ptr_combustivel);
        strcpy(CARRO.opcional, ptr_opcial);
        CARRO.preco_compra = *ptr_preco;
        system("pause");
    }
    else
    {
        system("cls");
        printf("\ncarro descartado\n");
        system("pause");
    }
}

int main()
{
    system("cls");
    int ano_fabrica = 0;
    char placa[9];
    char modelo[100];
    char fabricante[100];
    char combustivel[TAM];
    char opcional[TAM];
    int ano_modelo = 0;
    float preço = 0;
    gerar_carro_valido(placa, modelo, fabricante, &ano_fabrica, &ano_modelo, combustivel, opcional, &preço);


    printf("%s",CARRO.placa);

    return 0;
}
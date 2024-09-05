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
};

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
};

struct VENDA_CARRO
{
    char placa_car[9];
    char cpf_cli[15];
    float preco_venda;
    struct DATA data_venda;
};

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

int DDD()
{
    // Distrito Federal (61)
    // Goiás (62 e 64)
    // Mato Grosso (65 e 66)
    // Mato Grosso do Sul (67)

    srand(time(NULL));

    int a = rand() % 6;
    int ddd[6] = {61, 62, 64, 65, 66, 67};

    return (ddd[a]);
}

void gerar_tele_movel(char *ptr_telefone, int modificador)
{

    srand(time(NULL));
    int telefone_int[14]; // sem -
    int ddd = DDD();
    // inserir o DDD nos dois primeiros valores
    telefone_int[0] = ddd / 10;
    ddd = ddd - telefone_int[0] * 10;
    telefone_int[1] = ddd;

    for (int i = 2; i < 14; i++)
    {
        do
        {
            telefone_int[i] = rand() % 9 + modificador;
            if (telefone_int[i] > 9)
            {
                telefone_int[i] -= 2;
            }

        } while (telefone_int[i] > 9);
    }

    telefone_int[2] = 9;

    for (int i = 0; i < 14; i++)
    {
        if (i == 7)
        {
            ptr_telefone[7] = 45; // valor de - na tabela asc
        }
        else
        {
            ptr_telefone[i] = conversor_char(telefone_int[i]);
        }
    }
    ptr_telefone[13] = '\0';
    ptr_telefone[2] = 32;
}

void gerar_nome_principal(char *ptr_principal)
{
    srand(time(NULL));

    char nome_1[20] = {"Jose"};
    char nome_2[20] = {"Max"};
    char nome_3[20] = {"Leo"};

    int a = rand() % 2;

    if (a == 0)
    {
        strcpy(ptr_principal, nome_1);
    }
    else if (a == 1)
    {
        strcpy(ptr_principal, nome_2);
    }
    else if (a == 2)
    {
        strcpy(ptr_principal, nome_3);
    }
}

void gerar_sobrenome(char *ptr_sobrenome)
{
    srand(time(NULL));
    char nome_1[20] = {"Gabriel"};
    char nome_2[20] = {"Ogawa"};
    char nome_3[20] = {"Delboni"};
    int a = rand() % 2;

    if (a == 0)
    {
        strcpy(ptr_sobrenome, nome_1);
    }
    else if (a == 1)
    {
        strcpy(ptr_sobrenome, nome_2);
    }
    else if (a == 2)
    {
        strcpy(ptr_sobrenome, nome_3);
    }
}

void gerar_nome_valido(char *ptr_nome)
{
    char nome_principal[11];
    char nome_sobrenome[11];
    char finalizador[3] = "\0";

    gerar_nome_principal(nome_principal);
    gerar_sobrenome(nome_sobrenome);

    strcpy(ptr_nome, nome_principal);
    strcat(ptr_nome, " ");
    strcat(ptr_nome, nome_sobrenome);
    strcat(ptr_nome, finalizador);
}

void gerar_rua(char *ptr_rua)
{
    srand(time(NULL));
    int a = 0;
    char rua_1[20] = "São pedro\0";
    char rua_2[20] = "Brigadeiro\0";
    char rua_3[20] = "Antonio Emilio\0";

    a = rand() % 3;

    if (a == 2)
    {
        strcpy(ptr_rua, rua_1);
    }
    else if (a == 1)
    {
        strcpy(ptr_rua, rua_2);
    }
    else if (a == 0)
    {
        strcpy(ptr_rua, rua_3);
    }
}

void gerar_bairro(char *ptr_bairro)
{
    srand(time(NULL));
    char bairro_1[20] = "Santo Antonio\0";
    char bairro_2[20] = "Centro\0";
    char bairro_3[20] = "Santa catarina\0";

    int a = rand() % 3;

    if (a == 2)
    {
        strcpy(ptr_bairro, bairro_1);
    }
    else if (a == 1)
    {
        strcpy(ptr_bairro, bairro_2);
    }
    else if (a == 0)
    {
        strcpy(ptr_bairro, bairro_3);
    }
}

void gerar_estado(char *ptr_estado)
{
    srand(time(NULL));
    char estado_1[20] = "Mato Grosso\0";
    char estado_2[20] = "Mato Grosso do Sul\0";
    char estado_3[20] = "Ceara\0";

    int a = rand() % 3;

    if (a == 2)
    {
        strcpy(ptr_estado, estado_1);
    }
    else if (a == 1)
    {
        strcpy(ptr_estado, estado_2);
    }
    else if (a == 0)
    {
        strcpy(ptr_estado, estado_3);
    }
}

void gerar_cidade(char *ptr_cidade)
{
    srand(time(NULL));
    char cidade_1[20] = "Campo grande\0";
    char cidade_2[20] = "Cuiabá\0";
    char cidade_3[20] = "Fortaleza\0";

    int a = rand() % 3;

    if (a == 2)
    {
        strcpy(ptr_cidade, cidade_1);
    }
    else if (a == 1)
    {
        strcpy(ptr_cidade, cidade_2);
    }
    else if (a == 0)
    {
        strcpy(ptr_cidade, cidade_3);
    }
}

void gerar_cep_valido(char *ptr_cep)
{
    srand(time(NULL));
    int cep_int[10];

    for (int i = 0; i < 10; i++)
    {
        cep_int[i] = rand() % 10;
    }

    for (int i = 0; i < 10; i++)
    {
       
        if (i == 6)
        {
            ptr_cep[6] = 45;
        }
        else
        {

            ptr_cep[i] = conversor_char(cep_int[i]);
        }
    }
     ptr_cep[2] = 46;
}

int gera_numero_casa()
{
    srand(time(NULL));
    int a = rand() % 727;
    return (a);
}

int obtem_primeiro_digito_verificador(char cpf[])
{

    // recebe uma STRING com uma sequencia de caracteres e calcula o primeiro digito verificador do CPF
    int digito;
    int i = 0;
    int j = 1;
    int div = 0;
    int cpf_int[11];
    int soma = 0;
    for (i = 0; i < 9; i++)
    {
        cpf_int[i] = conversor_int(cpf[i]); // converter STRING em um vetor para fazer os calculos
    }
    // logica do calculo do D1
    for (i = 0; i < 9; i++) // percorre os primeiros 9 digitos
    {
        soma += cpf_int[i] * j; // soma e multiplica eles sequencialmente de 1 a 10
        j++;                    // variavel contadora para soma
    }
    div = (soma * 10) % 11; // Variavel DIV recebe modulo de 10 vezes a soma
    if (div < 2)
    {
        digito = 0; // caso resto seja menor que 2 o D1 é 0
    }
    else
    {
        digito = 11 - div; // caso div >=2 o d1 é o resto de 11 menos o div
    }
    return (digito);
}

int obtem_segundo_digito_verificador(char cpf[])
{
    // recebe uma STRING com uma sequencia de caracteres e calcula o primeiro digito verificador do CPF.
    int digito;
    int i = 0;
    int j = 0;
    int div = 0;
    int cpf_int[11];
    int soma = 0;
    for (i = 0; i < 10; i++)
    {
        cpf_int[i] = conversor_int(cpf[i]); // converte a STRING em um vetor para os calculos.
    }

    // procedimento do calculo do D2.

    for (i = 0; i < 10; i++) // percorre os 10 digitos do cpf.
    {
        soma += cpf_int[i] * j; // soma e multiplica o valor do cpf sequencialmente de 0 a 10.
        j++;                    // variavel contadora da multiplicação.
    }
    div = (soma * 10) % 11; // div recebe o modulo de 10 vezes a soma total.
    if (div < 2)
    {
        digito = 0; // caso div <2 d2 recebe 0.
    }
    else
    {
        digito = 11 - div; // caso div >=2 d2 recebe 11 - div.
    }
    return (digito);
}
// objetivo:verifica se um cpf no formato 999.999.999-99 e valido
// parametros: cpf a ser verificado
// retorno: 1 se cpf e valido ou 0 se cpf nao e valido

void gera_cpf_valido(char cpf[])
{
    srand(time(NULL));
    int cpf_int[11];
    char cpf_char[12];
    int i = 0;
    int digito = 0;

    // randomizar  9 numeros.
    for (i = 0; i < 9; i++)
    {
        cpf_int[i] = rand() % 10;
    }

    // converte para CPF em CHAR.
    for (i = 0; i < 9; i++)
    {
        cpf_char[i] = conversor_char(cpf_int[i]);
    }
    // pega d1
    digito = obtem_primeiro_digito_verificador(cpf_char);
    // insere o D1 no vetor do CPF.
    cpf_int[9] = digito;

    // converte novo CPF para char.

    for (i = 0; i < 10; i++)
    {
        cpf_char[i] = conversor_char(cpf_int[i]);
    }

    // acha D2.
    digito = obtem_segundo_digito_verificador(cpf_char);
    // insere o D2.
    cpf_int[10] = digito;
    for (i = 0; i < 11; i++) // Converte o vetor do CPF valido em um CHAR e inseri na STRING selecionada.
    {
        cpf[i] = conversor_char(cpf_int[i]);
    }
}

void gerar_salario(float *ptr_salario)
{
    srand(time(NULL));
    *ptr_salario = rand() % 10 * 1000;
}

void gerar_telefone_fixo(char *ptr_tele_fixo)
{
    srand(time(NULL));
    int telefone_int[14]; // sem -
    int ddd = DDD();
    // inserir o DDD nos dois primeiros valores
    telefone_int[0] = ddd / 10;
    ddd = ddd - telefone_int[0] * 10;
    telefone_int[1] = ddd;

    for (int i = 2; i < 14; i++)
    {

        telefone_int[i] = rand() % 9;
    }

    telefone_int[2] = 3;
    telefone_int[3] = 3;

    for (int i = 0; i < 14; i++)
    {

        if (i == 8)
        {
            ptr_tele_fixo[i] = 45; // valor de - na tabela asc
        }
        else
        {
            ptr_tele_fixo[i] = conversor_char(telefone_int[i]);
        }
    }
    ptr_tele_fixo[2] = 32;
    ptr_tele_fixo[13] = '\0';
}
void gerar_cliente_valido()
{
    // aux
    srand(time(NULL));
    int b = 0;
    int a = rand() % 5 + 1;
    int cont = 0;

    // client
    char nome[TAM];
    char cpf[15];

    // endereço

    char rua[TAM];
    int numero;
    char bairro[TAM];
    char cidade[TAM];
    char estado[3];
    char cep[11];

    // telefone

    char tele_fixo[14];
    char telfone[5][100];

    if (a > 5)
    {
        a--;
    }
    for (int i = 0; i < a; i++)
    {
        gerar_tele_movel(telfone[i], cont);
        cont++;
    }

    // salario

    float salario = 0;

    gerar_nome_valido(nome);
    gera_cpf_valido(cpf);
    gera_numero_casa(&numero);
    gerar_bairro(bairro);
    gerar_cidade(cidade);
    gerar_estado(estado);
    gerar_cep_valido(cep);
    gerar_rua(rua);
    gerar_salario(&salario);
    gerar_telefone_fixo(tele_fixo);

    printf("\n\n%s\n\n",cep);

    printf("DESEJA ADD?\n");
    scanf("%d", &b);

    if (b == 1)
    {
        system("cls");
        printf("CLIENT ADICIONADO NO CADRASTO\n");
        // add na struct
        strcpy(CLIENTE.nome, nome);
        strcpy(CLIENTE.cpf, cpf);
        strcpy(CLIENTE.endereco.cep, cep);
        strcpy(CLIENTE.endereco.bairro, bairro);
        strcpy(CLIENTE.endereco.cidade, cidade);
        strcpy(CLIENTE.endereco.estado, estado);
        CLIENTE.endereco.numero = numero;
        strcpy(CLIENTE.endereco.rua, rua);

        for (int i = 0; i < a; i++)
        {
            strcpy(CLIENTE.celular[i].telefone, telfone[i]);
        }
    }
    else
    {
        system("cls");
        printf("CLIENTE EXCLUIDO\n");
        system("pause");
    }
}

int main()
{
    gerar_cliente_valido();

    return 0;
}
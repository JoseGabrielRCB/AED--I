#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
};

struct TELEFONE
{
    char telefone[14]; // 99 99999-9999
};

struct CLIENTE
{
    char nome[TAM];
    char cpf[15]; // 999.999.999-99
    struct ENDERECO endereco;
    struct TELEFONE residencial;
    struct TELEFONE celular[5];
    float renda_mensal;
};

struct SUB_DADOS_VENDA
{
    char placa[9];
    char nome[TAM];
    char modelo[TAM];
    char fabricante[TAM];
};

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

void limpa()
{
#ifdef _WIN32 // Caso o usuario esteja rodando o codigo no windows
    system("cls");
#else // Caso o usuario esteja rodando o codigo em algum sistema operacional que nao seja o windows
    system("clear");
#endif
}

void pause()
{
#ifdef _WIN32 // Caso o usuario esteja rodando o codigo no windows
    system("pause");
#else // Caso o usuario esteja rodando o codigo em algum sistema operacional que nao seja o windows
    system("read -p \"Pressione entre para continuar . . .\" saindo");
#endif
}

void err(char text[])
{
    limpa();
    printf("[ERRO] %s\n\n", text);
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

int quantRegistro(char diretorio[], int local)
{
    int cont = 0;
    struct CARRO carro;
    struct CLIENTE cliente;
    struct VENDA_CARRO venda;
    FILE *arq;
    arq = fopen(diretorio, "rb");
    if (local == 1)
    {
        while (fread(&carro, sizeof(carro), 1, arq) == 1)
        {
            cont++;
        }
    }
    else if (local == 2)
    {
        while (fread(&cliente, sizeof(cliente), 1, arq) == 1)
        {
            cont++;
        }
    }
    else if (local == 3)
    {
        while (fread(&venda, sizeof(venda), 1, arq) == 1)
        {
            cont++;
        }
    }
    fclose(arq);
    return cont;
}

int tamNum(int num)
{
    int tam = 0;
    while (num != 0)
    {
        tam++;
        num /= 10;
    }
    return tam;
}

int verif(char ent[])
{
    int tam = strlen(ent);
    int conf = 0;
    for (int i = 0; i < tam; i++)
    {
        if (isdigit(ent[i]) > 0)
        {
            conf++;
        }
    }
    if (conf == tam)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Carro
void gerar_placa(char ptr_placa[])
{
    srand(time(NULL));
    char placa[9];
    char num_char[5];

    for (int i = 0; i < 3; i++)
    {
        placa[i] = (rand() % 26) + 65;
        num_char[i] = (rand() % 10) + 48;
    }
    num_char[3] = (rand() % 10) + 48;
    strcat(placa, "-");
    strcat(placa, num_char);
    strcpy(ptr_placa, placa);
}

void gerar_modelo(char ptr_modelo[])
{
    srand(time(NULL));
    char modelos[4][100] = {"Celta", "Gol", "Sorento", "Uno"};
    int a = rand() % 4;

    strcpy(ptr_modelo, modelos[a]);
}

void gerar_fabricante(char ptr_fabricante[])
{
    srand(time(NULL));
    char fabricantes[4][100] = {"Ferrari", "Honda", "Kia", "Lamborghini"};
    int a = rand() % 4;

    strcpy(ptr_fabricante, fabricantes[a]);
}

void gerar_combustivel(char ptr_combustivel[])
{
    srand(time(NULL));
    char aux_combustivel[4][100] = {"Alcool", "Disel", "Etanol", "Flex"};
    int a = rand() % 4;
    strcpy(ptr_combustivel, aux_combustivel[a]);
}

void gerar_cor(char ptr_cor[])
{
    srand(time(NULL));
    char aux_cor[4][100] = {"Vermelho", "Amarelo", "Azul", "Verde"};
    int a = rand() % 4;
    strcpy(ptr_cor, aux_cor[a]);
}

int opcional(int opicionais[])
{
    srand(time(NULL));
    int quantOpc = (rand() % 8) + 1;
    int quant = 0, conf = 0;
    int num;

    for (int i = 0; i < quantOpc; i++)
    {
        num = rand() % 8;
        for (int j = 0; j < quant; j++)
        {
            if (opicionais[j] == num)
            {
                conf = 1;
            }
        }
        if (conf != 1)
        {
            opicionais[i] = num;
            quant++;
        }
        else
        {
            conf = 0;
            i--;
        }
    }
    for (int i = quantOpc; i < 8; i++)
    {
        opicionais[i] = -1;
    }

    return quantOpc;
}

void infDadosCarro(struct CARRO carro)
{
    printf("Placa: %s\n", carro.placa);
    printf("Modelo: %s\n", carro.modelo);
    printf("Fabricante: %s\n", carro.fabricante);
    printf("Ano de Fabricacao: %d\n", carro.ano_fabricacao);
    printf("Ano Modelo: %d\n", carro.ano_modelo);
    printf("Combustivel: %s\n", carro.combustivel);
    printf("Cor: %s\n", carro.cor);
    printf("Opcional: ");
    int conf = 0, i = 0;
    while (conf == 0)
    {
        if (carro.opcional[i + 1] == -1 || i == 7)
        {
            printf("%s", opcionais[carro.opcional[i]]);
            conf = 1;
        }
        else
        {
            printf("%s, ", opcionais[carro.opcional[i]]);
            i++;
        }
    }
    printf("\nPRECO: %.2f\n", carro.preco_compra);
    printf("------------------------------------------------------------------------------\n");
}

void ordValores(int quant, int valores[quant][2])
{
    int cont = 0;
    int auxPos, auxVal;
    int j = 0;
    while (cont != quant - 1)
    {
        if (valores[j][1] > valores[j + 1][1])
        {
            auxPos = valores[j][0];
            auxVal = valores[j][1];
            valores[j][0] = valores[j + 1][0];
            valores[j][1] = valores[j + 1][1];
            valores[j + 1][0] = auxPos;
            valores[j + 1][1] = auxVal;
            cont = 0;
            j = 0;
        }
        else
        {
            cont++;
            j++;
        }
    }
}

void ordValores_float(int quant, float valores[quant][2])
{
    int cont = 0;
    int auxPos, auxVal;
    int j = 0;
    while (cont != quant - 1)
    {
        if (valores[j][1] > valores[j + 1][1])
        {
            auxPos = valores[j][0];
            auxVal = valores[j][1];
            valores[j][0] = valores[j + 1][0];
            valores[j][1] = valores[j + 1][1];
            valores[j + 1][0] = auxPos;
            valores[j + 1][1] = auxVal;
            cont = 0;
            j = 0;
        }
        else
        {
            cont++;
            j++;
        }
    }
}
int gerar_carro_valido(struct CARRO *carro)
{
    srand(time(NULL));
    char placa[9];
    char modelo[100];
    char fabricante[100];
    int ano_fabrica = 0;
    int ano_modelo = 0;
    char combustivel[TAM];
    char cor[TAM];
    int valoresOpc[8];
    float preco = 0;
    char opc[500];

    int salvar = 0;

    gerar_placa(placa);
    gerar_modelo(modelo);
    gerar_fabricante(fabricante);
    ano_fabrica = (rand() % 37) + 1980;
    while (ano_modelo < ano_fabrica)
        ano_modelo = (rand() & 38) + 1980;
    gerar_combustivel(combustivel);
    gerar_cor(cor);
    int quant = opcional(valoresOpc);
    strcpy(opc, opcionais[valoresOpc[0]]);
    strcat(opc, ", ");
    for (int i = 1; i < quant; i++)
    {
        if (i != quant - 1)
        {
            strcat(opc, opcionais[valoresOpc[i]]);
            strcat(opc, ", ");
        }
        else
        {
            strcat(opc, opcionais[valoresOpc[i]]);
        }
    }
    preco = ((rand() % 80) + 1) * 1000.0;

    printf("Placa: %s\n", placa);
    printf("Modelo: %s\n", modelo);
    printf("Fabricante: %s\n", fabricante);
    printf("Ano de Fabricacao: %d\n", ano_fabrica);
    printf("Ano Modelo: %d\n", ano_modelo);
    printf("Combustivel: %s\n", combustivel);
    printf("Cor: %s\n", cor);
    printf("Opcional: %s\n", opc);
    printf("PRECO: %.2f\n", preco);

    printf("\nDeseja salvar o carro?\n1 - Sim\n0 - Nao\n");
    char val[2];
    scanf("%s", val);
    if (verif(val) == 1)
    {
        salvar = atoi(val);
        if (salvar == 1)
        {
            limpa();
            strcpy(carro->placa, placa);
            strcpy(carro->modelo, modelo);
            strcpy(carro->fabricante, fabricante);
            carro->ano_fabricacao = ano_fabrica;
            carro->ano_modelo = ano_modelo;
            strcpy(carro->combustivel, combustivel);
            strcpy(carro->cor, cor);
            for (int i = 0; i < 8; i++)
                carro->opcional[i] = valoresOpc[i];
            carro->preco_compra = preco;
            return 1;
        }
        else if (salvar == 0)
        {
            limpa();
            printf("Carro nao cadastrado.");
            return 0;
        }
        else
        {
            err("Valor inserido invalido! Carro nao cadastrado.");
            return 0;
        }
    }
    else
    {
        err("Valor inserido invalido! Carro nao cadastrado.");
        return 0;
    }
}

int verFabMod(char val[], int tipo)
{
    int num;
    if (tipo == 0)
    {
        if (strcmp(val, "Ferrari") == 1)
            num = 0;
        else if (strcmp(val, "Honda") == 1)
            num = 1;
        else if (strcmp(val, "Kia") == 1)
            num = 2;
        else if (strcmp(val, "Lamborghini") == 1)
            num = 3;
    }
    else if (tipo == 1)
    {
        if (strcmp(val, "Celta") == 1)
            num = 0;
        else if (strcmp(val, "Gol") == 1)
            num = 1;
        else if (strcmp(val, "Sorento") == 1)
            num = 2;
        else if (strcmp(val, "Uno") == 1)
            num = 3;
    }
    return num;
}

void ordMod(int quant, int valores[quant][3])
{
    int temp[3];

    for (int i = 0; i < quant - 1; i++)
    {
        for (int j = i + 1; j < quant; j++)
        {
            if (valores[i][1] > valores[j][1] || (valores[i][1] == valores[j][1] && valores[i][2] > valores[j][2]))
            {
                // Trocar as posições
                for (int k = 0; k < 3; k++)
                {
                    temp[k] = valores[i][k];
                    valores[i][k] = valores[j][k];
                    valores[j][k] = temp[k];
                }
            }
        }
    }
}
// Carro

// Cliente
void infDadosCliente(struct CLIENTE CLIENTE)
{
    printf("Nome: %s\n", CLIENTE.nome);
    printf("Cpf: %s\n", CLIENTE.cpf);
    printf("Endereco: \n");
    printf("    Rua: %s\n", CLIENTE.endereco.rua);
    printf("    Numero: %d\n", CLIENTE.endereco.numero);
    printf("    Bairro: %s\n", CLIENTE.endereco.bairro);
    printf("    Cidade: %s\n", CLIENTE.endereco.cidade);
    printf("    Estado: %s\n", CLIENTE.endereco.estado);
    printf("    Cep: ");
    for (int i = 0; i < 10; i++)
        printf("%c", CLIENTE.endereco.cep[i]);
    printf("\nTelefone Residencial: %s\n", CLIENTE.residencial.telefone);
    printf("Celular: ");
    for (int i = 0; i < 5; i++)
    {
        if (CLIENTE.celular[i + 1].telefone[0] == '0' || i == 4)
        {
            printf("\"%s\"\n", CLIENTE.celular[i].telefone);
            i = 5;
        }
        else
        {
            printf("\"%s\", ", CLIENTE.celular[i].telefone);
        }
    }
    printf("Renda mensal: %.2f\n", CLIENTE.renda_mensal);
    printf("------------------------------------------------------------------------------\n");
}

int cmpCpf(char cpf[], char cpfIns[])
{
    if (strlen(cpf) == strlen(cpfIns))
    {
        int cont = 0;
        for (size_t i = 0; i < strlen(cpf); i++)
        {
            if (cpf[i] == cpfIns[i])
                cont++;
        }
        if (cont == (int)strlen(cpf))
            return 1;
        else
            return 0;
    }
    else
    {
        return 0;
    }
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

void gerar_nome_valido(char *ptr_nome)
{
    char nomes[][20] = {"Jose", "Max", "Leonardo"};
    char sobrenomes[][20] = {"Gabriel", "Ogawa", "Delboni"};

    srand(time(NULL));
    int a = rand() % 3;
    int b = rand() % 3;

    strcpy(ptr_nome, nomes[a]);
    strcat(ptr_nome, " ");
    strcat(ptr_nome, sobrenomes[b]);
    strcat(ptr_nome, "\0");
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
        if (i == 2)
            ptr_cep[2] = 46;
        else if (i == 6)
            ptr_cep[6] = 45;
        else
            ptr_cep[i] = cep_int[i] + 48;
    }
}

// int casa,char rua,char bairro,char estado,char cidade,char cep
void gerar_endereço_valido(int *ptr_numero_casa, char *ptr_rua, char *ptr_bairro, char *ptr_estado, char *ptr_cidade, char *ptr_cep)
{
    char ruas[][20] = {"Sao pedro\0", "Brigadeiro\0", "Antonio Emilio\0"};
    char bairros[][20] = {"Santo Antonio\0", "Centro\0", "Santa catarina\0"};
    char estados[][20] = {"MT\0", "MS\0", "CA\0"};
    char cidades[][20] = {"Campo grande\0", "Cuiaba\0", "Fortaleza\0"};
    int numRand[4];

    srand(time(NULL));
    for (int i = 0; i < 4; i++)
        numRand[i] = rand() % 3;

    *ptr_numero_casa = rand() % 727;
    strcpy(ptr_rua, ruas[numRand[0]]);
    strcpy(ptr_bairro, bairros[numRand[1]]);
    strcpy(ptr_estado, estados[numRand[2]]);
    strcpy(ptr_cidade, cidades[numRand[3]]);
    gerar_cep_valido(ptr_cep);
    strcat(ptr_cep, "\0");
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
    int j = 0;
    for (i = 0; i < 14; i++) // Converte o vetor do CPF valido em um CHAR e inseri na STRING selecionada.
    {
        if (i == 3 || i == 7)
        {
            cpf[i] = 46;
        }
        else if (i == 11)
        {
            cpf[i] = 45;
        }
        else
        {
            cpf[i] = conversor_char(cpf_int[j]);
            j++;
        }
    }
}

void gerar_salario(float *ptr_salario)
{
    srand(time(NULL));
    *ptr_salario = (rand() % 10) * 1000;
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

void gerar_cliente_valido(struct CLIENTE *CLIENTE)
{
    // aux
    srand(time(NULL));
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
    char cep[15];

    // telefone

    char tele_fixo[14];
    char telfone[5][100];

    for (int i = 0; i < a; i++)
    {
        gerar_tele_movel(telfone[i], cont);
        cont++;
    }
    for (int i = a; i < 5; i++)
        telfone[i][0] = 'a';

    // salario

    float salario = 0;

    gerar_nome_valido(nome);
    gera_cpf_valido(cpf);
    gerar_endereço_valido(&numero, rua, bairro, estado, cidade, cep);
    salario = (rand() % 10) * 1000;
    gerar_telefone_fixo(tele_fixo);

    limpa();
    // add na struct
    strcpy(CLIENTE->nome, nome);
    strcpy(CLIENTE->cpf, cpf);
    strcpy(CLIENTE->endereco.rua, rua);
    CLIENTE->endereco.numero = numero;
    strcpy(CLIENTE->endereco.bairro, bairro);
    strcpy(CLIENTE->endereco.cidade, cidade);
    strcpy(CLIENTE->endereco.cep, cep);
    strcpy(CLIENTE->endereco.estado, estado);
    CLIENTE->renda_mensal = salario;
    strcpy(CLIENTE->residencial.telefone, tele_fixo);
    for (int i = 0; i < a; i++)
    {
        strcpy(CLIENTE->celular[i].telefone, telfone[i]);
    }
    for (int i = a; i < 5; i++)
    {
        CLIENTE->celular[i].telefone[0] = '0';
    }
}
// Cliente

// Venda
int realizaVenda(char diretorios[4][20], int quantCarro, int quantCliente, int posCarro, int posCliente, struct CARRO carros[quantCarro], struct CLIENTE clientes[quantCliente])
{
    srand(time(NULL));
    char val[2];
    int conf = -1;
    printf("Cliente e carro localizados, deseja prosseguir com a venda?\n1 - Sim\n0 - Nao\n");
    scanf("%s", val);
    if (verif(val) == 1)
    {
        conf = atoi(val);
        if (conf == 1)
        {
            struct VENDA_CARRO venda;
            strcpy(venda.placa_car, carros[posCarro].placa);
            strcpy(venda.cpf_cli, clientes[posCliente].cpf);
            venda.preco_venda = carros[posCarro].preco_compra;
            venda.data_venda.mes = (rand() % 12) + 1;
            if (venda.data_venda.mes != 2)
                venda.data_venda.dia = (rand() % 28) + 1;
            else
                venda.data_venda.dia = (rand() % 30) + 1;
            venda.data_venda.ano = (rand() % 43) + 1980;

            struct SUB_DADOS_VENDA subDados;
            strcpy(subDados.placa, carros[posCarro].placa);
            strcpy(subDados.placa, clientes[posCliente].nome);
            strcpy(subDados.modelo, carros[posCarro].modelo);
            strcpy(subDados.fabricante, carros[posCarro].fabricante);

            FILE *arqVenda;
            arqVenda = fopen(diretorios[2], "ab");
            fwrite(&venda, sizeof(venda), 1, arqVenda);
            fclose(arqVenda);

            FILE *arqSubVenda;
            arqSubVenda = fopen(diretorios[3], "ab");
            fwrite(&subDados, sizeof(subDados), 1, arqSubVenda);
            fclose(arqSubVenda);

            FILE *arqCarro;
            arqCarro = fopen(diretorios[0], "wb");
            for (int i = 0; i < quantCarro; i++)
            {
                if (i != posCarro)
                    fwrite(&carros[i], sizeof(carros[i]), 1, arqCarro);
            }
            fclose(arqCarro);

            printf("Venda realizada com sucesso.\n\n");
            return 1;
        }
        else if (conf == 2)
        {
            printf("Venda cancelada\n\n");
            return 0;
        }
        else
        {
            err("Valor inserido invalido! Venda cancelada.");
            return 0;
        }
    }
    else
    {
        err("Valor inserido invalido! Venda cancelada.");
        return 0;
    }
}

void norm(char text[])
{
    int quant = strlen(text);
    char str[quant];
    strcpy(str, text);
    for (int i = 0; i < quant; i++)
    {
        if (i == 0)
            text[i] = toupper(str[i]);
        else
            text[i] = tolower(str[i]);
    }
}
// Venda

void menuCarro(char diretorio[])
{
    char ent[2];
    int escolha = -1;
    while (escolha != 0)
    {
        printf("Escolha uma das opcoes:\n");
        printf("1 - Inserir um carro no cadastro\n");
        printf("2 - Excluir um carro do cadastro\n");
        printf("3 - Listar os carros disponiveis para a venda ordenados crescentemente por fabricante e modelo\n");
        printf("4 - Listar os carros disponiveis para a venda por selecao de um ou mais opcionais\n");
        printf("5 - Listar os carros disponiveis para a venda por selecao da faixa de ano de fabricacao\n");
        printf("0 - Voltar para o menu principal\n");
        scanf("%s", ent);
        if (verif(ent) == 1)
        {
            escolha = atoi(ent);
            if (escolha == 1)
            { // Inserir um carro no cadastro
                struct CARRO carro;
                int conf = gerar_carro_valido(&carro);
                if (conf == 1)
                {
                    FILE *arq;
                    arq = fopen(diretorio, "ab");
                    fwrite(&carro, sizeof(carro), 1, arq);
                    fclose(arq);
                    limpa();
                    printf("Carro cadastrado com sucesso\n\n");
                }
            }
            else if (escolha == 2)
            { // Excluir um carro no cadastro
                int quant = quantRegistro(diretorio, 1);
                if (quant > 0)
                {
                    FILE *arq;
                    arq = fopen(diretorio, "rb");
                    char val[TAM];
                    int pos = -1;
                    struct CARRO carro[quant];
                    printf("Digite a placa do carro que deseja excluir:\n");
                    scanf("%s", val);
                    for (int i = 0; i < quant; i++)
                    {
                        fread(&carro[i], sizeof(carro[i]), 1, arq);
                        if (strcmp(val, carro[i].placa) == 0)
                            pos = i;
                    }
                    fclose(arq);
                    if (pos >= 0)
                    {
                        arq = fopen(diretorio, "wb");
                        for (int i = 0; i < quant; i++)
                        {
                            if (i != pos)
                            {
                                fwrite(&carro[i], sizeof(carro[i]), 1, arq);
                            }
                        }
                        fclose(arq);
                        limpa();
                        printf("Exclusao sucedida.\n\n");
                    }
                    else
                    {
                        err("Nao ha nenhum carro cadastrado com a placa informada.");
                    }
                }
                else
                {
                    err("Nao ha nenhum registro cadastrado no sistema!");
                }
            }
            else if (escolha == 3)
            { // Listar em ordem por fabricante e modelo
                int quant = quantRegistro(diretorio, 1);
                if (quant > 0)
                {
                    struct CARRO carro[quant];
                    int valores[quant][3]; //[pos, fabricante, modelo]
                    FILE *arq;
                    arq = fopen(diretorio, "rb");
                    for (int i = 0; i < quant; i++)
                    {
                        fread(&carro[i], sizeof(carro[i]), 1, arq);
                        valores[i][0] = i;
                        valores[i][1] = verFabMod(carro[i].fabricante, 0);
                        valores[i][2] = verFabMod(carro[i].modelo, 1);
                    }
                    ordMod(quant, valores);
                    fclose(arq);

                    printf("------------------------------------------------------------------------------\n");
                    for (int i = 0; i < quant; i++)
                    {
                        infDadosCarro(carro[valores[i][0]]);
                    }
                    pause();
                    limpa();
                }
                else
                {
                    err("Nao ha nenhum registro cadastrado no sistema!");
                }
            }
            else if (escolha == 4)
            { // Listar em ordem por selecao de opcionais
                int quant = quantRegistro(diretorio, 1);
                if (quant > 0)
                {
                    FILE *arq;
                    arq = fopen(diretorio, "rb");
                    struct CARRO carro[quant];
                    int valores[quant][2]; //[pos, quant]
                    int cont = 0;
                    for (int i = 0; i < quant; i++)
                    {
                        fread(&carro[i], sizeof(carro[i]), 1, arq);
                        cont = 0;
                        for (int j = 0; j < 8; j++)
                        {
                            if (carro[i].opcional[j] != -1)
                                cont++;
                        }
                        valores[i][0] = i;
                        valores[i][1] = cont;
                    }
                    fclose(arq);
                    ordValores(quant, valores);
                    printf("------------------------------------------------------------------------------\n");
                    for (int i = 0; i < quant; i++)
                    {
                        infDadosCarro(carro[valores[i][0]]);
                    }
                    pause();
                    limpa();
                }
                else
                {
                    err("Nao ha nenhum registro cadastrado no sistema!");
                }
            }
            else if (escolha == 5)
            { // Listar em ordem de ano de fabricacao
                int quant = quantRegistro(diretorio, 1);
                if (quant > 0)
                {
                    FILE *arq;
                    arq = fopen(diretorio, "rb");
                    struct CARRO carro[quant];
                    int valores[quant][2]; //[pos, ano]
                    for (int i = 0; i < quant; i++)
                    {
                        fread(&carro[i], sizeof(carro[i]), 1, arq);
                        valores[i][0] = i;
                        valores[i][1] = carro[i].ano_fabricacao;
                    }
                    ordValores(quant, valores);
                    printf("------------------------------------------------------------------------------\n");
                    for (int i = 0; i < quant; i++)
                    {
                        infDadosCarro(carro[valores[i][0]]);
                    }
                    pause();
                    limpa();
                }
                else
                {
                    err("Nao ha nenhum registro cadastrado no sistema!");
                }
            }
            else if (escolha < 0 || escolha > 5)
            { // Caso o usuario insira um valor inexistente
                err("Valor inserido invalido!");
            }
        }
        else
        { // Caso o usuario digite um caractere ao inves de um numero
            err("Valor inserido invalido!");
        }
    }
}

void ordenaClientesPorNome(char diretorio[TAM])
{
    int quant = quantRegistro(diretorio, 2);

    if (quant > 0)
    {
        struct CLIENTE cliente_ordenado[quant];

        FILE *arq;
        arq = fopen(diretorio, "rb");

        fread(cliente_ordenado, sizeof(struct CLIENTE), quant, arq);
        fclose(arq);

        for (int i = 0; i < quant - 1; i++)
        {
            for (int j = 0; j < quant - i - 1; j++)
            {
                if (strcmp(cliente_ordenado[j].nome, cliente_ordenado[j + 1].nome) > 0)
                {
                    struct CLIENTE temp;
                    temp = cliente_ordenado[j];
                    cliente_ordenado[j] = cliente_ordenado[j + 1];
                    cliente_ordenado[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < quant; i++)
        {
            infDadosCliente(cliente_ordenado[i]);
        }
    }
}

void ordena_por_media_salarial(char diretorio[TAM])
{

    float auxiliar;
    int cont = 0; // auxiliariliar na inversão de valores

    // definar lmites da renda
    float Valor_maximo = 0;
    float Valor_minimo = 0;

    // entrada dos valores maximos e minimos das medias salarias desejadas

    printf("Informe a faixa salarial que deseja buscar.\n");
    printf("INFORME O VALOR MINIMO DA FAIXA SALARIAL:\n");
    scanf("%f", &Valor_minimo);
    printf("INFORME O VALOR MAXIMO DA FAIXA SALARIAL:\n");
    scanf("%f", &Valor_maximo);

    // faz uma inversão nos valores, caso usuario inverta os valores maximo e minimo

    if (Valor_maximo < Valor_minimo)
    {
        auxiliar = Valor_maximo;
        Valor_maximo = Valor_minimo;
        Valor_minimo = auxiliar;
    }

    FILE *arq = fopen(diretorio, "rb"); // abre o arquivo
    int quant = quantRegistro(diretorio, 2);
    struct CLIENTE cliente[quant];
    // primeiro valor posição / segunda renda salarial
    float valores[quant][2];
    if (quant > 0 && arq != NULL)
    {
        for (int i = 0; i < quant; i++)
        {
            fread(&cliente, sizeof(cliente), 1, arq);
            valores[i][0] = i;
            valores[i][1] = cliente[i].renda_mensal;
        }
        ordValores_float(quant, valores);
        int aux_1;
        for (int i = 0; i < quant; i++)
        {
            aux_1 = valores[i][0];
            if (cliente[aux_1].renda_mensal >= Valor_minimo && cliente[aux_1].renda_mensal <= Valor_maximo)
            {
                cont++;
                infDadosCliente(cliente[aux_1]);
            }
        }
        if (cont == 0)
        {
            printf("SEM CLIENTES NESTA FAIXA\n");
        }

        fclose(arq);
    }
    else
    {
        printf("Nao ha clientes registrados");
    }
}

void menuCliente(char diretorio[])
{
    char ent[2];
    int escolha = -1;
    printf("Escolha uma das opcoes:\n");
    printf("1 - Inserir um cliente no cadastro\n");
    printf("2 - Excluir um cliente do cadastro\n");
    printf("3 - Listar os clientes do cadastro ordenados crescentemente pelo nome\n");
    printf("4 - Listar os clientes do cadastro ordenados crescentemente pelo nome por seleção de faixa de renda salarial mensal\n");
    printf("0 - Voltar para o menu principal\n");
    scanf("%s", ent);
    if (verif(ent) == 1)
    {
        escolha = atoi(ent);
        if (escolha == 1)
        { // Inserir um cliente no cadastro
            struct CLIENTE cliente;
            gerar_cliente_valido(&cliente);
            printf("Nome: %s\n", cliente.nome);
            printf("Cpf: %s\n", cliente.cpf);
            printf("Endereco: \n");
            printf("    Rua: %s\n", cliente.endereco.rua);
            printf("    Numero: %d\n", cliente.endereco.numero);
            printf("    Bairro: %s\n", cliente.endereco.bairro);
            printf("    Cidade: %s\n", cliente.endereco.cidade);
            printf("    Estado: %s\n", cliente.endereco.estado);
            printf("    Cep: ");
            for (int i = 0; i < 10; i++)
                printf("%c", cliente.endereco.cep[i]);
            printf("\nTelefone Residencial: %s\n", cliente.residencial.telefone);
            printf("Celular: ");
            for (int i = 0; i < 5; i++)
            {
                if (cliente.celular[i + 1].telefone[0] == '0' || i == 4)
                {
                    printf("\"%s\"\n", cliente.celular[i].telefone);
                    i = 5;
                }
                else
                {
                    printf("\"%s\", ", cliente.celular[i].telefone);
                }
            }
            printf("Renda mensal: %.2f\n\n", cliente.renda_mensal);

            char val[2];
            int conf;
            printf("Deseja cadastrar o cliente?\n1 - Sim\n0 - Nao\n");
            scanf("%s", val);
            if (verif(val) == 1)
            {
                conf = atoi(val);
                if (conf == 1)
                {
                    FILE *arq;
                    arq = fopen(diretorio, "ab");
                    fwrite(&cliente, sizeof(cliente), 1, arq);
                    fclose(arq);
                    printf("Cliente cadastrado com sucesso.\n\n");
                }
                else if (conf == 0)
                {
                    printf("Cliente nao cadastrado.\n\n");
                }
                else
                {
                    err("Valor inserido invalido! Cliente nao cadastrado.");
                }
            }
            else
            {
                err("Valor inserido invalido! Cliente nao cadastrado.");
            }
            system("pause");
            system("cls");
        }
        else if (escolha == 2)
        { // Excluir um cliente do cadastro
            int quant = quantRegistro(diretorio, 2);
            if (quant > 0)
            {
                FILE *arq;
                arq = fopen(diretorio, "rb");
                char cpf[15];
                int pos = -1;
                printf("Digite o cpf da pessoa que deseje excluir do sistema, no formato: XXX.XXX.XXX-XX\n");
                scanf("%s", cpf);

                struct CLIENTE clientes[quant];
                for (int i = 0; i < quant; i++)
                {
                    fread(&clientes[i], sizeof(clientes[i]), 1, arq);
                    if (cmpCpf(clientes[i].cpf, cpf) == 1)
                        pos = i;
                }
                fclose(arq);
                if (pos >= 0)
                {
                    arq = fopen(diretorio, "wb");
                    for (int i = 0; i < quant; i++)
                    {
                        if (i != pos)
                            fwrite(&clientes[i], sizeof(clientes[i]), 1, arq);
                    }
                    fclose(arq);
                    limpa();
                    printf("Exclusao sucedida.\n\n");
                }
                else
                {
                    err("Nao ha nenhum cliente com o cpf informado cadastrado no sistema.");
                }
            }
            else
            {
                err("Nao ha nenhum registro cadastrado no sistema!");
            }
        }
        else if (escolha == 3)
        {

            ordenaClientesPorNome(diretorio);
        }

        else if (escolha == 4)
        { // Listar os clientes ordenados crescentemente pelo nome e por renda salarial mensal
            printf("CLIENTES POR NOME:\n");
            ordenaClientesPorNome(diretorio);
            printf("\n\n---------------------------------------\n\n");
            printf("CLIENTES POR FAIXA SALARIAL:\n");
            ordena_por_media_salarial(diretorio);
        }
        else if (escolha == 5)
        { //
            int quant = quantRegistro(diretorio, 2);
            FILE *arq;
            if (quant > 0)
            {
                struct CLIENTE clientes[quant];
                arq = fopen(diretorio, "rb");
                printf("------------------------------------------------------------------------------\n");
                for (int i = 0; i < quant; i++)
                {
                    fread(&clientes[i], sizeof(clientes[i]), 1, arq);
                    infDadosCliente(clientes[i]);
                }

                fclose(arq);
            }
            else
            {
                err("Nao ha nenhum cliente cadastrado no sistema!");
            }
        }
    }

    else if (escolha < 0 || escolha > 4)
    { // Caso o usuario digite um valor inexistente
        err("Valor inserido invalido!");
    }
}
// else
// { // Caso o usuario digite um caractere ao inves de um numero
//     err("Valor inserido invalido!");
// }

void menuVenda(char diretorios[4][20])
{
    char ent[2];
    int escolha = -1;
    while (escolha != 0)
    {
        printf("Escolha uma das opcoes:\n");
        printf("1 - Inserir uma venda\n");
        printf("2 - Excluir uma venda\n");
        printf("3 - Listar os carros vendidos de um determinado fabricante, ordenados crescentemente pelo modelo\n");
        printf("4 - Listar os carros vendidos de um determinado modelo, ordenados crescentemente pelo ano de fabricação \n");
        printf("5 - Informar a quantidade de carros vendidos com o valor totalizado dos preços vendidos\n");
        printf("6 - Informar o lucro total das vendas\n");
        printf("0 - Voltar para o menu principal\n");
        scanf("%s", ent);
        if (verif(ent) == 1)
        {
            escolha = atoi(ent);
            if (escolha == 1)
            { // Inserir uma venda
                int quantCarro = quantRegistro(diretorios[0], 1);
                int quantCliente = quantRegistro(diretorios[1], 2);
                if (quantCarro > 0 && quantCliente > 0)
                {
                    char cpf[15];
                    printf("Digite o cpf do cliente que deseja comprar o carro:\n");
                    scanf("%s", cpf);
                    FILE *arqCliente;
                    arqCliente = fopen(diretorios[1], "rb");
                    struct CLIENTE clientes[quantCliente];
                    int posCliente = -1;
                    for (int i = 0; i < quantCliente; i++)
                    {
                        fread(&clientes[i], sizeof(clientes[i]), 1, arqCliente);
                        if (cmpCpf(clientes[i].cpf, cpf) == 1)
                            posCliente = i;
                    }
                    fclose(arqCliente);
                    if (posCliente >= 0)
                    {
                        char placa[9];
                        printf("Digite a placa do carro que o cliente deseja comprar:\n");
                        scanf("%s", placa);
                        FILE *arqCarro;
                        arqCarro = fopen(diretorios[0], "rb");
                        struct CARRO carros[quantCarro];
                        int posCarro = -1;
                        for (int i = 0; i < quantCarro; i++)
                        {
                            fread(&carros[i], sizeof(carros[i]), 1, arqCarro);
                            if (strcmp(placa, carros[i].placa) == 0)
                                posCarro = i;
                        }
                        fclose(arqCarro);
                        if (posCarro >= 0)
                        {
                            realizaVenda(diretorios, quantCarro, quantCliente, posCarro, posCliente, carros, clientes);
                        }
                        else
                        {
                            err("Nao ha nenhum carro com a placa informada cadastrado no sistema.");
                        }
                    }
                    else
                    {
                        err("Nao ha nenhum cliente com o cpf informado cadastrado no sistema.");
                    }
                }
                else
                {
                    err("Nao ha dados suficientes cadastrados no sistema para performar uma venda!");
                }
            }
            else if (escolha == 2)
            { // Excluir uma venda
                char placa[9];
                printf("Digite a placa do carro que deseja excluir do registro de venda:\n");
                scanf("%s", placa);
                FILE *arqVenda;
                arqVenda = fopen(diretorios[2], "rb");

                fclose(arqVenda);
            }
            else if (escolha == 3)
            { // Listar os carros de um fabricante, ordenados pelo modelo
            }
            else if (escolha == 4)
            { // Listar os carros de um modelo, ordenados pelo ano de fabricacao
            }
            else if (escolha == 5)
            { // Informar a quantidade de carros vendidos e seu total
            }
            else if (escolha == 6)
            { // Informar o lucro total das vendas
            }
            else if (escolha < 0 || escolha > 6)
            {
                err("Valor inserido invalido!");
            }
        }
        else
        {
            err("Valor inserido invalido!");
        }
    }
}

int main()
{
    char diretorios[][20] = {"carro.bin", "cliente.bin", "venda.bin", "dadosVenda.bin"};
    char ent[2];
    int escolha = 0;
    while (escolha != 4)
    {
        printf("Escolha uma das opcoes:\n");
        printf("1 - Carro\n");
        printf("2 - Cliente\n");
        printf("3 - Venda\n");
        printf("4 - Sair do programa\n");
        scanf("%s", ent);
        if (verif(ent) == 1)
        {
            limpa();
            escolha = atoi(ent);
            if (escolha == 1)
            { // Carro
                menuCarro(diretorios[0]);
            }
            else if (escolha == 2)
            { // Cliente
                menuCliente(diretorios[1]);
            }
            else if (escolha == 3)
            { // Venda
                menuVenda(diretorios);
            }
            else if (escolha < 1 || escolha > 4)
            { // Valor inexistente
                err("Valor Inserido invalido!");
            }
        }
        else
        { // Valor com caracteres
            err("Valor inserido invalido!");
        }
    }
    return 0;
}
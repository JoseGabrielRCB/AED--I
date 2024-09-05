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
void ordenarCarrosPorFabricanteModelo(struct CARRO carros[], int quant)
{
    // Bubble sort
    for (int i = 0; i < quant - 1; i++)
    {
        for (int j = 0; j < quant - i - 1; j++)
        {
            if (strcmp(carros[j].fabricante, carros[j + 1].fabricante) > 0 || (strcmp(carros[j].fabricante, carros[j + 1].fabricante) == 0 && strcmp(carros[j].modelo, carros[j + 1].modelo) > 0))
            {
                // Troca os carros se estiverem fora de ordem
                struct CARRO temp = carros[j];
                carros[j] = carros[j + 1];
                carros[j + 1] = temp;
            }
        }
    }
}

void listarCarrosPorFabricanteModelo(char diretorio[])
{
    int quant = quantRegistro(diretorio, 1);

    if (quant > 0)
    {
        struct CARRO carros[quant];
        FILE *arq;
        arq = fopen(diretorio, "rb");

        if (arq != NULL)
        {
            fread(carros, sizeof(struct CARRO), quant, arq);

            // Ordena os carros por fabricante e modelo
            ordenarCarrosPorFabricanteModelo(carros, quant);

            fclose(arq);

            printf("------------------------------------------------------------------------------\n");
            for (int i = 0; i < quant; i++)
            {
                infDadosCarro(carros[i]);
            }
            pause();
            limpa();
        }
        else
        {
            err("Erro ao abrir o arquivo.");
        }
    }
    else
    {
        err("Nao ha nenhum registro cadastrado no sistema!");
    }
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
    if (tipo == 0)
    {
        if (strcmp(val, "Ferrari") == 1)
            return 0;
        else if (strcmp(val, "Honda") == 1)
            return 1;
        else if (strcmp(val, "Kia") == 1)
            return 2;
        else if (strcmp(val, "Lamborghini") == 1)
            return 3;
    }
    else if (tipo == 1)
    {
        if (strcmp(val, "Celta") == 1)
            return 0;
        else if (strcmp(val, "Gol") == 1)
            return 1;
        else if (strcmp(val, "Sorento") == 1)
            return 2;
        else if (strcmp(val, "Uno") == 1)
            return 3;
    }
    return 0;
}
// Carro

// Cliente
void infDadosCliente(struct CLIENTE cliente)
{
    printf("Nome: %s\n", cliente.nome);
    printf("Cpf: %s\n", cliente.cpf);
    printf("Endereco: \n");
    printf("    Rua: %s\n", cliente.endereco.rua);
    printf("    Numero: %d\n", cliente.endereco.numero);
    printf("    Bairro: %s\n", cliente.endereco.bairro);
    printf("    Cidade: %s\n", cliente.endereco.cidade);
    printf("    Estado: %s\n", cliente.endereco.estado);
    printf("    Cep: %s\n", cliente.endereco.cep);
    printf("Telefone Residencial: %s\n", cliente.residencial.telefone);
    printf("Celular: '%s', ", cliente.celular[0].telefone);
    for (int i = 1; i < 5; i++)
    {
        if (cliente.celular[i + 1].telefone[0] == '0')
        {
            printf("\"%s\n\"", cliente.celular[i].telefone);
        }
        else
        {
            printf("\"%s\", ", cliente.celular[i].telefone);
        }
    }
    printf("Renda mensal: %.2f", cliente.renda_mensal);
    printf("------------------------------------------------------------------------------\n");
}
// Cliente
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
                listarCarrosPorFabricanteModelo(diretorio);
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

void menuCliente(char diretorio[])
{
    char ent[2];
    int escolha = -1;
    while (escolha != 0)
    {
        printf("Escolha uma das opcoes:\n");
        printf("1- Inserir um cliente no cadastro\n");
        printf("2- Excluir um cliente do cadastro\n");
        printf("3- Listar os clientes do cadastro ordenados crescentemente pelo nome\n");
        printf("4- Listar os clientes do cadastro ordenados crescentemente pelo nome por seleção de faixa de renda salarial mensal\n");
        scanf("%s", ent);
        if (verif(ent) == 1)
        {
            escolha = atoi(ent);
            if (escolha == 1)
            { // Inserir um cliente no cadastro
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
                        if (strcmp(cpf, clientes[i].cpf) == 1)
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
            { // Listar os clientes do cadastro ordenados crescentemente pelo nome
                int quant = quantRegistro(diretorio, 2);
                if (quant > 0)
                {
                    struct ORDENA_NOME
                    {
                        int id;
                        char nome[TAM];
                    };

                    char aux[100];
                    int idAux;
                    struct CLIENTE clientes[quant];
                    struct ORDENA_NOME nomes[quant];
                    FILE *arq;
                    arq = fopen(diretorio, "rb");
                    for (int i = 0; i < quant; i++)
                    {
                        fread(&clientes[i], sizeof(clientes[i]), 1, arq);
                        strcpy(nomes[i].nome, clientes[i].nome);
                        nomes[i].id = i;
                    }
                    fclose(arq);
                    for (int i = 0; i < quant; i++)
                    {
                        for (int j = i + 1; j < quant; j++)
                        {
                            if (nomes[i].nome[0] > nomes[j].nome[0])
                            {
                                idAux = nomes[i].id;
                                nomes[i].id = nomes[j].id;
                                nomes[j].id = idAux;
                                strcpy(aux, nomes[i].nome);
                                strcpy(nomes[i].nome, nomes[j].nome);
                                strcpy(nomes[j].nome, aux);
                            }
                        }
                    }
                    for (int i = 0; i < quant; i++)
                    {
                        infDadosCliente(clientes[nomes[i].id]);
                    }
                }
                else
                {
                    err("Nao ha nenhum registro cadastrado no sistema!");
                }
            }
            else if (escolha == 4)
            { // Listar os clientes ordenados crescentemente pelo nome e por renda salarial mensal
            }
            else if (escolha < 0 || escolha > 4)
            { // Caso o usuario digite um valor inexistente
                err("Valor inserido invalido!");
            }
        }
        else
        { // Caso o usuario digite um caractere ao inves de um numero
            err("Valor inserido invalido!");
        }
    }
}

// void menuVenda(char diretorios[3][20])
// {
// }

int main()
{
    char diretorios[][20] = {"carro.bin", "cliente.bin", "venda.bin"};
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
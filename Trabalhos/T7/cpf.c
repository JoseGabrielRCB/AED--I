
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

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
    char cpf_char;
    for (int i = 0; i < 10; i++)
    {
        if (a == i) // verifica a qual nuemero de 1 a 9 ele pertence.
        {
            cpf_char = aux[i]; // insere o numero condizente.
            i = 10;            // finaliza o for.
        }
    }

    return (cpf_char);
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

int main()
{
    char cpf[20];
    gera_cpf_valido(cpf);
    for (int i = 0; i < 11; i++)
    {
        printf("%c",cpf[i]);
    }
    
    return 0;
}
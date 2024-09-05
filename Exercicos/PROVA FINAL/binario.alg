
tipo
    registro=NOME
        nome_cliente: caractere
    FIM_REGISTRO

    RGN = NOME

var
    ARQ_2: RNG
    ARQ_1: RGN
    REG: NOME


inicio rotina copia_arquivo()
    var
        i: inteiro
    inicio
       Associe(ARQ_1,"arquivo1.bin") 
       Associe(ARQ_2,"arquivo2.bin")

       Abre(ARQ_1)
       Reabre(ARQ_2)

       enquanto nao(FDA(ARQ_1)) faca
            leia(ARQ_1,REG.nome_cliente)
            escreva(ARQ_2,REG)
        fim enquanto
        Fecha(ARQ_1);
        Fecha(ARQ_2);
    fim algoritimo
fim rotina



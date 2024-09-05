Faça uma rotina que retire os registros repetidos de um
arquivo. Declare todas as variáveis necessárias antes.

tipo
    registro=NOME
        nome_cliente: caractere
    FIM_REGISTRO

    RGN = NOME

var
    arquivo: RNG
    arquivo_destino: RNG
    REG : RNG



rotina retirar_repetidos()
    var
        nome_destino : caractere
        nome_origem : caractere


    inicio
    Associe(arquivo,"arquivo.bin")
    Associe(arquivo_destino,"arquivoDestino.bin")

    Reabre(arquivo_destino)
    Abre(arquivo)

    Aponte(arquivo,1)
    leia(arquivo,REG.nome)
    Aponte(arquivo2,1)
    escreva(arquivo2,REG.nome)
    nome_origem <- REG.nome

    enquanto nao(FDA(arquivo)) faca
        enquanto nao(FDA(arquivo_destino)) faca
            leia(arquivo2,nome_destino)
            se nome_destino = nome_origem

            



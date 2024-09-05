
Faça uma rotina que retire os registros repetidos de um
arquivo. Declare todas as variáveis necessárias antes.


tipo
    registro=NOME
        nome_cliente: caractere
    FIM_REGISTRO

    RGN = NOME

var
    Arquivo : RNG
    arquivo_destino: RNG
    REG_origem : RNG
    REG_destino : RNG

rotina Retirar_Repetidos()
    var
        cont,i: inteiro
        
    inicio
        Associe(Arquivo,"arquivo.bin")
        Reabre(arquivo_destino,"arquivoNovo.bin")
        Abre(Arquivo)
        Abre(arquivo_destino)

        Aponte(Arquivo,1)
        leia(Arquivo,REG_origem.nome_cliente)
        escreva(arquivo_destino,REG_origem)
        Aponte(Arquivo,2)
        i<-2
        enquanto nao (FDA(Arquivo)) faca
            leia(Arquivo,REG_origem.nome_cliente)
            Aponte(arquivo_destino,1)
            cont <- 0
            enquanto nao(FDA(arquivo_destino)) faca
                leia(arquivo_destino,REG_destino.nome_cliente)
                se REG_destino.nome_cliente = REG_origem.nome_cliente faca
                    cont <- cont +1
                fim se
            fim enquanto
            se cont = 0 faca
                Aponte(arquivo_destino,i)
                escreva(arquivo_destino,REG_origem.nome_cliente)
            fim se
            i<- i+1
        fim enquanto

        Fecha(Arquivo)
        Fecha(arquivo_destino)
    fim algoritimo

            
            


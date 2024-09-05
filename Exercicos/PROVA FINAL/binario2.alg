tipo
    registro=NOME
        nome_cliente: caractere
    FIM_REGISTRO

    RGN = NOME

var
    arquivo1 : RNG
    arquivo2: RNG
    REG : RNG


inicio rotina()
    var
    nome_um ,nome_dois: caractere

    inicio
        Associe(arquivo1,"arquivo1.bin")
        Associe(arquivo2,"arquivo2.bin")

        Abre(arquivo1)
        ReabreAbre(arquivo2)

        enquanto nao(FDA(arquivo1)) faca
         nome_um<-Leia(arquivo1,REG.nome)
         Aponte(arquivo2,1)
            enquanto nao(FDA(arquivo1)) faca
                nome_dois<- Leia(arquivo1,REG.nome)
                se nome_um = nome_dois faca
                    escreva(arquivo2,nome_um)
                fim se
            fim enquanto
        fim enquanto
        Fecha(arquivo1)
        Fecha(arquivo2)
    fim algoritimo
            
            

         
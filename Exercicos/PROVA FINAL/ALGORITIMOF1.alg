

procedimento Salvar_em_bin()
    var
        i: inteiro
    inicio
        Associe(ARQ,"corrida.bin")
        Reabre(ARQ)
        para i de 1  ate 72 faca
            leia(REG.ano)
            leia(REG.pontos)
            leia(REG.campeao)
            leia(REG.equipe)
            escreva(ARQ,REG)
        fimpara
        Feche(ARQ)
    fim algoritomo
fim procedimento


funcao Quant_Champ(caractere campeao)
    var
        palavra 0..100
        i,cont:inteiro
    inicio
        Associe(ARQ,"corrida.bin")
        i<-0
        Abre(ARQ)
        enquanto nao (FDA(ARQ)) faca
            Leia(ARQ,REG)
            se(REG.campeao = campeao)
                cont<- cont +1
            fim se
        fimpara
        Fecha(ARQ)
        retorne cont
    fim algoritomo
fim funcao

                
            

            

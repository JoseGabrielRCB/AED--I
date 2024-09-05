Faça uma rotina que mostre os registros iguais entre
dois arquivos

tipo
    registro=NOME
        nome_cliente: caractere
    FIM_REGISTRO

    RGN = NOME



var

    Arq_um : RNG
    Arq_dois : RNG

funcao  RegistrosIguais()
    var
        Registro_um = RNG
        Registro_dois = RNG
        cont : inteiro
        

    inicio
        cont <- 0

        Associe(Arq_um,"arquivo1.bin")
        Associe(Arq_dois,"arquivo2.bin")

        Abre(Arq_um)
        Abre(Arq_dois)

        enquanto nao(FDA(Arq_um)) faca
            leia(Arq_um,Registro_um.nome_cliente)
            Aponte(Arq_dois,1)
            cont <- 0
            enquanto nao (FDA(Arq_dois)) faca
                leia(Arq_dois,Registro_dois.nome_cliente)
                    se cont = 0 faca
                        se Registro_dois.nome_cliente = Registro_um.nome_cliente faca
                            escreval(Registro_dois.nome)
                            cot <- cont +1
                        fim se
                    fim se
            fim enquanto
        fim enquanto
        Fecha(Arq_dois)
        Fecha(Arq_um)
    fim algoritimo
fim funcao
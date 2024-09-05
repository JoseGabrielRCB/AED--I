
Tipo
    Pessoa=registro
        nome: caracter
        idade: inteiro
    FIM_REGISTRO
    
    Tarq = Arquivo de pessoa
var
    AP_Origem_1,AP_Origem_2,AP_Destino : Tarq

procedimento JuntarArquivos( origem_1: Tarq, origem_2: Tarq)
    var
        registro_1: PESSOA
        registro_2: PESSOA
        inteiro: cont
    inicio
        abre(origem_1)
        abre(origem_2)
        Reabre(Arq_3)

        enquanto (nao FDA(origem_1)) faca
            leia(origem_1,registro_1)
            escreva(Arq_3,registro_1)
            cont <- cont +1
        fim enquanto

        Aponte(Arq_3,cont)

        enquanto(nao FDA(origem_2)) faca
            leia(origem_2,registro_2)
            escreva(Arq_3,registro_2)
        fim enquanto

        fecha(Arq_3)
        fecha(origem_2)
        fecha(origem_1)
fim procedimento

inicio
    Associe(AP_Origem_1,"pessoa_1.bin")
    Associe(AP_Destino,"Arq_3.bin")
    Associe(AP_Origem_2,"pessoa_2.bin")
     JuntarArquivos(AP_Origem_1,AP_Origem_2)
fimalgoritimo


        








        
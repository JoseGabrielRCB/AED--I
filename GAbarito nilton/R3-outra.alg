algoritmo "semnome"
//entrada: sexo (H="homem"  M="mulher"), altura
//saida: PESO_IDEAL
//proc:  PESO_IDEAL = (62,1 x Altura) – 44.7  -->  (sexo="M")
//       PESO_IDEAL = (72,7 x Altura) - 58    -->  (sexo="H")
var
   altura, peso_ideal:real
   sexo:caracter
inicio
      escreval("Calcula o peso ideal")
      escreva("Qual o sexo? (M=mulher ou H=homem) ")
      leia(sexo)
      se (sexo="M") ou (sexo ="H") entao
         escreva("Qual a altura? ")
         leia(altura)
         se (sexo="M") entao
            PESO_IDEAL <- (62.1 * Altura) – 44.7
         fimse
         se (sexo="H") entao
            PESO_IDEAL <- (72.7 * Altura) - 58
         fimse
         escreva("O peso ideal vale: ",peso_ideal)
      fimse
      se (sexo<>"M") e (sexo<>"H") entao
         escreva("O valor do sexo invalido!")
      fimse
fimalgoritmo

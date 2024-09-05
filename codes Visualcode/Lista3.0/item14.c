#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    int matricula = 0;
    int n2 = 0;
    int n1 = 0;
    int n3 = 0;
    int presenca = 0;
    float media = 0;
    int cont = 0;
    int cont2 = 0;
    int cont3 = 0;
    int maior = 0;
    int menor = 0;
    float media_total;
    int nota_total;

    printf("\ncalcule a aprovacao dos alunos\n");
    for (i = 0; i < 4; i++)
    {
        do
        {

            printf("\nInsira o numero de matricula do aluno:\n");
            scanf("%d", &matricula);
            if (matricula <= 0)
            {
                printf("\nas matriculas devem ser maiores que 0!!\n");
            }
        } while (matricula <= 0);

        do
        {
            maior = 0;
            menor = 0;
            printf("\ninsira a primeira nota do aluno:\n");
            scanf("%d", &n1);
            printf("\ninsira a segunda nota do aluno:\n");
            scanf("%d", &n2);
            printf("\ninsira a terceira nota do aluno:\n");
            scanf("%d", &n3);
            if (n1 < 0 || n2 < 0 || n3 < 0)
            {
                printf("\nas notas devem ser maiores  ou  iaguais a 0!!\n");
            }
            // contador para maior
            else if (n1 > maior)
            {
                maior = n1;
            }
            else if (n2 > maior)
            {
                maior = n2;
            }
            else if (n3 > maior)
            {
                maior = n3;
            }
            // contador para menor
            if (n1 < menor)
            {
                menor = n1;
            }
            else if (n2 < menor)
            {
                menor = n2;
            }
            else if (n3 < menor)
            {
                menor = n3;
            }
        } while (n1 < 0 || n2 < 0 || n3 < 0);

        do
        {
            printf("\ninsira a quantidade de presencas do aluno:\n");
            scanf("%d", &presenca);
            if (presenca < 0)
            {
                printf("As presencas devems ser maiores ou iguais a 0\n");
            }
            else if (presenca < 40)
            {
                cont3++; // contador de reprovados por infrequencia
            }
        } while (presenca < 0);

        media = ((float)n1 + n2 + n3) / 3;
        // guardar todas as notas para o calculo da media final
        nota_total = n1 + n2 + n3;

        if (media >= 60 && presenca >= 40)
        {
            cont++; // contador de aprovados
            printf("\nMatricula:%d\nMedia:%.2f\nPresenca:%d\nSituacao:aprovado\n", matricula, media, presenca);
        }
        else
        {
            cont2++; // contador de aprovados
            printf("\nMatricula:%d\nMedia:%.2f\nPresenca:%d\nSituacao:reprovado\n", matricula, media, presenca);
        }
    }
    media_total = nota_total / i;
    printf("\nfinalizacao do sistema\n");
    printf(" a media da turma foi de %.2f", media_total);
    printf("\nA maior nota da sala e:%d\n", maior);
    printf("\nA menor nota da sala e:%d\n", menor);
    printf("\nA quantidade alunos reprovados foi de %d", cont2);
    printf("\nA porcentagem de alunos reprovados por infrequencia foi de:%.2f", ((float)cont3 * 100) / (cont + cont2));

    return 0;
}
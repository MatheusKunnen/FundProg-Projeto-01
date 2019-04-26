# include<stdio.h>
/*
    Projeto-01 | Fund. Prog 01 | Turma Eng. Comp. 2019/01
    Alunos: Matheus Kunnen
            Jhonny Assis
    Questao - 02:
                Construa um programa que produza uma folha de calend ́ario para um ano completo,
                o qual deve ser informado pelo usuario via teclado! O programa a ser desenvolvido
                deve levar em conta que o mˆes de fevereiro pode ter 29 dias (ano bissexto).
*/
#define SIZE (1 << 4)
int main (){
        int x, y, i;
        printf("\tX\t\tY\t\tI\t\t\n");
        for (y = SIZE - 1; y >= 0; y--, putchar(/*'\n'*/' ')) {
                printf("%10d\t%10d\t%10d\n", x, y, i);
                for (i = 0; i < y; i++)
                    printf("%10d\t%10d\t%10d\n", x, y, i);
                        //putchar(' ');
                for (x = 0; x + y < SIZE; x++)
                    printf("%10d\t%10d\t%10d\n", x, y, i);
                        //printf((x & y)? " " : "* ");
        }
        return 0;
}

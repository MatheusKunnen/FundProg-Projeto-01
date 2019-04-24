# include<stdio.h>
/*
    Projeto-01 | Fund. Prog 01 | Turma Eng. Comp. 2019/01
    Alunos: Matheus Kunnen
            Jhonny Assis
    Questao - 01:
                Construa um programa que produza uma folha de calend ́ario para um ano completo,
                o qual deve ser informado pelo usu ́ario via teclado! O programa a ser desenvolvido
                deve levar em conta que o mˆes de fevereiro pode ter 29 dias (ano bissexto).
*/

// Calcula primeiro dia do mes
int diaInicioMes(int mes, int ano);
// Retorna 1 se o ano e bissexto e 0 no caso contrario
int ehBissexto(int ano);
// Imprime a cabecera do mes
void imprimeCabMes(int mes);
// Imprime dias do mes
void imprimeDiasMes(int mes, int ano);
// Retorna o total de dias do mes
int totalMes(int mes, int ano);

int main(){
    int ano = 0;
    do {
        printf("0 = Sair\nDigite o ano do calendario: "); 
        scanf("%d", &ano);
        for(int i = 1; i <= 12 && ano != 0; i++){
            imprimeCabMes(i);
            imprimeDiasMes(i,2019);
            printf("\n\n");
        }
        /*while (mes != 0){
        scanf("%d %d", &mes, &ano);
        printf("%d", diaInicioMes(mes, ano));
        }*/
    } while (ano != 0);
    return 0;
}

// Calcula primeiro dia do mes
int diaInicioMes(int mes, int ano){
    int mMes = 0;
    switch(mes){
            case 1:
            mMes = ehBissexto(ano) ? 0 : 0;
            break;
        case 2:
            mMes = ehBissexto(ano) ? 3 : 3;
            break;
        case 3:
            mMes = ehBissexto(ano) ? 3 : 4;
            break;
        case 4:
            mMes = ehBissexto(ano) ? 6 : 0;
            break;
        case 5:
            mMes = ehBissexto(ano) ? 1 : 2;
            break;
        case 6:
            mMes = ehBissexto(ano) ? 4 : 5;
            break;
        case 7:
            mMes = ehBissexto(ano) ? 6 : 0;
            break;
        case 8:
            mMes = ehBissexto(ano) ? 2 : 3;
            break;
        case 9:
            mMes = ehBissexto(ano) ? 5 : 6;
            break;
        case 10:
            mMes = ehBissexto(ano) ? 0 : 1;
            break;
        case 11:
            mMes = ehBissexto(ano) ? 3 : 4;
            break;
        case 12:
            mMes = ehBissexto(ano) ? 5 : 6;
            break;
    }
    return ((ano - 1) % 7 + ((ano - 1) / 4 - (3 *((ano - 1)/100 + 1) / 4))%7 + mMes + 1)%7;
}

// Retorna 1 se o ano e bissexto e 0 no caso contrario
int ehBissexto(int ano){
    return ano % 4 == 0 || ano % 400 == 0;
}

// Imprime a cabecera do mes
void imprimeCabMes(int mes){
    switch(mes){
        case 1:
            printf("\t\tJANEIRO\t\t\t\n");
            break;
        case 2:
            printf("\t\tFEVEREIRO\t\t\n");
            break;
        case 3:
            printf("\t\tMAR\x80O\t\t\n");
            break;
        case 4:
            printf("\t\tABRIL\t\t\n");
            break;
        case 5:
            printf("\t\tMAIO\t\t\n");
            break;
        case 6:
            printf("\t\tJUNHO\t\t\n");
            break;
        case 7:
            printf("\t\tJULHO\t\t\n");
            break;
        case 8:
            printf("\t\tAGOSTO\t\t\n");
            break;
        case 9:
            printf("\t\tSETEMBRO\t\t\n");
            break;
        case 10:
            printf("\t\tOUTOBRO\t\t\n");
            break;
        case 11:
            printf("\t\tNOVEMBRE\t\t\n");
            break;
        case 12:
            printf("\t\tDEZEMBRO\t\t\n");
            break;
    }
    printf("DOM\tSEG\tTER\tQUA\tQUI\tSEX\tSAB\n");
}

// Imprime dias do mes
void imprimeDiasMes(int mes, int ano){
    int tMes, iMes, i;
    tMes = totalMes(mes, ano);
    iMes = diaInicioMes(mes, ano);
    for(i = 1; i <= tMes + iMes; i++){
        if (i < iMes + 1){
            printf("  \t");
        } else {
            printf("%3d\t", i - iMes);
            if (i % 7 == 0)
                printf("\n");
        }
    }
}

// Retorna o total de dias do mes
int totalMes(int mes, int ano){
     switch(mes){
        case 1:
            return 31;
            break;
        case 2:
            return ehBissexto(ano) ? 29 : 28;
            break;
        case 3:
            return 31;
            break;
        case 4:
            return 30;
            break;
        case 5:
            return 31;
            break;
        case 6:
            return 30;
            break;
        case 7:
            return 31;
            break;
        case 8:
            return 31;
            break;
        case 9:
            return 30;
            break;
        case 10:
            return 31;
            break;
        case 11:
            return 30;
            break;
        case 12:
            return 31;
            break;
    }
    return 0;
}

/*
    Bibliografia:
            * Calculo primeiro dia do mes: https://es.wikibooks.org/wiki/Algoritmia/Algoritmo_para_calcular_el_d%C3%ADa_de_la_semana
*/

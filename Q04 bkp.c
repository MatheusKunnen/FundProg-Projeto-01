/*
    Projeto-01 | Fund. Prog 01 | Turma Eng. Comp. 2019/01
    Alunos: Matheus Kunnen
            Jhonny Assis
    Questao - 04: Faca um programa que, dado um numero, identifique a imprimirOperadora e verifique a validade do nu ́mero. As situa ̧c ̃oes a serem tratadas e que devem ser indicadas por mensagens adequadas sa ̃o as seguintes:
                        1. Nu ́meros que contiverem caracteres n ̃ao num ́ericos (caracteres fora do intervalo [0;9] );
                        2. Nu ́meros com tamanho incorreto;
                        3. Nu ́meros de operadoras desconhecidas (que nao precisam ser validados);
                        4. Nu ́meros de operadoras conhecidas, mas invalidos;
                        5. Nu ́meros de operadoras conhecidas e validos.
                */

#include <stdio.h>
#include <math.h>

int lerNroCartao(unsigned long long *numero, int *tamanho);
int verOperadora(unsigned long long numero, int *codOperadora);
void numeroInvalido(unsigned long long numero, int codOperadora, int tamanho);
void imprimirOperadora(int codOperadora);
int validarNro(unsigned long long numero, int codOperadora, int tamanho);
unsigned long long restoLong(unsigned long long d1, unsigned long long d2);

int main()
{
        int codOperadora, tamanho;
        unsigned long long numero;
        //printf("Digite o numero do Cartao: ");
        //scanf("%llu", &numero);
        //codOperadora = verOperadora(numero);
        if (lerNroCartao(&numero, &tamanho))
        {
                if (verOperadora(numero, &codOperadora))
                {
                        if (validarNro(numero, codOperadora, tamanho))
                        {
                                printf("Estado: \x1b[32mValido.\x1b[0m\n");
                        }
                        else
                        {
                                printf("Estado: Invalido. ");
                                numeroInvalido(numero, codOperadora, tamanho);
                        }
                }
        }
        /*if (codOperadora == 0) //NUMERO INVALIDO, CASO 1,2,3
        {
                numeroInvalido(numero);
        }
        else
        {
                if (validarNro(numero)) //CASO 4
                        printf("Numero de imprimirOperadora conhecida, mas invalido ");
                else //CASO 5
                {
                        printf("\nNumero valido\nOperadora: ");
                        imprimirOperadora(codOperadora);
                }
        }*/
        return 0;
}

int verOperadora(unsigned long long numero, int *codOperadora)
{
        *codOperadora = 0;
        while (numero / 10000 > 0)
        {
                numero /= 10;
        }
        printf("Operadora: ");
        switch (numero / 1000)
        {
        case 1:
                if (numero == 1800)
                {
                        printf("JCB");
                        *codOperadora = 8; // JCB de tamanho 15
                }
                break;
        case 2:
                switch (numero)
                {
                case 2014:
                case 2149:
                        printf("enRoute");
                        *codOperadora = 6;
                        break;
                case 2131:
                        printf("JCB");
                        *codOperadora = 8; // JCB de tamanho 15
                        break;
                }
                break;
        case 3:
        case 5:
                switch (numero / 100)
                {
                case 30:
                case 36:
                case 38:
                        printf("Diners");
                        *codOperadora = 4;
                        break;
                case 34:
                case 37:
                        printf("Amex");
                        *codOperadora = 3;
                case 51:
                case 55:
                        printf("Mastercard");
                        *codOperadora = 1;
                        break;
                default:
                        printf("JCB");
                        *codOperadora = 7; // JCB de tamanho 16
                        break;
                }
                break;
        case 4:
                printf("Visa");
                *codOperadora = 2;
                break;
        case 6:
                if (numero == 6011)
                {
                        printf("Discover");
                        *codOperadora = 5;
                }
                break;
        default:
                printf("Desconhecida\n");
        }
        printf("\n");
        /*int codOperadora = 0;
        if (numero / (unsigned long long)(pow(10, 14)) == 51 || numero / (unsigned long long)(pow(10, 14)) == 55)
        {
                codOperadora = 1; //Mastercard
        }
        else if (numero / (unsigned long long)(pow(10, 12)) == 4 || numero / (unsigned long long)(pow(10, 15)) == 4)
        {
                codOperadora = 2; //Visa
        }
        else if (numero / (unsigned long long)(pow(10, 13)) == 34 || numero / (unsigned long long)(pow(10, 13)) == 37)
        {
                codOperadora = 3; //Amex
        }
        else if (numero / (unsigned long long)(pow(10, 12)) == 30 || numero / (unsigned long long)(pow(10, 12)) == 36 || numero / (unsigned long long)(pow(10, 12)) == 38)
        {
                codOperadora = 4; //Dinnes
        }
        else if (numero / (unsigned long long)(pow(10, 12)) == 6011)
        {
                codOperadora = 5; //Discover
        }
        else if (numero / (unsigned long long)(pow(10, 11)) == 2014 || numero / (unsigned long long)(pow(10, 11)) == 2149)
        {
                codOperadora = 6; //enRoute
        }
        else if (numero / (unsigned long long)(pow(10, 15)) == 3)
        {
                codOperadora = 7; //JCB
        }
        else if (numero / (unsigned long long)(pow(10, 11)) == 2131 || numero / (unsigned long long)(pow(10, 11)) == 1800)
        {
                codOperadora = 8; //JCB
        }
        //SE X=0, O NUMERO � INVALIDO.*/
        return *codOperadora != 0;
}

void numeroInvalido(unsigned long long numero, int codOperadora, int tamanhoN)
{
        int tipo = 0; // 1 = Maior; 2 = Menor
        switch (codOperadora)
        {
        case 1:
        case 5:
        case 7:
                tipo = (tamanhoN > 16) ? 1 : 2;
                break;
        case 3:
        case 6:
        case 8:
                tipo = (tamanhoN > 15) ? 1 : 2;
        case 4:
                tipo = (tamanhoN > 14) ? 1 : 2;
        case 2:
                if (tamanhoN > 16)
                        tipo = 1;
                else if (tamanhoN < 13)
                        tipo = 2;

        }
        if (tipo != 0) printf(((tipo == 1) ? "(Numero muito longo)\n" : "(Numero muito curto)\n"));
        //printf("R: %d\n", numeroResultante); //TESTE
        //return tamOk && (numeroResultante % 10 == 0);
        /*if (((numero / (unsigned long long)(pow(10, 12))) < 10) || ((numero / (unsigned long long)(pow(10, 16))) > 10))
        {
                printf("Tamanho incorreto "); //CASO 2
        }
        else if (((numero / (unsigned long long)(pow(10, 12))) > 10) && ((numero / (unsigned long long)(pow(10, 16))) < 10))
        {
                printf("numero de operadoras desconhecidas  "); //CASO 3
        }*/
}


int lerNroCartao(unsigned long long *numero, int *tamanho)
{
        int valido = 1;
        char c;

        printf("Digite o numero do Cartao: ");
        scanf("%c", &c);

        *tamanho = 0;
        while (c != '\n')
        {
                //printf("C: %c %d",c,c);
                if (c < 47 || c > 58)
                {
                        valido = 0;
                        break;
                }
                *tamanho += 1;
                *numero = *numero * 10 + (c - 48);
                scanf("%c", &c);
        }
        printf("Nro.: %llu\n", *numero);
        if (!valido || *tamanho > 16 || *tamanho < 13)
        {
                printf("Estado: \x1b[31m Invalido.");
                if (!valido)
                        printf(" (Caracteres invalidos encontrados).\x1b[0m\n");
                else
                        printf((*tamanho > 16) ? "(Nro. muito longo).\x1b[0m\n": "(Nro. muito curto).\x1b[0m\n");
        }
        return valido;
}

int validarNro(unsigned long long numero, int nroOperadora, int tamanhoN)
{
        int  tamOk = 1, numeroResultante = 0, num;
        while (numero > 0) //Quantos algarismos tem o numero
        {
                num = numero % 10;
                //printf("I: %d N: %d\n", tamanhoN, num); // TESTE
                if (tamanhoN % 2 == 0)
                {
                        num = num * 2;
                        if (num >= 10)
                        {
                                num = num % 10 + num / 10;
                        }
                }
                numeroResultante += num;
                numero /= 10;
        }
        //printf("Operadora: %d\n Tamanho: %d \n", nroOperadora, );
        switch (nroOperadora)
        {
        case 1:
        case 5:
        case 7:
                if (tamanhoN != 16) tamOk = 0;
                break;
        case 3:
        case 6:
        case 8:
                if (tamanhoN != 15) tamOk = 0;
        case 4:
                if (tamanhoN != 14) tamOk = 0;
        case 2:
                if (tamanhoN != 16 && tamanhoN != 13) tamOk = 0;
        }
        //printf("R: %d\n", numeroResultante); //TESTE
        return tamOk && (numeroResultante % 10 == 0);
}

unsigned long long restoLong(unsigned long long d1, unsigned long long d2)
{
        printf("Entrou em resto\n");
        while (d1 >= d2)
        {
                d1 -= d2;
        }
        return d1;
}

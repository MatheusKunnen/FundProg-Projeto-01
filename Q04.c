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

int lerNroCartao(unsigned long long *numero);
int verOperadora(unsigned long long numero);
int validarNro(unsigned long long numero);

int main()
{
        unsigned long long numero;
        do {
            if (lerNroCartao(&numero))
            {
                    if (verOperadora(numero))
                    {
                            if (validarNro(numero))
                            {
                                    printf("Estado: \x1b[32mValido.\x1b[0m\n");
                            }
                            else
                            {
                                    printf("Estado: \x1b[31mInvalido.\x1b[0m ");
                            }
                    }
            }
            printf("\n\n");
        } while (numero > 0);
        return 0;
}

int verOperadora(unsigned long long numero)
{
        int codOperadora = 0;
        printf("Operadora: ");
        if (numero / (unsigned long long)(pow(10, 14)) == 51 || numero / (unsigned long long)(pow(10, 14)) == 55)
        {
                printf("Mastercard");
                codOperadora = 1; //Mastercard
        }
        else if (numero / (unsigned long long)(pow(10, 12)) == 4 || numero / (unsigned long long)(pow(10, 15)) == 4)
        {
                printf("Visa");
                codOperadora = 2; //Visa
        }
        else if (numero / (unsigned long long)(pow(10, 13)) == 34 || numero / (unsigned long long)(pow(10, 13)) == 37)
        {
                printf("Amex");
                codOperadora = 3; //Amex
        }
        else if (numero / (unsigned long long)(pow(10, 12)) == 30 || numero / (unsigned long long)(pow(10, 12)) == 36 || numero / (unsigned long long)(pow(10, 12)) == 38)
        {
                printf("Dinnes");
                codOperadora = 4; //Dinnes
        }
        else if (numero / (unsigned long long)(pow(10, 12)) == 6011)
        {
                printf("Discover");
                codOperadora = 5; //Discover
        }
        else if (numero / (unsigned long long)(pow(10, 11)) == 2014 || numero / (unsigned long long)(pow(10, 11)) == 2149)
        {
                printf("enRoute");
                codOperadora = 6; //enRoute
        }
        else if (numero / (unsigned long long)(pow(10, 15)) == 3)
        {
                printf("JCB");
                codOperadora = 7; //JCB
        }
        else if (numero / (unsigned long long)(pow(10, 11)) == 2131 || numero / (unsigned long long)(pow(10, 11)) == 1800)
        {
                printf("JCB");
                codOperadora = 8; //JCB
        } else {
                printf("Desconhecida");
        }
        printf("\n");
        return codOperadora != 0;
}

// Le o nro. do cartao e verifica sua longitude e caracteres. Retorna 1 => OK, 0 => nro. Invalido
int lerNroCartao(unsigned long long *numero)
{
        int valido = 1, tamanho = 0;
        char c;

        printf("Digite o numero do Cartao: ");
        scanf("%c", &c); // Inicia variavel c

        *numero = 0;
        while (c != '\n')  // Le um caracter ate encontrar um salto de linha
        {
                if (c < 47 || c > 58) // Verifica se o valor e um nro.
                {
                        valido = 0;
                        while ((getchar()) != '\n'); // Limpa entrada
                        break;
                }
                tamanho += 1;
                *numero = *numero * 10 + (c - 48);
                scanf("%c", &c);
        }
        printf("Nro.: %llu\n", *numero);
        if (!valido || tamanho > 16 || tamanho < 13) //  Verifica se o nro e valido e imprime mensagens de erro.
        {
                printf("Estado: \x1b[31mInvalido.\x1b[0m");
                if (!valido)
                        printf("\x1b[31m (Caracteres invalidos encontrados).\x1b[0m\n");
                else
                        printf((tamanho > 16) ? "\x1b[31m (Nro. muito longo).\x1b[0m\n": "\x1b[31m (Nro. muito curto).\x1b[0m\n");
        }
        return valido && (tamanho <= 16 && tamanho >= 13);
}

int validarNro(unsigned long long numero)
{
        int  numeroResultante = 0, num, i = 1;
        while (numero > 0) //Quantos algarismos tem o numero
        {
                num = numero % 10;
                if (i % 2 == 0)
                {
                        num = num * 2;
                        if (num >= 10)
                        {
                                num = num % 10 + num / 10;
                        }
                }
                numeroResultante += num;
                numero /= 10;
                i++;
        }
        return numeroResultante % 10 == 0;
}

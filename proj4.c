#include <stdio.h>
#include <math.h>

int ver_operadora(unsigned long long numero);
void numero_invalido(unsigned long long numero);
void operadora(int x);
int numero_resultante(unsigned long long numero);
unsigned long long restoLong(unsigned long long d1, unsigned long long d2);
int main()
{
    int prefixo, x, y;
    unsigned long long numero;
    printf("Digite o numero do Cartao: ");
    scanf("%llu", &numero);
    x = ver_operadora(numero);
    //
    if (x == 0) //NUMERO INVALIDO, CASO 1,2,3
    {
        numero_invalido(numero);
    }
    else
    {
        y = numero_resultante(numero);
        if(y % 10 != 0) //CASO 4
            printf("Numero de operadora conhecida, mas invalido ");
        else //CASO 5
        {
            printf("\nNumero valido\nOperadora: ");
            operadora(x);
        }
    }
    return 0;
}

int ver_operadora(unsigned long long numero)
{
    int x = 0;
    if (numero / (unsigned long long) (pow(10, 14)) == 51 || numero / (unsigned long long) (pow(10, 14)) == 55)
    {
        x = 1; //Mastercard
    }
    else if (numero / (unsigned long long) (pow(10, 12)) == 4 || numero / (unsigned long long) (pow(10, 15)) == 4)
    {
        x = 2; //Visa
    }
    else if (numero / (unsigned long long) (pow(10, 13)) == 34 || numero / (unsigned long long) (pow(10, 13)) == 37)
    {
        x = 3; //Amex
    }
    else if (numero / (unsigned long long) (pow(10, 12)) == 30 || numero / (unsigned long long) (pow(10, 12)) == 36 || numero / (unsigned long long) (pow(10, 12)) == 38)
    {
        x = 4; //Dinnes
    }
    else if (numero / (unsigned long long) (pow(10, 12)) == 6011)
    {
        x = 5; //Discover
    }
    else if (numero / (unsigned long long) (pow(10, 11)) == 2014 || numero / (unsigned long long) (pow(10, 11)) == 2149)
    {
        x = 6; //enRoute
    }
    else if (numero / (unsigned long long) (pow(10, 15)) == 3)
    {
        x = 7; //JCB
    }
    else if (numero / (unsigned long long) (pow(10, 11)) == 2131 || numero / (unsigned long long) (pow(10, 11)) == 1800)
    {
        x = 8; //JCB
    }
    //SE X=0, O NUMERO � INVALIDO.
    return x;
}

void numero_invalido(unsigned long long numero)
{
        printf("Entro em numero_invalido\n");
    if (((numero / (unsigned long long) (pow(10, 12))) < 10) || ((numero / (unsigned long long) (pow(10, 16))) > 10))
    {
        printf("Tamanho incorreto "); //CASO 2
    }
    else if (((numero / (unsigned long long) (pow(10, 12))) > 10) && ((numero / (unsigned long long) (pow(10, 16))) < 10))
    {
        printf("numero de operadoras desconhecidas  "); //CASO 3
    }
}
void operadora(int x)
{
    switch (x)
    {
    case 1:
        printf("Mastercard\n");
        break;
    case 2:
        printf("Visa\n");
        break;
    case 3:
        printf("Amex\n");
        break;
    case 4:
        printf("Diners\n");
        break;
    case 5:
        printf("Discover\n");
        break;
    case 6:
        printf("enRoute\n");
        break;
    case 7:
        printf("JCB\n");
        break;
    case 8:
        printf("JCB\n");
        break;
    }
}
int numero_resultante(unsigned long long numero)
{
    //printf("Entro em resultante\n"); //TESTE
    int i = 0, j = 0, numero_resultante = 0, num;
    unsigned long long int aux_numero, s, r;
    aux_numero = numero * 10;
    while (aux_numero > 0) //Quantos algarismos tem o numero
    {
        num = aux_numero % 10;
        //printf("I: %d N: %d\n", i, num); // TESTE
        if (i % 2 == 0){
                num = num * 2;
                if (num >= 10){
                    num = num % 10 + num / 10;
                }
        }
        numero_resultante += num;
        aux_numero /= 10;
        i++;
    }
    //printf("R: %d\n", numero_resultante); //TESTE
    return numero_resultante;
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

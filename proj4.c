#include <stdio.h>
#include <math.h>

int ver_operadora(unsigned long int numero);
int numero_valido(unsigned long int numero);
void operadora(int x);
int numero_resultante(unsigned long int numero);

main()
{
    int prefixo,x,y;
    unsigned long int numero;
    printf("Digite o numero do Cartao: ");
    scanf("%lu", numero);
    x=ver_operadora(numero);
    y=numero_resultante(numero);
    if(x==0)//NUMERO INVALIDO, CASO 1,2,3
    {
         numero_invalido(numero);

    }
    else if(y%10!=0)//CASO 4
    {
        printf("Numero de operadora conhecida, mas inv�lido ");

    }
    else//CASO 5
    {
        printf("\nNumero valido\nOperadora: ");
        operadora(x);

    }


    return 0;
}

int ver_operadora(unsigned long int numero)
{
    int x=0;
    if(numero/(pow(10,15))==51 || numero/(pow(10,15))==55)
    {
        x=1;//Mastercard
    }
    else if(numero/(pow(10,13))==4 || numero/(pow(10,16))==4)
    {
        x=2;//Visa
    }
    else if(numero/(pow(10,14))==34 || numero/(pow(10,14))==37)
    {
        x=3;//Amex
    }
    else if(numero/(pow(10,15))==30 || numero/(pow(10,15))==36 || numero/(pow(10,15))==38)
    {
        x=4;//Dinnes
    }
    else if(numero/(pow(10,13))==6011)
    {
        x=5;//Discover
    }
    else if(numero/(pow(10,12))==2014 || numero/(pow(10,12))==2149)
    {
        x=6;//enRoute
    }
    else if(numero/(pow(10,16))==3 )
    {
        x=7;//JCB
    }
    else if(numero/(pow(10,12))==2131 || numero/(pow(10,12))==1800)
    {
        x=8;//JCB
    }
    //SE X=0, O NUMERO � INVALIDO.
    return x;
}

int numero_invalido(unsigned long int numero)
{
     if(((numero/(pow(10,12)))<10) || ((numero/(pow(10,16)))>10))
    {
        printf("Tamanho incorreto ");//CASO 2
    }
    else if(((numero/(pow(10,12)))>10) && ((numero/(pow(10,16)))<10))
    {
        prontf("numero de operadoras desconhecidas  ");//CASO 3
    }
}
void operadora(int x)
{
    switch(x)
    {
        case 1:
            printf("Mastercard");
            break;
        case 2:
            printf("Visa");
            break;
        case 3:
            printf("Amex");
            break;
        case 4:
            printf("Diners");
            break;
        case 5:
            printf("Discover");
            break;
        case 6:
            printf("enRoute");
            break;
        case 7:
            printf("JCB");
            break;
        case 8:
            printf("JCB");
            break;
    }
}
int numero_resultante(unsigned long int numero)
{
    int i=0,j=0,r,numero_resultante=0;
    unsigned long int aux_numero, s;
    aux_numero=numero;
    while((aux_numero/10)>9)//quantos algarismos tem o numero
    {
       i++;
    }
    aux_numero=numero;
    for(j=2;j<=i;j+2)
    {
        r=(numero%(pow(10,(i-j))))/(pow(10,j));
        r=r*2;
        numero_resultante=numero_resultante+r;//soma algarismos de posi��es pares
    }
    for(j=1;j<=i;j+2)
    {
        s=(numero%(pow(10,(i-j))))/(pow(10,j));
        numero_resultante=numero_resultante+s;
        /*soma a soma dos algarismos pares com os algarismos impares*/
    }
    return numero_resultante;
}

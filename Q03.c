#include <stdio.h>
/*
    Projeto-01 | Fund. Prog 01 | Turma Eng. Comp. 2019/01
    Alunos: Matheus Kunnen
            Jhonny Assis
    Questao - 01:
                A proposta  ́e transmitir esses sımbolos usando o codigo ASCII - por exemplo, ao inves de transmitir ’A’,
                e transmitido o valor 65. Anna e Bob observaram que, para a faixa de valores utilizada para as letras,
                os valores ocupam apenas um byte e que o seu bit mais significativo nao precisa ser usado. Por exemplo,
                o valor 65 em bin ́ario  ́e 01000001 - note que o bit mais a esquerda e zero. Eles decidiram explorar este bit
                para determinar se a letra transmitida foi corrompida ou nao. A proposta consiste em alterar este bit mais
                significativo de tal forma que a soma dos bits seja sempre par (2, 4, 6 or 8)
*/

// recebe uma mensagem e imprime a mesma codificada
void codificaMensagem();
// recebe um char por parametro e o codifica em base decimal ASCII
int codificarLetra(char letra);
// recebe uma mensagem codificada e retorna a mesma em texto
void decodificaMensagem();
// recebe um numero e retorna a letra correspondente se nao estiver corrompido
char decodificarLetra(int letra);
// recebe um decimal e retonar a soma dos digitos binarios
int somaBinario(int dec);

int main()
{
        int men = -1;
        while (men != 0)
        {
                printf("1 - Codificar Mensagem\n2 - Decodificar Mensagem\n0 - SAIR\n>", " ");
                scanf("%d", &men);
                switch (men)
                {
                case 1:
                        codificaMensagem();
                        break;
                case 2:
                        decodificaMensagem();
                        break;
                case 0:
                        break;
                default:
                        men = 0;
                }
        }
        return 0;
}
// Ler os caracgteres
void codificaMensagem()
{
        char letra;
        printf("Digite a Mensagem:\n");
        scanf("%c ", &letra);
        printf("Mensagem Codificada:\n ");
        do
        {
                scanf("%c", &letra);
                printf("%d ", codificarLetra(letra));
        } while (letra != 46);
        printf("\n\n-------------------------------------------------------------\n\n");
}

int codificarLetra(char letra)
{
        int soma = 0;
        soma = somaBinario(letra);
        if (soma % 2 != 0)
        {
                return letra + 128;
        }
        else
        {
                return letra;
        }
}

void decodificaMensagem()
{
        char letra;
        int lDec = 0, dec;
        printf("Digite a Mensagem Codificada:\n");
        scanf("%c ", &letra);
        printf("Mensagem decodificada:\n ");
        while (lDec != 46)
        {
                //printf("while %c\n", letra);
                lDec = 0;
                while (letra != 32)
                {
                        if (letra >= 48 &&letra <= 57)
                        {
                                lDec = lDec * 10 + (letra - 48);
                        } else if (lDec == 46) break;
                        scanf("%c", &letra);
                }
                printf("%c", decodificarLetra(lDec));
                scanf("%c", &letra);
        }
        printf("\n\n-------------------------------------------------------------\n\n");
}

char decodificarLetra(int letra)
{
        int soma = 0;
        soma = somaBinario(letra);
        if (soma % 2 != 0)
        {
                return '*';
        }
        else if (letra > 127)
        {
                return (char) letra - 128;
        }
        else
        {
                return (char) letra;
        }
}

int somaBinario(int dec)
{
        int soma = 0, aux = 1;
        while (dec > 0)
        {
                if (dec % 2 != 0)
                {
                        soma++;
                        //*bin += aux;
                }
                aux *= 10;
                dec /= 2;
        }
        return soma;
}

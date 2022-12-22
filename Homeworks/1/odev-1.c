#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

void printSignBit(int number);
int intToBinary(long number, int isPrint);
void decimalToBinary(double remain);

int *mantissaArr;
int exponent_len, mantis_len, mantissaStartPoint;

int main()
{
    double number;
    int type, exponent_bias;
    long number_int;
    float remain;

    printf("1 - Float \n2 - Double\n");
    printf("Veri Tipini Seciniz (1-2) : ");
    scanf("%d", &type);

    if(type == 1)
    {
        exponent_len = 8;
        mantis_len = 23;
    }
    else if(type == 2)
    {
        exponent_len = 11;
        mantis_len = 52;
    }
    else
    {
        printf("Gecersiz Sayi Girdiniz.");
        return -1;
    }


    printf("\nKusuratli Sayi Giriniz (Tam sayidan sonra nokta koyarak ayiriniz): ");
    scanf("%lf", &number);


    exponent_bias = pow(2, exponent_len-1) - 1;
    number_int = (long) number;
    remain = number - (long) number;

    printSignBit(number);

    int powVal = intToBinary(number_int, 0) + exponent_bias;
    intToBinary(powVal, 1);  

    decimalToBinary(remain);

    getch();
    return 0;
}


void printSignBit(int number)
{
    if(number >= 0)
        printf("0 | ");
    else
        printf("1 | ");
}


int intToBinary(long number, int isPrint)
{
    int i, counter;
    long temp = number;

    for (counter = 0;;counter++)
    {
        if(temp < 2) 
        {
            break;
        }
        temp /= 2;
    }

    temp = number;
    int *exponent = (int*) malloc(sizeof(int) * counter);

    for (i = 0;;i++)
    {
        if (temp < 2)
        {
            exponent[i] = temp % 2;
            break;
        }
        exponent[i] = temp % 2;
        temp /= 2;
    }
    
    int j;
    if(isPrint == 1)
    {
        for (j = i; j >= 0; j--)
        {
            printf("%d ", exponent[j]);
        }
        printf(" | ");

    }
    else
    {
        mantissaArr = (int*) malloc(sizeof(int) * mantis_len);
        int ctr = 0;
        for (j = i - 1; j >= 0; j--)
        {
            mantissaArr[ctr] = exponent[j];
            ctr++;
        }
        mantissaStartPoint = counter;
    }

    return counter;
}

void decimalToBinary(double remain)
{
    int i = 0;
    for (i = mantissaStartPoint; i < mantis_len; i++)
    {
        remain *= 2;

        if(remain >= 1)
        {
            remain -= 1;
            mantissaArr[i] = 1;
        }
        else
        {
            mantissaArr[i] = 0;
        }
    }

    for (int j = 0; j < mantis_len ;j++)
    {
       printf("%d ", mantissaArr[j]);
    }

}
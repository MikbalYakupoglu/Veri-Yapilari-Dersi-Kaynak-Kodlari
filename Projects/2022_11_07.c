#include <stdio.h>
#include <stdlib.h>

#define LENGHT 5

int stack[LENGHT];
int t = -1;

int isFull()
{
    if(t < LENGHT -1)
    {
        return -1;
    }
    else
    {
        printf("Stack is Full\n");
        return 1;
    }
    
}

int isEmpty()
{
    if(t < 0)
    {
        printf("Stack is Empty.\n");
        return 1;
    }
    return 0;
}

void push(int number)
{
    if(isFull() == -1)
    {
        t++;
        stack[t] = number;
    }
}

void pop()
{
    if(isEmpty() == 0)
    {
        printf("Cikarilan Eleman = %d\n", stack[t]);
        t--;
    }
}

void peak()
{
    if(isEmpty() == 0)
    {
        printf("peak : %d\n",stack[t]);    
    }
}

void printStack()
{
    if(isEmpty() == 0)
    {
        for (int i = 0; i <= t; i++)
        {
            printf("%d ", stack[i]);
        }
    }
}


int main()
{
/*
    int secim;
    int sayi;

    while(1)
    {
        printf("\n1- Eleman Ekle");
        printf("\n2- Eleman Cikar");
        printf("\n3- En Tepesindeki Eleman");
        printf("\n4- Tum Elemanlari Yazdir");
        printf("\n5- Cikis");
        printf("\nIslem Seciniz : ");
        scanf("%d", &secim);

        switch (secim)
        {
            case 1:
                printf("Eklemek Istediginiz Sayiyi Giriniz : ");
                scanf("%d", &sayi);
                push(sayi);
                break;

            case 2: 
                pop();
                break;

            case 3:
                peak();
                break;

            case 4: 
                printStack();
                break;

            case 5:
                printf("Islemden Ciktiniz.");
                exit(0);
            
            default:
                printf("Gecersiz Deger Girdiniz.");
                break;
        }
    }
    
*/


    return 0;
}
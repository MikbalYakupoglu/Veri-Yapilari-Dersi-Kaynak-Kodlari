#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

int TamSayiyiCevir(long tamsayi, int yazdir);
void KalaniCevir(double kalan);

int* mantisa;
int mantisaUzunlugu, exponentUzunlugu;
int mantisaBaslangic;

int main()
{
    double sayi;
    int secim;
    long tamSayi;
    double kalan;
    int exponent_bias;

    printf("1- Float\n2- Double\nSeciminizi Yapiniz : ");
    scanf("%d", &secim);

    if(secim == 1)
    {
        exponentUzunlugu = 8;
        mantisaUzunlugu = 23;
    }
    else if(secim == 2)
    {
        exponentUzunlugu = 11;
        mantisaUzunlugu = 52;
    }
    else
    {
        printf("\nGecersiz Deger Girdiniz.");
        return -1;
    }

    printf("Sayi Giriniz : (Sayiyi Noktali Olarak Ayiriniz) : ");
    scanf("%lf", &sayi);

    if(sayi >= 0)
    {
        printf("0 | ");
    }
    else
    {
        printf("1 | ");
        sayi *= -1;
    }

    tamSayi = (long)sayi;
    kalan = sayi - (long) sayi;
    exponent_bias = pow(2,exponentUzunlugu-1) - 1;


    int normalizeSayisi = TamSayiyiCevir(tamSayi, 0);
    int exponentDecimal = exponent_bias + normalizeSayisi;



    TamSayiyiCevir(exponentDecimal, 1);
    KalaniCevir(kalan);




    return 0;
}


int TamSayiyiCevir(long tamsayi, int yazdir)
{
    int sayac, i;
    long gecici;

    gecici = tamsayi;

    for(sayac = 0 ;; sayac++)
    {
        if(gecici < 2)
        {
            break;
        }
        gecici /= 2;
    }

    gecici = tamsayi;
    int* exponent = (int*)malloc(sizeof(int) * sayac);

    for(i = 0;; i++)
    {
        if(gecici < 2)
        {
            exponent[i] = gecici % 2;
            break; 
        }
        exponent[i] = gecici % 2;
        gecici /= 2; 
    }

    int j;
    if(yazdir == 1)
    {
        for (j = i; j >= 0 ; j--)
        {
            printf("%d ", exponent[j]);            
        }
        printf(" | ");        
    }
    else
    {
        mantisa = (int*) malloc(sizeof(int) * mantisaUzunlugu);
        int a = 0;
        for (j = i - 1; j >= 0; j--)
        {
            mantisa[a] = exponent[j];
            a++;
        }
        mantisaBaslangic = sayac;        
    }

    return sayac;
}

void KalaniCevir(double kalan)
{
    int i;

    for (i = mantisaBaslangic; i < mantisaUzunlugu; i++)
    {
        kalan *= 2;

        if(kalan >= 1)
        {
            kalan -= 1;
            mantisa[i] = 1;
        }
        else
        {
            mantisa[i] = 0;
        }
    }

    for(int j = 0; j < mantisaUzunlugu; j++)
    {
        printf("%d ", mantisa[j]);
    }
    
}
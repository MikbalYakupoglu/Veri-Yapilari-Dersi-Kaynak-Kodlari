#include <stdio.h>


int Arttir(int x){
    x++;
    return x;
}

void Degistir(int* x, int* y){
    int gecici;
    gecici = *x;
    *x = *y;
    *y = gecici;
}

int Faktoriyel(int sayi)
{
    if(sayi == 0)
    {
        return 1;
    }
    else if(sayi < 0)
    {
        return -1;
    }
    else
    {
        int sonuc = 1;
        while(sayi > 1)
        {
            sonuc *= sayi;
            sayi--;
        }

        return sonuc;
    }
}

int RecursiveFaktoriyel(int sayi)
{
    if(sayi == 0)
    {
        return 1;
    }
    else if(sayi < 0)
    {
        return -1;
    }
    else
    {
        return sayi * RecursiveFaktoriyel(sayi - 1);
    }
}

int sayac = 0;

int RecursiveBolucu(int sayi, int bolen)
{
    if(bolen == 0)
    {
        return -1;
    }
    else if(sayi < bolen)
    {
        return sayac;
    }
    else
    {
        sayac++;
        sayi -= bolen;
        RecursiveBolucu(sayi, bolen);
    }
}

int RecursiveBolme(int x, int y)
{
    if(y == 0)
        return -1;

    else if(x < y)
        return 0;

    return 1 + RecursiveBolme(x-y, y);
}


int main()
{
/*
    int a = 5;
    int b = Arttir(a);


    printf("a : %d",a);
    printf("\nb : %d",b);
*/



/*
    int x = 5;
    int y = 10;

    printf("x: %d", x);
    printf("\ny: %d", y);

    Degistir(&x, &y);

    printf("\n\nDegistir Sonrasi : ");
    printf("\nx: %d", x);
    printf("\ny: %d", y);
*/

/*
    int sayi = 5;
    printf("Sayi : %d",sayi );
    printf("\nFaktoriyel : %d",Faktoriyel(sayi));
*/

/*
    int sayi = 5;
    printf("Sayi : %d",sayi );
    printf("\nRecursive Faktoriyel : %d",RecursiveFaktoriyel(sayi));
*/

/*
    int sayi = 10;
    int bolen = 2;
    printf("Sayi : %d",sayi );
    printf("\nBolen : %d",bolen );
    printf("\nBolum : %d",RecursiveBolme(sayi, bolen));
*/

    return 0;
}
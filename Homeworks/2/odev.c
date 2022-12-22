#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define LENGHT 5


typedef struct Yolcu{
  int koltuk_no;
  char ad[50];
  char soyad[50];
} Yolcu;

typedef struct Otobus{
  int kapasite;
  Yolcu Yolcular[LENGHT];
  struct Otobus* sonrakiOtobus;
} Otobus;

Otobus* ilkOtobus = NULL;

int isFull(int t)
{
    if(t < LENGHT -1)
    {
        return -1;
    }
    else
    {
        printf("\nStack is Full");
        return 0;
    }
    
}

int isEmpty(int t)
{
    if(t < 0)
    {
        printf("\nStack is Empty.");
        return 1;
    }
    return 0;
}

void push(Yolcu* array, Yolcu yolcu, int *t)
{
    if(isFull(*t) == -1)
    {
        (*t)++;
        array[*t] = yolcu;

    }
}

void pop(Yolcu* array, int* t)
{
    if(isEmpty(*t) == 0)
    {
        // printf("\nCikarilan Eleman = %d\n", array[*t]);
        (*t)--;
    }
}

Yolcu top(Yolcu* array, int t)
{
    if(isEmpty(t) == 0)
    {
        return array[t];
    }
}

void printStack(Yolcu* array, int t)
{
    int tempT = t - 1;
    if(isEmpty(t) == 0)
    {
        for (int i = 0; i <= tempT; i++)
        {
            printf("\n%d nolu yolcu - Yolcu Adi : %s   -  Yolcu Soyadi : %s ", array[i].koltuk_no, array[i].ad, array[i].soyad);
        }
    }
}


void PrintList()
{
    if(ilkOtobus == NULL){
        printf("Liste Bos");
        return;
    }

    Otobus* temp;
    temp = ilkOtobus;
    while(temp != NULL)
    {
        // printf("%d ==> ", temp-> Yolcular); Yolcular tek tek yazılacak
        temp = temp->sonrakiOtobus;
    }    
}

void OtobusEkle()
{
    Otobus* temp = NULL;
    temp = (Otobus*)malloc(sizeof(Otobus)); //  + LENGHT * sizeof(Yolcu*)
    temp->kapasite = 0;
    temp->sonrakiOtobus = NULL;


    if(ilkOtobus == NULL){
        ilkOtobus = temp;
    }
    else{
        Otobus* p;
        p = ilkOtobus;
        while(p->sonrakiOtobus != NULL){
            p = p->sonrakiOtobus;
        }
        p->sonrakiOtobus = temp;
    } 

    temp->Yolcular[0].koltuk_no = 123;

}

int LengthList(){
    int count = 0;
    if(ilkOtobus == NULL)
        return count;

    Otobus* temp;
    temp = ilkOtobus;
    while(temp != NULL){
        temp = temp->sonrakiOtobus;
        count++;
    }
    return count;
}

Otobus* sonOtobus()
{
    Otobus* p;
    p = ilkOtobus;
    while(p->sonrakiOtobus != NULL){
        p = p->sonrakiOtobus;   
    }
    return p;
}


void YolcuEkle(int* mevcutOtobus, int* mevcutYolcu)
{
    if(*mevcutOtobus == LENGHT)
    {
        printf("Kontenjan Doldu.");
        return;
    }

    if(*mevcutYolcu == 0)
    {
        OtobusEkle();
    }

    char ad[50];
    char soyad[50];


    Otobus* otobus = sonOtobus();    

    otobus->Yolcular[*mevcutYolcu].koltuk_no = (*mevcutYolcu) + 1;
    printf("%d. Otobus %d. Yolcu = \n",(*mevcutOtobus) + 1, (*mevcutYolcu) + 1);

    printf("Yolcu Adini Giriniz : ");
    scanf("%s", ad);
    strncpy(otobus->Yolcular[*mevcutYolcu].ad, ad,50);


    printf("Yolcu Soyadini Giriniz : ");
    scanf("%s", soyad);
    strncpy(otobus->Yolcular[*mevcutYolcu].soyad, soyad,50);


    (*mevcutYolcu) += 1;
    otobus->kapasite = (*mevcutYolcu);
    if((*mevcutYolcu) > 4)
    {
        (*mevcutYolcu) = 0;
        (*mevcutOtobus) += 1;
    }
}

void YolculariYaz(int* mevcutYolcu)
{
    if(ilkOtobus == NULL)
    {
        printf("Yolcu Bulunamadi.");
        return;
    }

    int i = 1;
    Otobus* temp;
    temp = ilkOtobus;
    while(temp != NULL)
    {
        printf("\n\n%d. Otobus", i);
        printf("---------------------------------------");
        printStack(temp->Yolcular, temp->kapasite);

        temp = temp->sonrakiOtobus;
        i+= 1;
    }
}

void SecilenOtobusunYolculariniYazdir()
{
    int count = 1;
    int lenght = LengthList();
    int n;
    printf("\nYolcularini Istediginiz Otobusu Seciniz : ");
    scanf("%d",&n);
    if(n < 1){
        printf("\nGecersiz Deger");
        return;
    }
    if(n > lenght){
        printf("\nSecilen Otobus Bulunamadi.");
        return;
    }

    Otobus* p = ilkOtobus;
    while(count < n){
        if(p->sonrakiOtobus == NULL)
        {
            printf("Secilen Otobus Bulunamadi.");
            return;
        }
        p = p->sonrakiOtobus;
        count++;
    }
    
    printf("\n\n%d. Otobus", n);        
    printf("---------------------------------------");
    printStack(p->Yolcular, p->kapasite);
}

void KapasiteHesapla()
{
    int kapasite = 25;

    Otobus* p = ilkOtobus;
    while (p != NULL)
    {
        kapasite -= p->kapasite;
        p = p->sonrakiOtobus;
    }

    printf("\nKalan Kapasite : %d", kapasite);
}

int main()
{
    int mevcutOtobus = 0;
    int mevcutYolcu = 0;

    int secim;
    while(1)
    {
        printf("\n\n1- Yolcu Ekle\n2- Mevcut Yolculari Yazdir\n3- Otobuse Gore Yolculari Yazdir\n4- Kalan Kontenjani Hesapla\n0- Cikis\nSeciminizi Yapiniz : ");
        scanf("%d", &secim);

        switch (secim)
        {
        case 1:
            YolcuEkle(&mevcutOtobus, &mevcutYolcu);
            break;

        case 2:
            YolculariYaz(&mevcutYolcu);
            break;

        case 3:
            SecilenOtobusunYolculariniYazdir();
            break;

        case 4:
            KapasiteHesapla();
            break;

        case 0:
            exit(0);
            break;
        
        default:
            printf("Gecersiz Deger Girdiniz.");
            break;
        }
    }
    















    return 0;
}
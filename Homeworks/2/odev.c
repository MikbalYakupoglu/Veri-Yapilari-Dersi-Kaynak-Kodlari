#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGHT 5

struct Yolcu{
  int koltuk_no;
  char ad[50];
  char soyad[50];
};

struct Otobus{
  int kapasite;
  struct Yolcu Yolcular[LENGHT];
  struct Otobus* sonrakiOtobus;
};

struct Otobus* ilkOtobus = NULL;

int isFull(int t)
{
    if(t < LENGHT)
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
    if(t < 1)
    {
        printf("\nStack is Empty.");
        return 1;
    }
    return 0;
}

void push(struct Yolcu* array,struct Yolcu yolcu, int *t)
{
    if(isFull(*t) == -1)
    {
        array[*t] = yolcu;
    }
}

void printStack(struct Yolcu* array, int t)
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

void OtobusEkle()
{
    struct Otobus* temp = NULL;
    temp = (struct Otobus*)malloc(sizeof(struct Otobus)); //  + LENGHT * sizeof(Yolcu*)
    temp->kapasite = 0;
    temp->sonrakiOtobus = NULL;


    if(ilkOtobus == NULL){
        ilkOtobus = temp;
    }
    else{
        struct Otobus* p;
        p = ilkOtobus;
        while(p->sonrakiOtobus != NULL){
            p = p->sonrakiOtobus;
        }
        p->sonrakiOtobus = temp;
    } 
}

int LengthList()
{
    int count = 0;
    if(ilkOtobus == NULL)
        return count;

    struct Otobus* temp;
    temp = ilkOtobus;
    while(temp != NULL){
        temp = temp->sonrakiOtobus;
        count++;
    }
    return count;
}

struct Otobus* sonOtobus()
{
    struct Otobus* p;
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

    struct Yolcu eklenecekYolcu;
    struct Otobus* otobus = sonOtobus();    

    eklenecekYolcu.koltuk_no = (*mevcutYolcu) + 1;
    
    printf("%d. Otobus %d. Yolcu = \n",(*mevcutOtobus) + 1, (*mevcutYolcu) + 1);

    printf("Yolcu Adini Giriniz : ");
    scanf("%s", eklenecekYolcu.ad);

    printf("Yolcu Soyadini Giriniz : ");
    scanf("%s", eklenecekYolcu.soyad);  

    push(otobus->Yolcular, eklenecekYolcu, mevcutYolcu);

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
    struct Otobus* temp;
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


int main()
{
    int mevcutOtobus = 0;
    int mevcutYolcu = 0;

    int secim;
    while(1)
    {
        printf("\n\n1- Yolcu Ekle\n2- Mevcut Yolculari Yazdir\n0- Cikis\nSeciminizi Yapiniz : ");
        scanf("%d", &secim);

        switch (secim)
        {
        case 1:
            YolcuEkle(&mevcutOtobus, &mevcutYolcu);
            break;

        case 2:
            YolculariYaz(&mevcutYolcu);
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
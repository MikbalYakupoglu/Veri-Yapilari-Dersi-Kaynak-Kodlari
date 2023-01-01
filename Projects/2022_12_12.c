#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* nextLink; 
    struct Node* prevLink; 
};

struct Node* root = NULL;

void PrintList()
{
    if(root == NULL){
        printf("Liste Bos");
        return;
    }

    struct Node* p;
    p = root;
    while(p != NULL)
    {
        printf("%d ==> ", p-> data);
        p = p->nextLink;
    }    
}

void PrintListReverse()
{
        if(root == NULL){
        printf("Liste Bos");
        return;
    }

    struct Node* p = root;
    while(p->nextLink != NULL)
    {
        p = p->nextLink;
    }   

    while (p != NULL)
    {
        printf("%d ==> ", p->data);
        p = p->prevLink;
    }
    
}

int LengthList()
{
    if (root == NULL)
    {
        return 0;
    }
    
    int count = 1;
    struct Node* p = root;
    while(p->nextLink != NULL)
    {
        count++;
        p = p->nextLink;
    }
    return count;
}

void AddNode()
{
    struct Node* temp = NULL;
    temp = (struct Node*)malloc(sizeof(struct Node));
    printf("\nData Giriniz : ");
    scanf("%d", &temp->data);
    temp->nextLink = NULL;
    temp->prevLink = NULL;

    if(root == NULL){
        root = temp;
    }
    else{
        struct Node* p = root;
        while(p->nextLink != NULL){
            p = p->nextLink;
        }
        p->nextLink = temp;
        temp->prevLink = p;
    }    
}

void AddNodeAfter(){
    int count = 1;
    int lenght = LengthList();
    int n;
    printf("\nKacinci Elemandan Sonra Ekleyeceksiniz (0-Root): ");
    scanf("%d",&n);
    if(n < 0){
        printf("\nGecersiz Deger");
        return;
    }
    if(n > lenght){
        printf("\nListe Boyutu Yetersiz");
        return;
    }
    if(n == lenght){
        OtobusEkle();
        return;
    }

    struct Node* temp = NULL;
    temp = (struct Node*)malloc(sizeof(struct Node));
    int data;
    printf("\nData Giriniz : ");
    scanf("%d", &temp->data);

    if(n == 0){
        temp->nextLink = root;
        root->prevLink = temp;
        root = temp;
        return;
    }

    struct Node* p = root;
    while(count < n){
        p = p->nextLink;
        count++;
    }
    temp->prevLink = p;
    temp->nextLink = p->nextLink;
    p->nextLink->prevLink = temp;
    p->nextLink = temp;
}


int main()
{    
    int secim;
    while(1)
    {
        printf("\n\n1-Eleman Ekle\n2-Araya Eleman Ekle\n3-Liste Uzunlugunu Yazdir\n4-Elemanlari Yazdir\n5-Elemanlari Tersten Yazdir\n0-Cikis\nIslemi Seciniz : "); // poplist pushlist eklenecek
        scanf("%d", &secim);

        switch (secim)
        {
        case 1:
            AddNode();
            break;

        case 2:
            AddNodeAfter();
            break;

        case 3:
            printf("Liste Boyutu : %d", LengthList());
            break;

        case 4:
            PrintList();
            break;

        case 5:
            PrintListReverse();
            break;


        case 0:
            printf("Cikis Yaptiniz.");
            exit(0);
            break;

        default:
            printf("Gecersiz Secim");
            break;
        }
    }


    return 0;
}
#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node* link; 
};

struct Node* root = NULL;



void PrintList()
{
    if(root == NULL){
        printf("Liste Bos");
        return;
    }

    struct Node* temp;
    temp = root;
    while(temp != NULL)
    {
        printf("%d ==> ", temp-> data);
        temp = temp->link;
    }    
}

void OtobusEkle()
{
    struct Node* node = NULL;
    node = (struct Node*)malloc(sizeof(struct Node));
    printf("\nData Giriniz : ");
    scanf("%d", &node->data);
    node->link = NULL;

    if(root == NULL){
        root = node;
    }
    else{
        struct Node* p;
        p = root;
        while(p->link != NULL){
            p = p->link;
        }
        p->link = node;
    }    
}

int LengthList(){
    int count = 0;
    if(root == NULL)
        return count;

    struct Node* temp;
    temp = root;
    while(temp != NULL){
        temp = temp->link;
        count++;
    }
    return count;
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
    if(n == 0){
        // printf("\nRoot degismeli");
        struct Node* p = NULL;
        p = (struct Node*)malloc(sizeof(struct Node));
        int data;
        printf("\nData Giriniz : ");
        scanf("%d", &p->data);
        struct Node* rootAdress = root;
        root = p;
        root->link = rootAdress;
        return;
    }
    if(n == lenght){
        OtobusEkle();
        return;
    }
    if(n > lenght){
        printf("\nListe Boyutu Yetersiz");
        return;
    }


    struct Node* temp;
    temp = root;
    while(count < n){
        temp = temp->link;
        count++;
    }
    struct Node* p = NULL;
    p = (struct Node*)malloc(sizeof(struct Node));
    int data;
    printf("\nData Giriniz : ");
    scanf("%d", &p->data);
    p->link = temp->link;
    temp->link = p;
}

struct Node* top = NULL;


void pushList(){
    struct Node* temp = NULL;
    temp = (struct Node*)malloc(sizeof(struct Node));
    printf("\nData Giriniz : ");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if(top == NULL){
        top = temp;
    }
    else{
        temp->link = top;
        top = temp;
    }
}

void popList(){
    if(top == NULL){
        printf("Liste Bos");
        return;
    }

    struct Node* temp = NULL;
    temp = top;
    top = top->link;

    if(temp == NULL){
        printf("Liste Bos");
        top = NULL;
        return;
    }

    temp->link = NULL;
    free(temp);
}

void PrintList()
{
    if(top == NULL){
        printf("Liste Bos");
        return;
    }

    struct Node* temp;
    temp = top;

    while(temp != NULL)
    {
        printf(" <== %d", temp->data);
        temp = temp->link;
    }    
}

int main()
{

    int secim;
    while(1)
    {
        printf("\n1-Eleman Ekle\n2-Elemanlari Yazdir\n3-Liste Uzunlugunu Yazdir\n4-Araya Eleman Ekle\n5-Cikis\nIslemi Seciniz : "); // poplist pushlist eklenecek
        scanf("%d", &secim);

        switch (secim)
        {
        case 1:
            OtobusEkle();
            break;

        case 2:
            PrintList();
            break;

        case 3:
            printf("\nListe Boyutu : %d", LengthList());
            break;

        case 4:
            AddNodeAfter();
            break;

        case 5:
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
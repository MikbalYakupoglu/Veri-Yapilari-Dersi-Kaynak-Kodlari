#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * rigth;
    struct Node * left;
};

struct Node * root=NULL;
void Insert(int data){
    struct Node * temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->rigth=NULL;
    temp->left=NULL;
    if (root ==NULL){
        root=temp;
        
    }else{
        struct Node *p,*son;
        p=root;
        while(p){
            son=p;
            if (temp->data>p->data)
                p=p->rigth;
            else
               p=p->left; 
            
        }  
        if (temp->data>son->data)
            son->rigth=temp;
        else
            son->left=temp;
            
    }
}

int GetMin(){
    struct Node* temp;
    temp=root;
    if (root==NULL){
        printf("root Bos\n");
        return -1;
    }
    while (temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}

int GenMinRecurisve(struct Node * temp){
   if (temp==NULL){
       printf("root Bos");
       return -1;
   } 
   if (temp->left==NULL){
       return temp->data;
   }
   return GenMinRecurisve(temp->left);
   
}

int main()
{

    struct Node * temp;
   
    Insert(20);
    Insert(30);
    Insert(10);
    Insert(5);
    Insert(18);
     temp=root;
    printf("En Kucuk Deger=%d",GetMin());
    printf("\n**********\n");
    printf("En kucuk Recurive=%d",GenMinRecurisve(temp));

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
/*
    int dizi [10];
    int diziLenght = sizeof(dizi) / sizeof(dizi[0]);

    for (int i = 0; i < diziLenght; i++)
    {
        printf("%d. Elemani Giriniz : ", i+1);
        scanf("%d", &dizi[i]);
    }
    

    int enbuyuk = dizi[0];
    int temp;
    int *dizipointer = &dizi[0];

    for (int i = 0; i < diziLenght; i++)
    {
        for(int j = i+1; j <= diziLenght -1; j++)
        {
            if(dizi[i] > dizi[j])
            {
                temp = dizi[i];
                dizi[i] = dizi[j];
                dizi[j] = temp;
            }
        }
    }
    
    printf("\n");
    for (int i = 0; i < diziLenght; i++)
    {
        printf("%d ", *dizipointer);
        dizipointer++;
    }
    printf("\n\nEn Buyuk Sayi : %d", dizi[diziLenght]);
*/


/*
    int a [3][2] = {{1,2}, {3,6}, {5,7}};
    int b [3][2] = {1,2,3,4,5,6};

    
    printf("a: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");        
    }

    printf("\nb: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");        
    }
*/


/*
    int matris[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    printf("matris : %d", matris);
    printf("\n*(*(matris + 1)+2) : %d", *(*(matris + 1)+2)); 
    printf("\n*(*(matris) + 1) : %d", *(*(matris) + 1));
*/



    return 0;
}
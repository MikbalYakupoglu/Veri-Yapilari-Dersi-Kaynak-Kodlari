#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* right;
    struct Node* left;
};
struct Node* root = NULL;
void Preorder(struct Node* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(struct Node* root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}
void Postorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->data);
}

struct Node* Insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        struct Node *root = (struct Node*)malloc(sizeof(struct Node));
        root->data = data;
        root->left = root->right = NULL;
        return root;
    }
    else if (data > root->data)
    {
         root->right = Insert(root->right, data);
       
    }
    else
    {
         root->left = Insert(root->left, data);
    }
    return root;
}



int main()
{
  
    root = Insert(root, 20);
    root = Insert(root, 10);
    root = Insert(root, 30);
    root = Insert(root, 5);
    root = Insert(root, 18);
    root = Insert(root, 40);
    printf("Preorder:");
    Preorder(root);
    printf("\n");

    printf("Inorder:");
    Inorder(root);
    printf("\n");
    
    printf("Postorder:");
    Postorder(root);
    printf("\n");

}
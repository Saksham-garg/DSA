#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* create(){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node*));
    int c;
    printf("\nEnter the data(-1 for no node)");
    scanf("%d",&c);
    temp->data=c;
    if(c==-1){
        return 0;
    }
    else{
        printf("Enter the data for %d left node : ",c);
        temp->left=create();
        printf("Enter the data for %d right node: ",c);
        temp->right=create();
        return temp;
    }
}

void Inorder(struct node *root){
    if(root==0){
        return;
    }
    Inorder(root->left);
    printf("%d\t",root->data);
    Inorder(root->right);
}

void Postorder(struct node *root){
    if(root==0){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    printf("%d\t",root->data);
}

void preOrder(struct node *root){
    if(root==0){
        return;
    }
    printf("%d\t",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

int main(void){
    struct node *root;
    root=create();
    printf("\nInorder Traversal: ");
    Inorder(root);
    printf("\nPostorder Traversal: ");
    Postorder(root);
    printf("\nPreorder traversal: ");
    preOrder(root);
}
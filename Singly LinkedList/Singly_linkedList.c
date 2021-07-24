#include<stdio.h>
#include<stdlib.h>

void insert_begin();
void insert_last();
void insert_random();
void delete_begin();
void delete_last();
void delete_random();
void Display();

struct node{
    int data;
    struct node *link;
};
struct node *root;

void insert_begin(){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node *));
    printf("\nEnter the key: ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root==NULL){
        root=temp;
    }
    else{
        temp->link=root;
        root=temp;
    }
    printf("\nNode inserted");
}

void insert_last(){
    int key;
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node *));
    printf("\nEnter the key: ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root==NULL){
        root=temp;
        printf("\n Node inserted!!");
    }
    else{
        struct node *temp1=root;
        while(temp1->link!=NULL){
        temp1=temp1->link;
    }
        temp1->link=temp;
    }
    printf("Node inserted");    
}

void insert_random(){
    int loc;
    printf("\nEnter the location you want to insert: ");
    scanf("%d",&loc);
    int key;
    struct node *temp,*temp1=root;
    temp=(struct node *)malloc(sizeof(struct node *));
    printf("\nEnter the key: ");
    scanf("%d",&key);
    temp->data=key;
    for(int i=0;i<loc;i++){
        temp1=temp1->link;
        if(temp1==NULL){
            printf("\n Can't insert");
            return;
        }
    }
    temp->link=temp1->link;
    temp1->link=temp;
    printf("\n Node inserted!!");
}

void delete_begin(){
    struct node *temp=root;
    if(root==NULL){
        printf("\nList is Empty!!");
    }
    else if(root->link==NULL){
        root=NULL;
        printf("\n node Deleted!!");
    }
    else{
        root=root->link;
        temp->link=NULL;
        printf("\nNode Deleted!!");
        free(temp);
    }
}

void delete_last(){
    struct node *temp=root,*prev;
    if(root==NULL){
        printf("\n List is Empty");
        return; 
    } 
    if(root->link==NULL){
        root=NULL;
        printf("\n node Deleted!!");
        return;
    }
    while(temp->link!=NULL){
        prev=temp;
        temp=temp->link;
    }
    prev->link=NULL;
    printf("\nNode Deleted!!");
}

void delete_random(){
    int loc;
    printf("\n enter the locaation you want to delete");
    scanf("%d",&loc);
    struct node *temp=root,*prev;
    for(int i=0;i<loc;i++){
        prev=temp;
        temp=temp->link;
        if(temp==NULL){
            printf("\nCan't Delete");
            return;
        }
    }
    prev->link=temp->link;
    temp->link=NULL;
    printf("\n Node Deleted!!");    
}

void Display(){
    struct node *temp=root;
    if(temp==NULL){
        printf("\n List is empty!!");
    }
    else{
        while(temp!=NULL){
        printf("%d\t ",temp->data);
        temp=temp->link;
    }
    }
}

int main(void)  
{  
    int choice =0;  
    while(choice != 8)   
    {  
        printf("\n\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n  5.Delete from last\n6.Delete node after specified location\n7.Show\n8.Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:insert_begin();      
                break;  
            case 2:insert_last();         
                break;  
            case 3:insert_random();       
                break;  
            case 4:delete_begin();       
                break;  
            case 5:delete_last();        
                break;  
            case 6:delete_random();          
                break;   
            case 7:Display();        
                break;  
            case 8:exit(0);  
                break;  
            default:  
                printf("Please enter valid choice..");  
        }  
    }  
}  
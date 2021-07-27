#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *root=NULL;
struct node *head=NULL;

void insert_begin(){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node*));
    printf("\nEnter the key");
    scanf("%d",&temp->data);
    if(root==NULL){
        root=temp;
        head=temp;
    }
    else{
        temp->link=root;
        root=temp;
    }
    head->link=root;
    printf("\n Node Inserted!!");
}

void insert_last(){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node*));
    printf("\nEnter the key");
    scanf("%d",&temp->data);
    if(root==NULL){
        root=temp;
        head=temp;
    }
    else{
        head->link=temp;
        head=temp;
    }
    head->link=root;
    printf("\n Node Inserted!!");
}

void insert_random(){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node*));
    int loc;
    printf("\nEnter the location at which you want to insert : ");
    scanf("%d",&loc);
    if(loc==0){
        printf("\n Can't insert!!");
        return;
    }
    if(root==NULL){
        printf("\nEnter the key: ");
        scanf("%d",&temp->data);
        root=temp;
        head=temp;
    }
    else{
        printf("\nEnter the key: ");
        scanf("%d",&temp->data);
        struct node *ptr=root;
        struct node *ptr1=root;
        for(int i=0;i<loc;i++){
            ptr1=ptr;
            ptr=ptr->link;
            if(ptr==NULL){
                printf("\n Can't insert!!");
                return;
            }
        }
        ptr1->link=temp;
        temp->link=ptr;
    }
    printf("\n Node inserted!!");
}

void delete_begin(){
    struct node *temp=root;
    if(root==NULL){
        printf("\n List is empty!!");
        return;
    }

    else if(root->link==root){
        root=head=NULL;
        return;
    }

    else{
        root=root->link;
        temp->link=NULL;
    }
    printf("\nNode Deleted!!");
}

void delete_last(){
    if(root==NULL){
        printf("\n List is Empty!!");
        return;
    }

    else if(root->link==root){
        root=head=NULL;
        return;
    }

    else{
        struct node *temp=root;
        struct node *ptr;
        while(temp->link==root){
            ptr=temp;
            temp=temp->link;
        }
        ptr->link=root;
        ptr=head;
        temp->link=NULL;
    }
    printf("\n Node Deleted!!");
}

void delete_random(){
    int loc;
    if(root==NULL){
        printf("\nList is Empty");
        return;
    }
    printf("\n Enter the location you want to delete: ");
    scanf("%d",&loc);
    if(loc==1){
        printf("\nCan't delete begin!!");
        return;
    }
    else{
        struct node *ptr=root;
        struct node *before_ptr;
        for(int i=0;i<loc-1;i++){
            before_ptr=root;
            ptr=ptr->link;
            if(ptr==NULL){
                printf("\n Can't Delete!!");
                return;
            }
        }
        struct node *temp1=ptr;
        ptr=ptr->link;
        temp1->link=NULL;
        before_ptr->link=ptr;
    }
    printf("\n Node Deleted!!");
}

void Display(){
    struct node *temp;
    if(root==NULL){
        printf("\n List is Empty!!");
        return;
    }
    else{
        temp=root;
        do{
            printf("%d\t",temp->data);
            temp=temp->link;
        }while(temp!=root);
    }
}

int main(void)
{
   int choice=0;  
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


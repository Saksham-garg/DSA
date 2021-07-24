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
    struct node *next;
    struct node *prev;
};

struct node *root=NULL;

void insert_begin(){
    struct node *temp1;
    temp1=(struct node*)malloc(sizeof(struct node*));
    printf("\nEnter the key: ");
    scanf("%d",&temp1->data);
    temp1->prev=NULL;
    temp1->next=NULL;
    if(root==NULL){
        root=temp1;
    }
    else{
        root->prev=temp1;
        temp1->next=root;
        root=temp1;
    }
    printf("\n Node inserted!!");
}

void insert_last(){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node*));
    printf("\nEnter the key: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(root==NULL){
        root=temp;
    }
    else{
        struct node *ptr=root;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->prev=ptr;
    }
    printf("\nNode inserted!!");
}

void insert_random(){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node*));
    int loc;
    printf("\nEnter the location at which you want to insert : ");
    scanf("%d",&loc);
    if(root==NULL){
        printf("\nEnter the key: ");
        scanf("%d",&temp->data);
        root=temp;
        root->next=NULL;
    }
    else{
        struct node *ptr=root,*before_ptr;
        for(int i=0;i<loc;i++){
            before_ptr=ptr;
            ptr=ptr->next;
            if(ptr==NULL){
                printf("\nCan't insert!!");
                return;
            }
        }
        printf("\nEnter the key: ");
        scanf("%d",&temp->data);
        before_ptr->next=temp;
        temp->prev=before_ptr;
        temp->next=ptr;
        ptr->prev=temp;
    }
    printf("\n Node Inserted!!");
}

void delete_begin(){
    if(root==NULL){
        printf("\n List is Empty!!");
        return;
    }
    else if(root->next==NULL){
        root=NULL;
    }
    else{
        struct node *temp=root;
        root=root->next;
        temp->next==NULL;
    }
    printf("\n Node Deleted!!");
}

void delete_last(){
    if(root==NULL){
        printf("\n List is empty!!");
        return;
    }
    else{
        struct node *ptr=root,*before_ptr;
        if(ptr->next==NULL){
            root=NULL;
            printf("\n Node Deleted!!");
            return;
        }
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        before_ptr=ptr->prev;
        before_ptr->next=NULL;
        ptr->prev=NULL;
    }
    printf("\n Node Deleted!!");
}

void delete_random(){
    int loc;
    printf("\n Enter the location you want to delete: ");
    scanf("%d",&loc);
    if(root==NULL){
        printf("List is Empty!!");
        return;
    }
    if(loc==1){
        printf("\n Call Delete_begin");
        return;
    }
    else{
        struct node *ptr=root,*before_ptr;
        for(int i=0;i<loc-1;i++){
            before_ptr=ptr;
            ptr=ptr->next;
            if(ptr==NULL){
                printf("Can't delete!!");
                return;
            }
        }
        ptr->prev=NULL;
        ptr=ptr->next;
        ptr->prev=before_ptr;
        before_ptr->next=ptr;
        printf("\n Node Deleted!!");
    }
}

void Display(){
    struct node *ptr1=root;
    if(root==NULL){
        printf("List is empty!!");
        return;
    }
    else{
        while(ptr1){
            printf("%d\t",ptr1->data);
            ptr1=ptr1->next;
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
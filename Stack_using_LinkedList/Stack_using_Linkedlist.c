#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
int pop();
int push(); 
void Display();
void Length();
struct node{
    int data;
    struct node *link;
};
struct node *top=NULL;
struct node *next=NULL;
int length=0;
int push(){
    int key;
    printf("\n Enter the key: ");
    scanf("%d",&key);
    if(top==NULL){
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->data=key;
        temp->link=NULL;
        top=temp;
        next=temp;
        length++;
    }
    else{
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->data=key;
        temp->link=NULL;
        next->link=temp;
        next=temp;
        length++;
    }
}

int pop(){
    if(top==NULL){
        printf("Stack is underflow!!");
        return 1;
    }
    struct node *temp=top;
    struct node *previous;
    while(temp->link!=NULL){
        previous=temp;
        temp=temp->link;
    }
    printf("Popped Element : %d",next->data);
    previous->link=NULL;
    next=previous;
    length--;
}

void Length(){
    printf("\nLength of Stack : %d",length);
}

void Display(){
    if(top==NULL){
        printf("Stack is underflow!!");
        return;
    }
    struct node *temp=top;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->link;
    }
}

int main(void){
    int choice;
    do{
        printf("\n*******************Make Operations on Stack********************** ");
        printf("\nEnter your choice\n 1.Push\n2.pop\n3.Display\n4.Length\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:push();
                break;
            case 2: pop();
                break;
            case 3:Display();
                break;
            case 4: Length();
                break;
            default:
                printf("Invalid Choice!!");
        }
        printf("\nDo you want to Exit??\n 1---YES \n 0---NO");
        scanf("%d",&choice);
    }while(choice);
}

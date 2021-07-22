#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void pop();
void push(); 
void Display();
void Length();
struct node{
    int data;
    struct node *link;
};

struct node *root=NULL;
struct node *next=NULL;
int size;
void push(){
    int key;
    printf("\nEnter the key : ");
    scanf("%d",&key);
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node*));
    temp->data=key;
    temp->link=NULL;
    if(root==NULL){
        root=temp;
        next=temp;
        size++;
    }
    else{
        next->link=temp;
        next=temp;
        size++;
    }
}

void pop(){
    if(root==NULL){
        printf("Queue is Underflow!!");
        return;
    }
    struct node *temp;
    temp=root;
    root=root->link;
    temp->link=NULL;
    size--;
    free(temp);
}

void Display(){
    if(root==NULL){
        printf("Queue is UnderFlow!!");
        return;
    }
    struct node *temp=root;
    while(temp){
        printf("%d\t",temp->data);
        temp=temp->link;
    }
}

void Length(){
    printf("Length of Queue : %d",size);
}

int main(void){
    int n=5;
    int queue[n];
    int choice;
    do{
        printf("\n*******************Make Operations on Queue********************** ");
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
        printf("\nDo you want to Continue??\n 1---YES \n 0---NO");
        scanf("%d",&choice);
    }while(choice);
}



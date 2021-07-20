#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#define MAX 10
static int top=-1;
int stack[MAX];

void push(){
    if(top==(MAX-1)){
        printf("\nStack is overflow!!");
        return;
    }
    int key;
    printf("\nEnter the key:");
    scanf("%d",&key);
    stack[++top]=key;
    printf("Key added Succesfully");
}

int pop(){
    if(top==-1){
        printf("\nStack is underflow!!");
        return 1;
    }
    int data=stack[top];
    stack[top--]=INT_MIN;
    printf("Popped Value: %d",data);
    return data;
}

void Display(){
    if(top==-1){
        printf("\nStack is underflow!!");
        return;
    }
    printf("\nStack elements are: ");
    for(int i=0;i<=top;i++){
        printf("%d\t",stack[i]);
    }
}

int main(void){
    int choice;
    do{
        printf("\n*******************Make Operations on Stack********************** ");
        printf("\nEnter your choice\n 1.Push\n2.pop\n3.Display");
        scanf("%d",&choice);
        switch(choice){
            case 1:push();
                break;
            case 2: pop();
                break;
            case 3:Display();
                break;
            default:
                printf("Invalid Choice!!");
        }
        printf("\nDo you want to Exit??\n 1---YES \n 0---NO");
        scanf("%d",&choice);
    }while(choice);
}
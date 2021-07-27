#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int pop();
int push(); 
void Display();
void expand();

int Capacity=4;
int top=-1;
int stack[Capacity];


int push(){
    int key;
    printf("\nEnter the key:");
    scanf("%d",&key);
    if((Capacity-1)==(top)){
        expand();
    }
    stack[++top]=key;
}

void expand(){
    int newstack[Capacity<<1];
    for(int i=0;i<Capacity;i++){
        newstack[i]=stack[i];
    }
    stack=newstack;
    Capacity=Capacity<<1;
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
        printf("\n*******************Make Operations on Dynamic Stack********************** ");
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
        printf("\nDo you want to Continue??\n 1---YES \n 0---NO");
        scanf("%d",&choice);
    }while(choice);
}

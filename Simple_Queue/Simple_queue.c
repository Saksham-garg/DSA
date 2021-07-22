#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

int rear=0,front=0,size=0;

void push(int *queue,int n){
    if(rear==(n-1)){
        printf("Queue is Overflow!!");
        return;
    }
    int key;
    printf("\nEnter the key: ");
    scanf("%d",&key);
    queue[rear++]=key;
    size++;
}

int pop(int *queue){
    if(rear==front){
        printf("Queue is Underflow!!");
        return 1;
    }
    for(int i=0;i<rear;i++){
        queue[i]=queue[i+1];
    }
    queue[rear]=INT_MIN;
    rear--;
    size--;
}

void Display(int *queue){
    if(rear==front){
        printf("Queue is Underflow!!");
        return;
    }
    for(int i=front;i<rear;i++){
        printf("%d\t",queue[i]);
    }
}

void Length(){
    printf("Length of Queue : %d",size);
}
int main(void){
    int n=10;
    int queue[n];
    int choice;
    do{
        printf("\n*******************Make Operations on Stack********************** ");
        printf("\nEnter your choice\n 1.Push\n2.pop\n3.Display\n4.Length\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:push(queue,n);
                break;
            case 2: pop(queue);
                break;
            case 3:Display(queue);
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

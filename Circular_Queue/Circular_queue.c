#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int rear=-1,front=-1;
int size=0;
void push(int *queue,int n){
    int key;
    if(front==-1 && rear==-1){
        printf("\nEnter the key:");
        scanf("%d",&key);
        front=rear=0;
        queue[rear]=key;
        size++;
        return;
    }
    if((rear+1)%n==front){
        printf("Queue is Overflow!!");
        return;
    }
    printf("\nEnter the key:");
    scanf("%d",&key);
    rear=(rear+1)%n;
    queue[rear]=key;
    size++;
}

void pop(int *queue,int n){
    if(front==-1 && rear==-1){
        printf("Queue is UnderFlow!!");
        return;
    }
    if(rear==front){
        printf("Popped Element: %d",queue[front]);
        front=rear=-1;
        return;
    }
    printf("Popped Element: %d",queue[front]);
    queue[front]=INT_MIN;
    front=(front+1)%n;
    size--;
}

void Display(int *queue,int n){
    if(rear==front){
        printf("Queue is Underflow!!");
        return;
    }
    int i=front;
    while(i!=rear){
        printf("%d\t",queue[i]);
        i=(i+1)%n;
    }
    printf("%d",queue[rear]);
}

void Length(){
    printf("Length of Queue : %d",size);
}

int main(void){
    int n=5;
    int queue[n];
    int choice;
    do{
        printf("\n*******************Make Operations on Stack********************** ");
        printf("\nEnter your choice\n 1.Push\n2.pop\n3.Display\n4.Length\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:push(queue,n);
                break;
            case 2: pop(queue,n);
                break;
            case 3:Display(queue,n);
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

#include<stdio.h>
#include<stdlib.h>
int n,arr[]={};
void set_array();
void Linear_Search(int);

int main(){
    printf("Size of array: ");
    scanf("%d",&n);
    int arr[n],key;
    set_array();
    printf("\nEnter the number you want to search : ");
    scanf("%d",&key);
    Linear_Search(key);
}
void set_array(){  
    for(int i=0;i<n;i++){
        printf("\nEnter the %d number: ",i+1);
        scanf("%d",&*(arr+i));
    }
}

void Linear_Search(int key){
    int flag=1;
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            printf("\nKey Found at index %d",i);
            flag=0;
            break;
        }
    }
    if(flag){
        printf("Key not found!!");
    }
}
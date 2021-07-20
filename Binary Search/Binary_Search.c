#include<stdio.h>
#include<stdlib.h>
int Iterative_Binary_search(int,int *);
int Reccursive_Binary_search();
int main(){
    int n, *array;
    printf("Array length: ");
    scanf("%d",&n);
    array=(int *)calloc(n,sizeof(int));
    int result=Iterative_Binary_search(n,array);
    if(result<0){
        printf("Key not found!!");
    }
    else{
        printf("Key found at index: %d",result);
    }
}

int Iterative_Binary_search(int n,int *array){
    for(int i=0;i<n;i++){
        printf("\nEnter the %d number: ",i+1);
        scanf("%d",&array[i]);
    }
    int key;
    printf("\nEnter key you wanna search: ");
    scanf("%d",&key);
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(array[mid]==key){
            return mid;
        }
        else if(array[mid]<key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

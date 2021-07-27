#include<stdio.h>
#include<stdlib.h>

void Insertion_sort(int *array,int n){
    int min;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=1;j<n;j++){
            if(array[j]<array[min]){
                min=j;
            }
        }
        int temp=array[min];
        array[min]=array[i];
        array[i]=temp;
    }
}

int main(){
    int n,*arr;
    printf("\nEnter the size of an array: ");
    scanf("%d",&n);
    arr=malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        printf("\n Enter the %d element : ",i+1);
        scanf("%d",&arr[i]);
    }
    Insertion_sort(arr,n);
    printf("\n Sorted Array: ");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}
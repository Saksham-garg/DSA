#include<stdio.h>
#include<stdlib.h>

void Insertion_sort(int *array,int n){
    int j;
    for(int i=1;i<=n;i++){
        int temp=array[i];
        j=i-1;
        while(j>=0 && array[j]>temp){
            array[j+1]=array[j];
            j=j-1;
        }
        array[j+1]=temp;
    }
}

int main(void){
    int n;
    printf("Enter the number of elements in array: ");
    scanf("%d",&n);
    int *array;
    array=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        printf("\n Enter the %d element : ",i+1);
        scanf("%d",&array[i]);
    }
    Insertion_sort(array,n);
    printf("\nSorted array: ");
    for(int i=0;i<n;i++){
        printf("%d\t",array[i]);
    }
}
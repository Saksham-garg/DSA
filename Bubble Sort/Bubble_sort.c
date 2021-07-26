#include<stdio.h>
#include<stdlib.h>

void Bubble_sort(int *array,int n){
    int swapped=1;
    for(int j=0;j<n && swapped;j++){
        swapped=0;
        for(int i=0;i<n-1;i++){
            if(array[i]>array[i+1]){
                int temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
                swapped=1;
            }
        }
    }
}

int main(void){
    int n;
    printf("Enter the number of elmeents in array: ");
    scanf("%d",&n);
    int *array;
    array=(int *)calloc(n,sizeof(int));
    for(int i=0;i<n;i++){
        printf("\n Enter the %d element : ",i+1);
        scanf("%d",&array[i]);
    }
    Bubble_sort(array,n);
    printf("\nSorted array: ");
    for(int i=0;i<n;i++){
        printf("%d\t",array[i]);
    }
}
#include<stdio.h>
int Iterative_Binary_search(int,int *);
int Reccursive_Binary_search();
int main(){
    int n,array[];
    printf("Array length: ");
    scanf("%d",&n);
    Iterative_Binary_search(n,array);
}

int Iterative_Binary_search(int n,int *array){
    for(int i=0;i<n;i++){
        printf("Enter the %d number: ",i+1);
        scanf("%d",&*(array+1));
    }
    
}
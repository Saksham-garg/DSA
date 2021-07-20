// Keep in mind!!
// Searching list should be Sorted in Binary Searcg
// Time Complexity is O(log n)    Space Complexity is : O(1)
// Reccurence Relation of Binary Search is T(n) = T(n/2)+ theta(1) because we are always considering one half of the input\
// list and throwing out the otheer half.

#include<stdio.h>
#include<stdlib.h>
int Iterative_Binary_search(int,int *);
int Reccursive_Binary_search(int *,int , int, int);
int main(){
    int n, *array;
    printf("Array length: ");
    scanf("%d",&n);
    array=(int *)calloc(n,sizeof(int));
    int result=Iterative_Binary_search(n,array);
    // int array[6]={1,2,3,4,5,65};
    // int result=Reccursive_Binary_search(array,0,5,55);       Dry Run this code, Working Correctely
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

int Reccursive_Binary_search(int *array,int low,int high,int key){
    int mid=(low+high)/2;
    if(low>high){
        return -1;
    }
    if(array[mid]==key){
        return mid;
    }
    else if(array[mid]<key){
        return Reccursive_Binary_search(array,mid+1,high,key);
    }
    else{
        return Reccursive_Binary_search(array,low,mid-1,key);
    }
}
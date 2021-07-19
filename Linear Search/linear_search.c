// Time Complexity of Linear Search is O(n), as in the Worst case we have to searh whole array
// Space complexity of Linear Search is O(1)

// Linear Search can be of two types:
//   1. Unordered Linear Search
//   2. Ordered Linear Search

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

// Function for Ordered Linear Search
// Here also time complexity is O(n) but in average case it reduces 
// the complexity even though the growth rate is same
int O_linear_Srh(int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            printf("Key found at index %d",i);
            return 1;
        }
        else if(arr[i]>key){
            printf("Key not found!!");
            return;
        }
    }
    return -1;
}
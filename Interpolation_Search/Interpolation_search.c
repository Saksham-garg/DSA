//Points to be Noted:
// Searching array must be in Sorted Order and it may oy may not be in uniform distributed manner.
// If array is in Uniformly distributed manner then searching will take on one step 
// If array is not in Uniformly distributed manner then searching will take more steps is more than Binary Search.

#include<stdio.h>
#include<stdlib.h>

int Interpolation(int *arr,int n){
    int key;
    printf("Enter the key to Search: ");
    scanf("%d",&key);
    int low=0,high=n-1;
    while(low<=high && key>=arr[low] && key<=arr[high]){
        if(arr[low]==key){
            return low;
        }
        int pos=low+ (key-arr[low])*(high-low)/(arr[high]-arr[low]);
        if(arr[pos]==key){
            return pos;
        }
        else{
            if(arr[pos]<key){
                low=pos+1;
            }
            else{
                high=pos-1;
            }
        }
    }
    return -1;
}
// Time Complexity: O(log2(log2 n)) for the average case, and O(n) for the worst case (when items are distributed exponentially)
// Space Complexity: O(1)
int main(){
    //Remember the uniform distribution of array elements i.e differece between each consective elements must be equal.
    int array[]={1,3,5,6,7,9};
    int n=sizeof(array)/sizeof(array[0]);
    int result=Interpolation(array,n);
    if(result==-1){
        printf("Key not found!!");
    }
    else{
        printf("Key found at index : %d",result);
    }
}
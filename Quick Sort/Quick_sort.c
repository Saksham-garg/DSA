#include<stdio.h>
#include<stdlib.h>

int Partition(int *array,int lb,int ub){
    int pivot=array[lb];
    int start=lb,end=ub;
    while(start<end){
        while(array[start]<=pivot){
            start++;
        }
        while(array[end]>pivot){
            end--;
        }
        if(start<end){
            int tem=array[start];
            array[start]=array[end];
            array[end]=tem;
        }
    }
    int temp=array[end];
    array[end]=array[lb];
    array[lb]=temp;
    return end;
}

void Quick_sort(int *array,int lb,int ub){
    if(lb<ub){
        int loc= Partition(array,lb,ub);
        Quick_sort(array,lb,loc-1);
        Quick_sort(array,loc+1,ub);
    }
}

int main(void){
    int array[]={7,4,9,1,3,7,4};
    int size=sizeof(array)/sizeof(int);
    Quick_sort(array,0,size-1);
    for(int i=0;i<size;i++){
        printf("%d\t",array[i]);
    }
}   
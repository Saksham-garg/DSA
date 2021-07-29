#include<stdio.h>
#include<stdlib.h>

void merge(int *array,int lb,int mid,int ub){
    int i=lb,j=mid+1;
    int k=0;
    int b[ub-lb +1];
    while(i<=mid && j<=ub){
        if(array[i]<=array[j]){
            b[k]=array[i];
            i++;
        }
        else{
            b[k]=array[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){
            b[k]=array[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
            b[k]=array[i];
            i++;
            k++;
        }
    }
    for(int z=lb;z<=ub;z++){
        array[z]=b[z-lb];
    }
}

void MergeSort(int *array,int lb,int ub){
    if(lb<ub){
        int mid=(lb+ub)/2;
        MergeSort(array,lb,mid);
        MergeSort(array,mid+1,ub);
        merge(array,lb,mid,ub);
    }
}

int main(void){
    int array[]={6,2,5,8,1,9};
    MergeSort(array,0,5);
    for(int i=0;i<=5;i++){
        printf("%d\t",array[i]);
    }
}

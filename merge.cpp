#include<iostream>
using namespace std;

void merge(int arr[],int p,int q,int r){
        int B[100];
        int i=p;
        int j =q+1;
        int k=p;

        while(i<=q && j<=r){
            if(arr[i]<= arr[j]){
                B[k++] = arr[i++];
            }
            else{
                B[k++] = arr[j++];
            }
        while(i=q){
            B[k++] = arr[i++];
        }
        while(j=r){
            B[k++]=arr[j++];
        }
        for(i =p;i<r;i++){
            arr[i]=B[i];
        }
        }
    }


void merge_sort(int arr[],int p,int r){
    if(p<r){
        int q=(p+r)/2;
        merge_sort(arr,p,q);
        merge_sort(arr,q+1,r);
        merge(arr,p,q,r);
    }
}
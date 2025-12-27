#include<iostream>
using namespace std;

void insert( arr[],int n){
    for(int i= 1;i<n;i++){
        int key =arr[i];
        int j =i-1;
        while(j>0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main(){
int arr[]={1,87,45,3,4,6,6,6,4,53,5,76,6,7,68,8,45,3}
int n= sizeof(arr)/sizeof(arr[0])
}
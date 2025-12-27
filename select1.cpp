#include<iostream>
using namespace std;
void select(int arr[],int n){
    for(int i =0;i<n;i++){
        int small = i;
        for(int j =i+1;j<n;j++){
            if(arr[i]>arr[j]){
                small =j;
            }
            if(arr[i]>arr[small]){
                swap(arr[i],arr[small]);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[]={1223213,4,34,13,13,534,3,56456,23};
    int n = sizeof(arr)/sizeof(arr[0]);
    select(arr,n);
}
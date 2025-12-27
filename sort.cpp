#include<iostream>
using namespace std;

void quicksort(int arr[], int left, int right){
    int i = left, j = right;
    int temp;
    int pivot = arr[(left+right)/2];
    while(i<=j){
        while(arr[i]<pivot)
        i++;
        while(arr[j]> pivot)
        j--;
        if(i<=j){
            temp = arr[i];
            arr[i]=arr[j];
            arr[j]= temp;
            i++;
            j--;
        }
    }
    if(left<j)
    quicksort(arr,left,j);
    if(i<right)
    quicksort(arr,i,right);



}

int main()
{
    int arr[10]={24,9,67,45,67,78,89,34,2,3};
     quicksort(arr,3,24);


    for(int i=0;i<9;i++){
        cout<<arr[i];
        cout<<" ";
    }
}
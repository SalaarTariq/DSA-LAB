#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j;
        }
        arr[j] = key;
    }
}

int main(){
    int arr[] ={10,2,34,1,5};
    int n = 5;
    insertionSort(arr, n);
   
}
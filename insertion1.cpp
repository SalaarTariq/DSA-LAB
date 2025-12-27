#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];       
        int j = i - 1;          
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
for(int i = 0; i < n; i++){
         cout<<arr[i]<< " ";
        }
}

int main(){
    int arr[] = {12, 31, 41, 37, 49, 45, 69, 2, 56,76,67, 98, 52};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
}

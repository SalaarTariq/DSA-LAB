#include <iostream>
using namespace std;

int partition(int arr[], int start, int end){
    int pivot = arr[end - 1];  
    int idx = start - 1;        

    for(int i = start; i < end - 1; i++){
        if(arr[i] < pivot){  
            idx++;
            int temp = arr[idx];
            arr[idx] = arr[i];
            arr[i] = temp;
        }
    }
    idx++;
    int temp= arr[idx];
    arr[idx] =pivot;
    arr[end - 1]= temp;

    return idx;
}

void quick_sort(int arr[], int start, int end){
    if (start < end - 1){ 
        int partition_index = partition(arr, start, end);
        quick_sort(arr, start, partition_index);
        quick_sort(arr, partition_index + 1, end);
        }
}

int main(){
    int arr[16] = {10,34,45,33,23,47,31,23,45,69,2,56,7,67,88,42};
    int len = 16;

    quick_sort(arr, 0, len);


    for(int i = 0; i < len; i++) {
        cout << arr[i]<< " ";
    }
}

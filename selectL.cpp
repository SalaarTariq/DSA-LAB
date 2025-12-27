#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    int passes = 0;
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++)
            if(arr[j] < arr[minIndex]){
            minIndex = j;}
        swap(arr[i], arr[minIndex]);
        passes++;
    }
    cout<< "Total passes " <<passes <<endl;
}

int main() {
    int arr[] = {34,45,2,6,1,8};
    int n = 6;
    selectionSort(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";  
      }
}

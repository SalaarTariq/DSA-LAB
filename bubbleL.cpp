#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    int comparison = 0, swapp = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            comparison++;
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapp++;
            }
        }
    }
    cout << "Comparison: "<< comparison<<" Swaps " <<swapp<<endl;
  }
int main() {
    int arr[] = {10,2,1,4,3,6};
    int n = 6;
    bubbleSort(arr, n);
     for(int i=0;i<n;i++) cout<<arr[i]<<" ";

}
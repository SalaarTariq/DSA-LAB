#include <iostream>
#include <ctime> 
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high){
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {23,1,43,2,45,4,3,12};
    int n = sizeof(arr) / sizeof(arr[0]);

    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t stop = clock();
    double duration = double(stop - start) / CLOCKS_PER_SEC;

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    cout << "Execution time: " << duration << " seconds" << endl;
}

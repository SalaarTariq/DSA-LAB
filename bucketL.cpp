#include <iostream>
using namespace std;
void insertionSort(float arr[], int n){
    for(int i = 1; i < n; i++){
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n){
    float buckets[10][10]; 
    int bucketCount[10] = {0}; 

    for (int i = 0; i < n; i++) {
        int idx = n * arr[i];
        if (idx >= 10) idx = 9;
        buckets[idx][bucketCount[idx]++] = arr[i];
    }

    for (int i = 0; i < n; i++)
        if (bucketCount[i] > 0)
            insertionSort(buckets[i], bucketCount[i]);

    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < bucketCount[i]; j++)
            arr[index++] = buckets[i][j];
}

int main() {
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

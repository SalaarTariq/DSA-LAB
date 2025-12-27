#include <iostream>
#include <vector>
#include <algorithm>  
#include <chrono>     
using namespace std;
using namespace std::chrono;
void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);}}}
void printSample(const vector<int> &arr) {
    for (int i = 0; i < min(10, (int)arr.size()); i++)
        cout << arr[i] << " ";
    cout << "...\n";}
int main() {
    int n = 10000; 
    vector<int> data(n);
for (int i = 0; i < n; i++)
        data[i] = rand() % 10000;
    vector<int> arr1 = data; // Bubble Sort
    vector<int> arr2 = data; // std::sort
    vector<int> arr3 = data; // std::stable_sort
    cout << "=== Sorting Performance Comparison ===\n";
    cout << "Array size: " << n << "\n\n";
    auto start1 = high_resolution_clock::now();
    bubbleSort(arr1);
    auto end1 = high_resolution_clock::now();
    auto time1 = duration_cast<milliseconds>(end1 - start1);
    cout << "Bubble Sort time: " << time1.count() << " ms\n";
    auto start2 = high_resolution_clock::now();
    sort(arr2.begin(), arr2.end());
    auto end2 = high_resolution_clock::now();
    auto time2 = duration_cast<milliseconds>(end2 - start2);
    cout << "std::sort time: " << time2.count() << " ms\n";
    auto start3 = high_resolution_clock::now();
    stable_sort(arr3.begin(), arr3.end());
    auto end3 = high_resolution_clock::now();
    auto time3 = duration_cast<milliseconds>(end3 - start3);
    cout << "std::stable_sort time: " << time3.count() << " ms\n\n";
    cout << "First 10 sorted elements (std::sort): ";
    printSample(arr2);
}

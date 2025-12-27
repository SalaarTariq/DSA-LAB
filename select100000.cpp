#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void selectionSort(int arr[], int n) {
for (int i = 0; i < n - 1; i++) {
int minIndex = i;
for (int j = i + 1; j < n; j++) {
if (arr[j] < arr[minIndex]) minIndex = j;
}
swap(arr[i], arr[minIndex]);
}
}

int main() {
const int n = 100000;
int arr[n];
for (int i = 0; i < n; i++) arr[i] = rand() % 10000;
auto start = high_resolution_clock::now();
selectionSort(arr, n); // Replace with any sort
auto stop = high_resolution_clock::now();
auto duration = duration_cast<milliseconds>(stop - start);
cout << "Execution Time: " << duration.count() << " ms" << endl;
}
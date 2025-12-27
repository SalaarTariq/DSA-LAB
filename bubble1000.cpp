#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void bubbleSort(int arr[], int n) {
for (int i = 0; i < n - 1; i++) {
bool swapped = false;
for (int j = 0; j < n - i - 1; j++) {
if (arr[j] > arr[j + 1]) {
swap(arr[j], arr[j + 1]);
swapped = true;
}
}
if(!swapped) break; // optimization
}
}


int main() {
const int n = 1000;
int arr[n];
for (int i = 0; i < n; i++) arr[i] = rand() % 10000;
auto start = high_resolution_clock::now();
bubbleSort(arr, n); // Replace with any sort
auto stop = high_resolution_clock::now();
auto duration = duration_cast<milliseconds>(stop - start);
cout << "Execution Time: " << duration.count() << " ms" << endl;
}
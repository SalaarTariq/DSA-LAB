#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal) maxVal = arr[i];
    return maxVal;
}

void countingSortForRadix(int arr[], int n, int exp) {
    int* output = new int[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    delete[] output;
}

void radixSort(int arr[], int n) {
    int maxVal = getMax(arr, n);
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSortForRadix(arr, n, exp);
}

int main() {
    const int n = 100000;
    int arr[n];
    for (int i = 0; i < n; i++) arr[i] = rand() % 10000;

    auto start = high_resolution_clock::now();
    radixSort(arr, n);
    auto stop = high_resolution_clock::now();

    cout << "Execution Time (Radix Sort): "
         << duration_cast<milliseconds>(stop - start).count() << " ms" << endl;
}

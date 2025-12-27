#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

int main() {
    const int n = 100000;
    int arr[n];
    for (int i = 0; i < n; i++) arr[i] = rand() % 10000;

    auto start = high_resolution_clock::now();
    shellSort(arr, n);
    auto stop = high_resolution_clock::now();

    cout << "Execution Time (Shell Sort): "
         << duration_cast<milliseconds>(stop - start).count() << " ms" << endl;
}

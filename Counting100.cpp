#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void countingSort(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal) maxVal = arr[i];

    int* count = new int[maxVal + 1]();
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    int index = 0;
    for (int i = 0; i <= maxVal; i++)
        while (count[i]--)
            arr[index++] = i;

    delete[] count;
}

int main() {
    const int n = 100000;
    int arr[n];
    for (int i = 0; i < n; i++) arr[i] = rand() % 10000;

    auto start = high_resolution_clock::now();
    countingSort(arr, n);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Execution Time (Counting Sort): " << duration.count() << " ms" << endl;
}

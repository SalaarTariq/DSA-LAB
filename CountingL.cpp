#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int> &arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    vector<int> count(maxVal + 1, 0);
    for (int num : arr)
        count[num]++;
    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i]-- > 0)
            arr[index++] = i;
    }
}

int main() {
    vector<int> arr = {12,334,1,23,5,34,1,1,1};
    countingSort(arr);
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}

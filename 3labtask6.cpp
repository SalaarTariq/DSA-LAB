#include <iostream>
using namespace std;

int findRotations(int arr[], int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++){
        if (arr[i] < arr[minIndex]){
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    int arr[6] = {9, 10, 2, 5, 6, 8};
    int result = findRotations(arr, 6);
    cout<< "The array is rotated "<< result<< " times" << endl;
}

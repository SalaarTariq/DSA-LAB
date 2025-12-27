#include <iostream>
using namespace std;

int main() {
    int arr[10] ={1,2,3,4,5,6,7,8,9,10};
    int key;
    int size = 10;
    int start = 0;
    int end = size - 1;
    bool found = false;

    cout <<"Enter key to search: ";
    cin >>key;

    while(start <= end){
        int mid = (start + end) /2;

        if (arr[mid] == key){
            cout << "Index: " << mid <<endl;
            found = true;
            break;
        }
        else if (arr[mid] < key) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    if(!found){  
        cout <<"Key not found" <<endl;
    }
}

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 4, 6, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout<<"Enter a number: ";
    cin>>key;

    int floorVal = -1, ceilVal = -1;

    for(int i = 0; i < n; i++){
        if(arr[i] == key){
            floorVal = ceilVal = arr[i];
        break;
        }
        else if(arr[i] < key){
        floorVal = arr[i];  
        }
        else if(arr[i] > key && ceilVal == -1){
        ceilVal = arr[i]; 
        break;
        }
    }

    if (floorVal != -1){
    cout << "Floor: " << floorVal << endl;}
    else{
    cout << "No Floor exists" << endl;}

    if (ceilVal != -1){ 
    cout << "Ceil: " << ceilVal << endl;}
    else{
    cout << "No Ceil exists" << endl;}


}

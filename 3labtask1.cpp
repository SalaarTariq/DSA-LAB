#include<iostream>
using namespace std;
void Search(int arr[],int size,  int key){
    bool found = false;
    for(int i= 0; i<size; i++){
        if(key == arr[i]){
            cout<<"Key found at index: "<<arr[i];
            break;
        }
    } 
    if (found != true){
        cout<<"Key not found";
    }
}

int main(){
int arr[10]={1,2,3,4,5,6,7,8,9,10};
Search(arr,10,11);
}
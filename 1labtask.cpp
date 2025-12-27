#include<iostream>
using namespace std;
int main(){
    int arr[10] = {80,72,93,87,90,55,66,74,69,56};

    for(int i = 0; i < 10; i++){
        if (arr[i] >= 90){
            cout << "A Grade" << endl;
        }
        else if (arr[i] >= 81 && arr[i] < 90){
            cout << "B+ grade" << endl;
        }
        else if (arr[i] >= 70 && arr[i] < 81){
            cout << "B grade" << endl;
        }
        else if (arr[i] >= 60 && arr[i] < 70){
            cout << "C grade" << endl;
        }
        else if (arr[i] >= 50 && arr[i] < 60){
            cout << "D grade" << endl;
        }
        else{
            cout << "F grade" << endl;
        }
    }
}
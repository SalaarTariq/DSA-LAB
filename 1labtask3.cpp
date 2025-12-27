#include<iostream>
using namespace std;
int main(){
    int arr[10];
    cout<<"Please enter any 10 numbers: "<<endl;
    for(int i =0; i < 10; i++){
        cin>>arr[i];
    }
    cout<<"Element     Value     Diagram"<<endl;
    for(int j = 0; j< 10;j++){
        cout<<j<< "\t     " << arr[j] << "\t       " ;
        for(int k = 0; k< arr[j];k++){
            cout<<"*";
        }
        cout<<endl;
        
    }
}
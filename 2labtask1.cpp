#include<iostream>
using namespace std;

void convert(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    cout<<"Give first value: ";
    int a;
    cin>>a;
    cout<<"Give second value: ";
    int b;
    cin>>b;
    
    convert(&a, &b);
    cout<<"First value: "<<a<<endl;
    cout<<"Second value: "<<b;
}
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
    
    cout<<"Before swap"<<endl;
    cout<<" a = " << a<< " b = "<< b<<endl;
    convert(&a, &b);
    cout<<"After swap"<<endl;
    cout<<" a = " << a<< " b = " << b <<endl;
    
}
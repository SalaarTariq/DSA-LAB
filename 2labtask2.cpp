#include<iostream>
using namespace std;

void convert(float* fahrenheit){
    float celsius = (*fahrenheit - 32) * (5.0/9.0);
    cout<<"Temperature in Celsius is: "<<celsius;
}

int main(){
    float f;
    cout<<"Enter the value of Fahrenheit: ";
    cin>>f;

    convert(&f);
}
#include<iostream>
using namespace std;
int reverse(int n,int rev=0){
    
    if(n==0){
        return rev;
    }
    return reverse(n/10,rev*10+(n%10));
}

int main(){
int n;
cout<<"Enter a number: ";
cin>>n;
cout<<"Reversed number : "<<reverse(n);
}
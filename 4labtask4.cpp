#include<iostream>
using namespace std;

int gcd(int a,int b){
    if(b==0){
return a;
}
return gcd(b, a%b);
    }
int main(){
    cout<<"Enter two numbers: ";
    int a, b;
    cin>>a;
    cin>>b;
double result =gcd(a,b);
cout<<"The GCD is "<<result;

}
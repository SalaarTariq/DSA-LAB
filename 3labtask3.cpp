#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 0){
    return 0;}
    if (n == 1){ 
    return 1;}
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int sumFibonacci(int n) {
    if (n == 0) return 0;
    return fibonacci(n) + sumFibonacci(n - 1);
}

int main() {
    int n;
    cout<<"Enter number of terms: ";
    cin>>n;

    int sum =sumFibonacci(n);
    cout<<"Sum of first "<<n<< " Fibonacci numbers = " << sum<<endl;

}

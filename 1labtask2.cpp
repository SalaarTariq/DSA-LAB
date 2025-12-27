#include<iostream>
using namespace std;
 double Dmax( double arr[] , int size){
       double max =  arr[0];

       for(int i = 0; i< size;i++){
        if(max < arr[i]){
            max = arr[i];
        }
       }  
       return max;
        }

 double Dmin( double arr[] , int size){
       double min =  arr[0];

       for(int i = 0; i< size;i++){
        if(min > arr[i]){
            min = arr[i];
        }
       }  
       return min;
 }
int main(){
    double arr[10];
    cout<<"Enter 10 numbers ";
    for(int i = 0; i< 10;i++){
        cin>>arr[i];
    }
    cout <<"Max: " <<Dmax(arr ,10)<<endl;
    cout<<"Min: "<< Dmin(arr ,10)<<endl;


}
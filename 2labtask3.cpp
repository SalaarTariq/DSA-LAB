#include<iostream>
using namespace std;

struct Student{
    char name[20];
    int roll;
    float GPA;

};
int main(){
    Student S1;
    cout<<"Kindly tell your name: ";
    cin>> S1.name;
    cout<<"Enter your roll num: ";
    cin>> S1.roll;
    cout<<"Enter your GPA: ";
    cin>>S1.GPA;
    cout<< "Name: "<< S1.name<< endl;
    cout<< "Roll: "<< S1.roll <<endl;
    cout <<"Marks: " <<S1.GPA <<endl;
}

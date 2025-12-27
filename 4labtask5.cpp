#include<iostream>
using namespace std;
bool palind(string str,int strt,int end){
    if(strt >= end){
        return true;
}
    if(str[strt] != str[end]){
        return false;
    }
return palind(str,strt +1,end-1);
}
int main(){
string word;
cin>>word;
if (palind(word,0,word.length()-1) == false){
    cout<<"Not palindrome";
}
else{
    cout<<"Palindrome";
}
}
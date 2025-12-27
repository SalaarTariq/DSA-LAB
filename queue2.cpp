#include <iostream>
using namespace std;

int main() {
    int H, C, Q;
    cin>>H>>C>>Q;
    int height[C], start[C], end[C];
    for(int i = 0; i < C; i++){
        cin>>height[i]>>start[i]>>end[i];
    }
    for(int i = 0; i < Q; i++){
        int person_height, entry_time;
        cin>>person_height>>entry_time;
        bool can_enter = true;
        for(int j = 0; j < C; j++){
            if(entry_time >= start[j] && entry_time <= end[j]){
                if(person_height <= height[j]){
                    can_enter = false;
                    break;
                }
            }
        }
        if(can_enter){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
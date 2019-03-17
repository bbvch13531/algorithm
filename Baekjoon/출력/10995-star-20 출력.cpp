// https://www.acmicpc.net/problem/10995 별찍기-20

#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>>N;

    for(int i = 0; i < N; i++){
        if(i % 2 == 0){
            for(int j = 0; j<N; j++){
                cout<<"*";
                cout<<" ";
            }
            cout<<"\n";
        }
        
        else {
            for(int j = 0; j<N; j++){
                cout<<" ";
                cout<<"*";
            }
            cout<<"\n";
        }
    }
    return 0;
}
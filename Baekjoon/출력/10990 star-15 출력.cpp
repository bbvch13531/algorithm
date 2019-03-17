#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>>N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N - i - 1; j++){
            cout<<" ";
        }

        cout<<"*";

        if(i!=0){
            for(int j = 0; j < 2 * i - 1; j++){
                cout<<" ";
            }         
            cout<<"*";   
        }
        cout<<"\n";
    }
    return 0;
}
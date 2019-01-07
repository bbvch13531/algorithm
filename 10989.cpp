#include <iostream>

using namespace std;

int main(int argc, char** argv){
    int index[10010]={0,};
    int N,num;

    cin>>N;

    for(int i=0; i<N; i++){
        cin>>num;
        index[num]++;
    }
    
    // for(int i=1; i<N; i++){
    //     index[i]+=index[i-1];
    // }

    for(int i=1; i<=10000; i++){
        for(int j=0; j<index[i]; j++){
            cout<<i<<"\n";
        }
    }

    return 0;
}
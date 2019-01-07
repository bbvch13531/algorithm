#include <iostream>

using namespace std;

int arr[2000010];

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    
    int N,num;

    cin>>N;

    for(int i=0; i<N; i++){
        cin>>num;
        arr[num+1000000]++;
    }

    for(int i=0; i<=2000000; i++){
        for(int j=0; j<arr[i]; j++){
            cout<<i-1000000<<"\n";
        }
    }

    return 0;
}
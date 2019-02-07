#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> arr1,arr2;
int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M,buf;
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>buf;
        arr1.push_back(buf);
    }
    sort(arr1.begin(),arr1.end());
    cin>>M;
    for(int i=0; i<M; i++){
        cin>>buf;
        arr2.push_back(buf);
    }
    for(int i=0; i<M; i++){
        if(binary_search(arr1.begin(),arr1.end(),arr2[i])){
            cout<<"1 ";
        }
        else{
            cout<<"0 ";
        }
    }
    return 0;
}
/*
5
6 3 2 10 -10
8
10 9 -5 2 3 4 5 -10
*/
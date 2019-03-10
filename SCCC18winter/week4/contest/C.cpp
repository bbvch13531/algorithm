#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    vector <int> h;
    cin>>N;
    if(N!=0){
        h.resize(N);
        for(int i=0; i<N; i++){
            cin>>h[i];
        }
    }
 
    return 0;
}
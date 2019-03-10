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

    long long N,M;
    vector <long long> arr;
    cin>>N>>M;

    arr.resize(N);
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());


    return 0;
}
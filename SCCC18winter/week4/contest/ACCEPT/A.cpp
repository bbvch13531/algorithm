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

    int N,d1,d2,buf;
    vector <int> arr;

    for(int i=0; i<3; i++){
        cin>>buf;
        arr.push_back(buf);
    }
    sort(arr.begin(),arr.end());
    // for(int i=0; i<3; i++){
    //     cout<<arr[i]<<" ";
    // }
    d1 = arr[1] - arr[0];
    d2 = arr[2] - arr[1];

    if(d1 > d2){
        cout<< arr[0] + d2;
    }
    else if(d1 < d2){
        cout<< arr[1] + d1;
    }
    else cout<<arr[2]+d1;
    return 0;
}
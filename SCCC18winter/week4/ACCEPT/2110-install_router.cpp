#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

vector <int> arr;
int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,C,buf;
    int lo,hi,mid,cnt,d,cur,ans;

    cin>>N>>C;
    for(int i=0; i<N; i++){
        cin>>buf;
        arr.push_back(buf);        
    }
    sort(arr.begin(),arr.end());
    lo = 1;
    hi = arr[N-1] - arr[0];

    // 가장 인접한 거리를 mid로 하게 설치한다.
    // 설치한 공유기 갯수와 C를 비교한다.

    while(lo<hi){
        cnt = 1;
        mid = (lo + hi) / 2;

        // 가장 인접한 거리.
        cur = arr[0];

        for(int i=1; i<N; i++){
           d = arr[i] - cur;
           if(d >= mid){
               cnt++;
               cur = arr[i];
           }
        }
        // printf("%d %d %d %d\n",lo,mid,hi,cnt);
        if(cnt < C){
            hi = mid;
        }
        else{
            ans = mid;
            lo = mid + 1;
        }
       
    }
    cout<<ans;
    return 0;
}
/*
5 3
1 2 8 4 9

5 2
1 5 8 15 20
*/
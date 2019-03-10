#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> times;
int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M,buf;
    long long cnt,cur,d=0,maxD=0;
    long long lo,hi,mid;
    long long sum=0,ans;
    
    cin>>N>>M;

    for(int i=0; i<N; i++){
        cin>>buf;        
        times.push_back(buf);
    }
    // for(int i=0; i<N+1; i++){
    //     printf("%d ",acc[i]);
    // }
    sort(times.begin(),times.end());
    hi = 0x0000000fffffffff;
    lo = 0;

    while(lo < hi){
        maxD = cur = 0;
        cnt = 0;
        mid = (lo + hi) / 2;
        d = 0;
        for(int i=0; i<=N; i++){
            d += times[i];

            if(d > mid){
                cnt++;
                if(d>maxD){
                    maxD = d;
                }
                d = times[i];
            }
        }
        printf("%lld %lld %lld %lld %lld\n",lo,mid,hi,cnt,d);
        if(cnt < M){
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
9 3
1 2 3 4 5 6 7 8 9

7 6
100 400 300 100 500 101 400

7 7
5 9 6 8 7 7 5
9

8 7
3 3 10 10 3 2 6 2

7 7
1 5 9 9 9 2 9
*/
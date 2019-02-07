#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

vector <int> cost;
int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M,buf,lo,mid,hi=0,ans=0;
    long long sum=0;

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>buf;
        sum += buf;
        cost.push_back(buf);        
    }
    cin>>M;

    sort(cost.begin(),cost.end());
    
    lo = 0;
    hi = cost[N-1];
    if(sum <= M){
        ans = hi;
        hi = 0;
    }

    while(lo < hi){
        sum = 0;
        mid = (lo + hi) / 2;

        for(int i=0; i<N; i++){
            if(cost[i] <= mid){
                sum += cost[i];
            }
            else{
                sum += mid;
            }
        }
        // printf("%d %d %d %d\n",lo,mid,hi,sum);
        if(sum > M){
            hi = mid;
        }
        else if(sum == M){
            ans = mid;
            break;
        }
        else{            
            ans = mid;
            lo = mid+1;
        }
    }
    cout<<ans;
    return 0;
}
/*
4
120 110 140 150
485

127

5
4 4 5 5 2
7
output: 0
correct answer: 1

3
3 2 4
5
output: 0
correct answer: 1

3
4 4 5
6
output: 0
correct answer: 2

4
120 110 140 150
1000
output: 149
correct answer: 150

4
120 110 140 150
520

4
120 110 140 150
519
correct answer: 149
*/
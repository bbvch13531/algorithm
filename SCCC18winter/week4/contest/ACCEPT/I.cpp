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

    int N,num,maxV = -1;
    int chi[11000]={0,0,1,2};
    vector<int> fibo;

    fibo.push_back(1);
    fibo.push_back(2);

    cin>>N;

    // for(int i=1; num<10000; i++){
    //     num = fibo[i-1] + fibo[i];
    //     fibo.push_back(num);
    // }
    // for(int i=0; i<fibo.size(); i++){
    //     chi[fibo[i+1]] = fibo[i];
    //     // cout<<chi[i]<<" ";
    // }
    

    for(int i=4; i<=N; i++){

            maxV = -1;
            for(int j=0; j<=i/2 - 1; j++){
                int dp1 = chi[j+2];
                int dp2 = chi[i-j-2];
                maxV = max(maxV,dp1+dp2);

                // cout<<i<<" "<<dp1<<" "<<dp2<<" "<<maxV<<endl;
                
            }
            chi[i] = maxV;

    }

    // for(int i=0; i<=N; i++){
    //     cout<<i<<" = "<<chi[i]<<"\n";
    // }
    cout<<(N+1)/2<<" "<<chi[N];
    return 0;
}
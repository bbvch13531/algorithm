#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"

using namespace std;
vector <int> dp;
vector <int> path, ans;
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    dp.resize(N+1);
    path.resize(N+1);

    dp[1] = 0; path[1] = 0;
    dp[2] = 1; path[2] = 1;
    dp[3] = 1; path[3] = 1;

    for(int i=4; i<=N; i++){
        if(i%2 == 0) {
            if(i%3==0){
                if(dp[i-1] <= dp[i/2] && dp[i-1] <= dp[i/3]) {    // dp[i-1]
                    dp[i] = dp[i-1] + 1;
                    path[i] = i-1;
                    // debug2(i, i-1);
                } else if (dp[i/2] <= dp[i-1]  && dp[i/2] <= dp[i/3]){
                    dp[i] = dp[i/2] + 1;
                    path[i] = i/2;
                    // debug2(i, i/2);
                } else if (dp[i/3] <= dp[i-1]  && dp[i/3] <= dp[i/2]){
                    dp[i] = dp[i/3] + 1;
                    path[i] = i/3;
                    // debug2(i, i/3);
                }
                // dp[i] = min(min(dp[i-1], dp[i/2]), min(dp[i/2], dp[i/3])) +1 ;
            } else {
                if(dp[i-1] < dp[i/2]){
                    dp[i] = dp[i-1] + 1;
                    path[i] = i-1;
                    // debug2(i, i-1);
                } else {
                    dp[i] = dp[i/2] + 1;
                    path[i] = i/2;
                    // debug2(i, i/2);
                }
                // dp[i] = min(dp[i-1], dp[i/2]) + 1;
            }
        } else {
            if(i%3==0){
                if(dp[i-1] < dp[i/3]){
                    // debug2(i, i-1);
                    dp[i] = dp[i-1] + 1;
                    path[i] = i-1;
                } else {
                    // debug2(i, i/3);
                    dp[i] = dp[i/3] + 1;
                    path[i] = i/3;
                }
                // dp[i] = min(dp[i-1], dp[i/3]) + 1;
            } else {
                // debug2(i, i-1);
                dp[i] = dp[i-1] + 1;
                path[i] = i-1;
            }
        }
        // debug2(i, dp[i]);
    }

    int idx = N;
    while(1){
        if(path[idx] == 0) break;
        ans.push_back(path[idx]);
        idx = path[idx];
    }
    ans.push_back(N);
    sort(ans.begin(), ans.end(), greater<int>());
    
    // for(int i=1; i<=N; i++)
    //     debug2(i, path[i]);

    cout << dp[N] << "\n";
    for(int a: ans)
        cout << a <<" ";
}
/*
반례: 642

정해: 
10
642 321 320 160 80 40 20 10 9 3 1

오답:
11
642 214 107 106 53 52 26 13 12 4 2 1
*/
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

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    dp.resize(N+1);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for(int i=4; i<=N; i++){
        if(i%2 == 0) {
            if(i%3==0){
                dp[i] = min(min(dp[i-1], dp[i/2]), min(dp[i/2], dp[i/3])) +1 ;
            } else {
                dp[i] = min(dp[i-1], dp[i/2]) + 1;   
            }
        } else {
            if(i%3==0){
                dp[i] = min(dp[i-1], dp[i/3]) + 1;
            } else {
                dp[i] = dp[i-1] + 1;
            }
        }
        debug2(i, dp[i]);
    }

    cout << dp[N] << "\n";
}
/*

10
i = 4, dp[i] = 2
i = 5, dp[i] = 3
i = 6, dp[i] = 2
i = 7, dp[i] = 3
i = 8, dp[i] = 3
i = 9, dp[i] = 2
i = 10, dp[i] = 3
3
*/
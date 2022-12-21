#include <bits/stdc++.h>
#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"
#define INF 0x33ffffff
#define ll long long
using namespace std;

int main(){
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T;
    ll x, y;
    ll num, ans;
    cin >> T;
    while(T--){
        cin >> x >> y;
        num = y - x;
        ll a = sqrt(num);

        if(num == a*a){
            ans = 2*a-1;
        } else if(a*a < num && num <= a*a + a){
            ans = 2*a;
        } else if(a*a + a < num && num < (a+1)* (a+1)){
            ans = 2*a + 1;
        } else {
            assert(0);
        }
        cout << ans<<"\n";
    }
    return 0;
}
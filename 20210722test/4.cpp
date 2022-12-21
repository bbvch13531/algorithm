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
    freopen("4input.txt", "r", stdin);
    vector<ll> vec;
    ll sum=0;
    int N;
    cin >> N;
    int tmp;

    for(int i=0; i<N; i++){
        cin >>tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    ll ans[3];
    ll absMin=INF;
    int low = 0, high = N-1;
    int mid = (low + high)/2;

    while(1){
        
        sum = vec[low] + vec[mid] + vec[high];
        debug3(low, mid, high);
        if(abs(sum) < absMin){
            debug3(low, mid, high);
            absMin = abs(sum);
            ans[0] = vec[low];
            ans[1] = vec[mid];
            ans[2] = vec[high];
        }
        if(low+1 == mid){
            high--;
            mid = (low + high) / 2;
            continue;
        } else if(mid+1 == high){
            low++;
            mid = (low + high) / 2;
            continue;
        }
        if(sum <= 0){
            mid++;
        } else {
            mid--;
        }
        if(low == high){
            break;
        }
    }
    for(int i=0; i<3; i++)
        debug1(ans[i]);
    return 0;
}
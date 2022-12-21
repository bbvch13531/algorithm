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
    freopen("1input.txt", "r", stdin);
    ll N, S;
    ll tmp;
    vector<ll> vec;
    cin >> N >> S;

    for(int i=0; i<N; i++){
        cin >> tmp;
        vec.push_back(tmp);
    }
    int s=0, e=0;
    int minLen=INF;
    ll sum=vec[0];
    
    while(1){
        if(sum < S){
            // cout<<"under ";
            // debug3(s, e , sum);
            e++;
            sum += vec[e];

            // e를 1 증가하고, 다음 원소가 더해진 상태
        } else { // sum >= S
            if(e-s < minLen){
                minLen = e-s;
            }
            sum -= vec[s];
            // cout<<"over ";
            // debug3(s, e , sum);
            s++;
            // 맨 왼쪽 원소의 값을 빼고 s는 1 증가한 상태
        }
        if(e >= vec.size()) break;
        // 업데이트된 상태가 조건에 성립하는지?
        // 부분합이 S이상인지?
    }
    if(sum >= S){
        if(e-s < minLen){
            minLen = e-s;
        }
    }

    if(minLen == INF)   cout << 0;
    else cout << minLen + 1;
    return 0;
}
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
    // freopen("1-1input.txt", "r", stdin);
    int R, C, Rg, Rp, Cg, Cp;
    vector<string> mmap;

    cin >> R >> C ;
    cin >> Rg >> Cg >> Rp >> Cp;

    string tmp;
    for(int i=0; i<R; i++){
        cin >> tmp;
        mmap.push_back(tmp);
    }
    int cnt=0;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(mmap[i][j] == 'P'){
                cnt++;
            }
        }
    }
    if(cnt == Rp * Cp){
        cout << 0;
    } else {
        cout << 1;
    }
    return 0;
}
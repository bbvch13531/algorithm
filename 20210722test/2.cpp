#include <bits/stdc++.h>
#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"
#define INF 0x33ffffff
#define ll long long

using namespace std;
int N;
bool v[20][20];
int rows[20], cols[20], diagonal1[20], diagonal2[20];
ll ans = 0;

void printMap(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(v[i][j]) cout <<1;
            else cout<<0;
        }
        cout<<"\n";
    }
        cout<<"\n";
}
bool canVisit(int n, int m){
    if(rows[n] != 0) return false;
    if(cols[m] != 0) return false;
    if(diagonal1[n-m+N-1] != 0) return false;
    if(diagonal2[n+m] != 0) return false;

    return true;
}

void dfs(int x, int y, int q){
    if(q == N){
        ans++;
        // debug2(x,y);
        // printMap();
        return;
    }
    for(int i=x; i<N; i++){
        for(int j=0; j<N; j++){
        
    // int i=x;
    // int j=y;
    // while(1){
        // if(i==x || j==y) continue;
        // if(i-j == x-y) continue;
        if(canVisit(i,j)){
            v[i][j] = true;
            // debug3(i, j, q);
            // printMap();
            rows[i]++;
            cols[j]++;
            diagonal1[i-j+N-1]++;
            diagonal2[i+j]++;
            dfs(i, j, q+1);
            rows[i]--;
            cols[j]--;
            diagonal1[i-j+N-1]--;
            diagonal2[i+j]--;
            v[i][j] = false;
        }
    }
    }
}

void dfs2(int r, int q){
    if(q == N){
        ans++;
        // debug2(x,y);
        // printMap();
        return;
    }

    // r행 i열을 탐색한다.
    for(int i=0; i<N; i++){
        if(canVisit(r, i)){
            v[r][i] = true;
            rows[r]++;
            cols[i]++;
            diagonal1[r-i+N-1]++;
            diagonal2[r+i]++;

            dfs2(r+1, q+1);
            
            rows[r]--;
            cols[i]--;
            diagonal1[r-i+N-1]--;
            diagonal2[r+i]--;
            v[r][i] = false;
        }
    }
}
int m[20];
void dfs3(int r){
    if(r == N){
        ans++;
        return;
    }
    
    for(int i=0; i<N; i++){
        bool flag=true;
        for(int j=0; j<r; j++){
            if(m[j] == i || abs(j-r) == abs(i - m[j])){
                flag = false;
                break;
            }
        }
        if(flag){
            m[r] = i;
            dfs3(r+1);
        }
    }
}
int main(){
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<N; j++){
    //         dfs(i, j, 0);
    //     }
    // }
    // dfs2(0,0);
    dfs3(0);
    cout << ans;
    return 0;
}
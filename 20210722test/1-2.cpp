#include <bits/stdc++.h>
#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"
#define INF 0x33ffffff
#define ll long long

using namespace std;

string room[110];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool hasVisit[110][110];

int main(){
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("1-2input.txt", "r", stdin);
    int R, C, T;

    cin >> R >> C;
    string tmp;
    for(int i=0; i<R; i++){
        cin >> tmp;
        room[i] = tmp;
    }

    queue<tuple<int, int, int, int>> q;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            char ch = room[i][j];
            if(ch == 'G')
                q.emplace(i, j, 0, 0);
        }
    }
    int ans;
    while(!q.empty()){
        int x, y, goguma, step;
        tie(x, y, goguma, step) = q.front();
        if(step == T) {
            ans = goguma;
            break;
        }
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= R || ny < 0 || ny > C) continue;
            if(!hasVisit[nx][ny] && room[nx][ny] != '#'){
                int g=0;
                if(room[nx][ny]=='S') g = 1;
                q.emplace(nx, ny, goguma+g, step+1);
            }
        }
    }
    cout << ans;
    return 0;
}
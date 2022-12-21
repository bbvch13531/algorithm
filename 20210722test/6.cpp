#include <bits/stdc++.h>
#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"
#define INF 0x33ffffff
#define ll long long

using namespace std;
int N, M;
int maxVal=0;
int lab[10][10], flood[10][10];
bool vv[10][10];

void printMap(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout<<lab[i][j];
        }
        cout<<"\n";
    }
    cout<<"\n";
}
void printFlood(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout<<flood[i][j];
        }
        cout<<"\n";
    }
    cout<<"\n";
}

int canFlood(){
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    queue<pair<int,int>> q;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(lab[i][j] == 2){
                q.emplace(i,j);
            }
        }
    }

    while(!q.empty()){
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 || nx>=N || ny < 0 || ny >= M) continue;
            if(lab[nx][ny] == 0){
                lab[nx][ny] = 3;
                q.emplace(nx,ny);
            }
        }
    }
    // cout<<"-----virus-----\n";
    // printMap();
    // cout<<"-----end-----\n";

    int cnt=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(lab[i][j] == 0)
                cnt++;
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            flood[i][j] = lab[i][j];
            if(lab[i][j] == 3)
                lab[i][j] = 0;
        }
    }
    return cnt;
}

void dfs(int x, int y, int w){
    if(w == 3){ // 벽 3개 세움
        // printMap();
        int safeArea = canFlood();
        if(safeArea > maxVal){
            maxVal = safeArea;
            // debug1(maxVal);
            // printFlood();
        }
        return;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!vv[i][j] && lab[i][j] == 0){
                lab[i][j] = 1;
                vv[i][j] = true;
                dfs(i,j,w+1);
                lab[i][j] = 0;
                vv[i][j] = false;
            }
        }
    }

    // int i=x,j=y;
    // while(1){
    //     printMap();
    //     if(!vv[i][j] && lab[i][j] == 0){
    //         lab[i][j] = 1;
    //         vv[i][j] = true;
    //         dfs(i,j,w+1);
    //         lab[i][j] = 0;
    //         vv[i][j] = false;
    //     }
    //     debug2(i,j);
    //     j++;
    //     if(j==M){
    //         i++;
    //         j=0;
    //     }
    //     if(i==N){
    //         break;
    //     }
    // }
}

int main(){
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("6input.txt", "r", stdin);
    
    int tmp;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> tmp;
            lab[i][j] = tmp;
        }
    }
    
    dfs(0,0,0);
    cout <<maxVal;
    return 0;
}
// https://www.acmicpc.net/problem/7576
// 토마토, BFS 문제

#include <iostream>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>



using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int map[1010][1010];
int N, M;

struct tmt{
    int x;
    int y;
    int day;
};

int isValid(int, int);
int isFinished(void);

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt=0;
    queue <tmt> q;

    cin >> M >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>> map[i][j];

            if(map[i][j] == 1){
                q.push({i, j, 0});
            }
        }
    }

    while(!q.empty()){
        int tx = q.front().x;
        int ty = q.front().y;
        cnt = q.front().day;

        // cout<< tx<< " "<< ty<< " "<< cnt<< "\n";
        q.pop();    

        for(int i=0; i<4; i++){
            int nx = tx + dx[i];
            int ny = ty + dy[i];
            
            if(isValid(nx, ny) == 1){
                if(map[nx][ny] == 0){
                    map[nx][ny] = 1;
                    q.push({nx, ny, cnt+1});
                }
            }
        }
    }
    if(isFinished() == 1){
        cout << cnt;
    }
    else{
        cout<<"-1";
    }
    return 0;    
}


int isValid(int x, int y){
    if(0<= x && x < N && 0 <= y && y < M)
        return 1;
    else
        return -1;
}


int isFinished(void){
    int flag = 1;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] == 0){
                flag = 0;
                return -1;
            }
        }
    }
    if(flag == 1)
        return 1;
}
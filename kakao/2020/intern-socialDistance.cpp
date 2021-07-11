#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <fstream>

#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"
#define debug5(a,b,c,d,e) cout << "(" << #a << ", " << #b << ", " << #c << ", " << #d << ", " << #e << ") = (" << a << ", " << b << ", " << c << ", " << d << ", " << e << "\n"
using namespace std;
vector<string> map;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool visit[10][10];

// 사람있는 좌표를 시작으로 BFS 탐색한다
// (x,y,cnt)
// Cnt가 2인데 사람이 있는 칸을 발견하면 return false
// 끝까지 탐색하면 return true


bool valid(int x, int y){
    if(x < 0 || x >= 5 || y < 0 || y >= 5) return false;
    if(map[x][y] == 'X') return false;
    if(visit[x][y]) return false;
    return true;
}

bool dfs(int x, int y, int cnt) {
    bool res;
    if(cnt == 1){
        if(map[x][y] == 'P'){
            return false;
        }
    } else if(cnt==2){
        if(map[x][y] == 'P'){
            return false;
        } else {
            return true;   
        }
    }
    for(int i=0; i<4; i++){
        
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(valid(nx, ny)){
            visit[nx][ny] = true;
            res = dfs(nx, ny, cnt+1);
            if(!res) return false;
            visit[nx][ny] = false;
        }
    }

    return true;    //거리두기 지킴
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    bool res;
    for(int t=0; t<5; t++){
        map = places[t];
        debug1(t);
        res = true;
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                visit[i][j] = false;
            }
        }
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if(map[i][j] == 'P'){
                    visit[i][j] = true;
                    res = dfs(i, j, 0);
                    if(!res){
                        answer.push_back(0);
                        break;
                    }
                }
            }
            if(!res){
                break;
            }
        }
        if(res){
            answer.push_back(1);
        }
    }

    return answer;
}

int main(){
    vector<vector<string>> places;
    vector<string> row;
    string s;
    
    freopen("input-socialDistance.txt", "r", stdin);
    for(int i=0; i<5; i++){
        row.clear();
        for(int j=0; j<5; j++){
            cin >> s;
            row.push_back(s);
        }
        places.push_back(row);
    }
    // for(int i=0; i<5; i++){
    //     for(int j=0; j<5; j++){
    //         debug1(places[i][j]);
    //     }
    // }

    vector<int> ans = solution(places);
    
    return 0;
}
/*
POOOP OXXOX OPXPX OOXOX POXXP
POOPX OXPXP PXXXO OXXXO OOOPP
PXOPX OXOXP OXPOX OXXOP PXPOX
OOOXX XOOOX OOOXX OXOOX OOOOO
PXPXP XPXPX PXPXP XPXPX PXPXP
*/
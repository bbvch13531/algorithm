// https://www.acmicpc.net/problem/2667
// DFS문제. 몇개의 단지, 몇개의 아파트 있는지 계산하는 문제

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int isValid(int x, int y);
int N;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<pair<int, int> >stk;

    string in[30];
    int cnt=0, num=0;
    vector<int> val;
    cin>> N;
    
    for(int i=0; i<N; i++){
        cin>> in[i];
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(in[i][j] == '1'){
                val.push_back(num);
                // cout<<i<<" "<<j<<" "<<num<<"\n";
                cnt++;
                num=0;
                // val.push_back(0);
                in[i][j] = '0';
                stk.push({i, j});
            }
            while(!stk.empty()){
                int x = stk.top().first;
                int y = stk.top().second;
                // printf("%d %d\n", x, y);
                stk.pop();

                for(int k=0; k<4; k++){
                    int nx = x+dx[k];
                    int ny = y+dy[k];

                    if(isValid(nx, ny) == 1){
                        if(in[nx][ny] == '1'){
                            in[nx][ny] = '0';
                            stk.push({nx, ny});
                        }
                    }
                }
                num++;
                // val[cnt]++;
            }
            

        }
    }
    val.push_back(num);
    sort(val.begin(), val.end());
  
    cout<<cnt<<"\n";
    for(int i=1; i<=cnt; i++){
        cout<<val[i]<<"\n";
    }
    return 0;
}

int isValid(int x, int y){
    if(0<= x && x < N && 0 <= y && y < N){
        return 1;
    }
    return 0;
}

/*
5
01001
11001
10011
00100
10110
*/
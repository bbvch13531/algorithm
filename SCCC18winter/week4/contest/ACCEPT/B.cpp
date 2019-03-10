#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef struct knight{
    int x;
    int y;
    int cnt;
    knight(int x,int y,int cnt){
        this->x = x;
        this->y = y;
        this->cnt = cnt;
    }
} knight;

queue<knight > q;

int cnt,I;
int isVisit[310][310];
void visit(int,int,int);
int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T,cx,cy,dx,dy;
    int x,y;
    cin>>T;

    for(int tc=0; tc<T; tc++){
        cin>>I>>cx>>cy>>dx>>dy;
        cnt = 0;
        memset(isVisit,0,sizeof(isVisit));
        while(!q.empty()){
            q.pop();
        }
        q.push(knight(cx,cy,0));

        while(!q.empty()){
            auto kk = q.front();
            x = kk.x;
            y = kk.y;
            cnt = kk.cnt;
            // printf("x = %d, y = %d cnt = %d \n",x,y,cnt);
            q.pop();
            if(x == dx && y == dy){
                break;
            }
            visit(x+1,y+2,cnt);
            visit(x+2,y+1,cnt);
            
            visit(x+2,y-1,cnt);
            visit(x+1,y-2,cnt);

            visit(x-1,y-2,cnt);
            visit(x-2,y-1,cnt);

            visit(x-2,y+1,cnt);
            visit(x-1,y+2,cnt);

        }

        cout<<cnt<<"\n";
    }
    return 0;
}
void visit(int x,int y,int cnt){
    if(0<=x && x<I && 0<=y && y<I){
        if(isVisit[x][y] == 0){
            isVisit[x][y] = 1;
            q.push(knight(x,y,cnt+1));
        }
    }
}

/*
1
4
0 0
0 3

1
3
0 0
2 2

1
8
0 0
7 0



3
8
0 0
7 0
100
0 0
30 50
10
1 1
1 1

*/
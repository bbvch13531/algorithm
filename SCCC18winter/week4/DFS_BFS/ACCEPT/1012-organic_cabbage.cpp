#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstdio>
#include <cstring>
using namespace std;

void visit(int,int);

int graph[60][60];
int dy[] = {0,1,0,-1};
int dx[] = {-1,0,1,0};

int cnt,N,M,K;
queue <pair<int,int> > que;

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T,a,b;
    cin>>T;
    for(int tc=0; tc<T; tc++){
        memset(graph,0,sizeof(graph));
        cin>>M>>N>>K;
        for(int i=0; i<K; i++){
            cin>>b>>a;
            graph[a][b] = 1;
        }
        cnt=0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(graph[i][j] == 1){
                    graph[i][j] = 0;
                    visit(i,j);       
                    // printf("visit\n");             
                }

            }
        }
        printf("%d\n",cnt);
    }
    
    return 0;
}
void visit(int x,int y){
    int qx,qy,nx,ny;
    que.push(make_pair(x,y));

    while(!que.empty()){
        nx = que.front().first;
        ny = que.front().second;
        // printf("nx = %d, ny = %d\n",nx,ny);
        que.pop();
        
        for(int i=0; i<4; i++){
            qx = nx + dx[i];
            qy = ny + dy[i];

            if(0<=qx && qx<N && 0<=qy && qy<M){
                if(graph[qx][qy] == 1){
                    
                    graph[qx][qy] = 0;
                    que.push(make_pair(qx,qy));
                }
            }
        }
    }
    cnt++;
}

/*
2
10 8 18
0 0
1 0
1 1
4 2
4 3
4 5
5 2
2 4
3 4
7 4
8 4
9 4
7 5
8 5
9 5
7 6
8 6
9 6
10 10 1
5 5
*/
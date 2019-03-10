#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <cstring>
#include <string>

using namespace std;
int N,M;
int graph[110][110];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int des,dx,dy,nx,ny;
    queue <pair<int,int> > que;
    string buf;

    cin>>N>>M;

    for(int i=0; i<N; i++){
        cin>>buf;
        for(int j=0; j<buf.size(); j++){
            if(buf[j] == '1'){
                graph[i][j] = 1;
            }
        }
    }

    que.push(make_pair(0,0));

    while(!que.empty()){
        nx = que.front().first;
        ny = que.front().second;

        
    }
    return 0;
}
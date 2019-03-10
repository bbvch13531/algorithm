#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <cstring>

using namespace std;

int graph[1010][1010];
int isVisit[1010];

vector <int> ans;
queue <int> que;
stack <int> stk;
void dfs(int);
int N,M;
int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V;
    int des,a,b;
    cin>>N>>M>>V;

    for(int i=0; i<M; i++){
        cin>>a>>b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    printf("%d ",V);
    isVisit[V] = 1;
    dfs(V);
    printf("\n");
    memset(isVisit,0,sizeof(isVisit));


    que.push(V);
    isVisit[V] = 1;

    while(!que.empty()){
        des = que.front();
        printf("%d ",des);
        que.pop();
        for(int i=1; i<=N; i++){
            if(graph[des][i] == 1 && isVisit[i] == 0){
                isVisit[i] = 1;                
                que.push(i);
            }
        }
    }

    return 0;
}

void dfs(int n){
    for(int i=1; i<=N; i++){
        if(graph[n][i] == 1 && isVisit[i] == 0){
            printf("%d ",i);
            isVisit[i] = 1;
            dfs(i);
        }
    }
    
}
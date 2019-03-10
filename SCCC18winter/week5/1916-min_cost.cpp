#define INF 0x7FFFFFFF
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,start,finish;
int dis[1010],graph[1010][1010],isVisit[1010];

void preprocess(void);
int process(void);
void printDis(void);
void printGraph(void);

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int src,des,cost,ans;
    
    cin>>N>>M;

    for(int i=0; i<M; i++){
        cin>>src>>des>>cost;  
        graph[src][des] = cost;      
    }
    cin>>start>>finish;
    preprocess();

    printGraph();
    printDis();

    ans = process();

    cout<<ans;
    return 0;
}

void preprocess(void){
    for(int i=1; i<=N; i++){
        dis[i] = INF;
    }
    dis[start] = 0;
}
void printDis(void){
    cout<<"DIS\n";
    for(int i=1; i<=N; i++){
        cout<<dis[i]<<" ";
    }
    cout<<"\n";
}
void printGraph(void){
    cout<<"GRAPH\n";
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
int process(void){
    int next,minDis,tmp,step;

    for(int i=0; i<N; i++){
        minDis = INF;
        // Find next step
        for(int j=1; j<=N; j++){
            if(dis[j] != -1){
                if(minDis > dis[j] && isVisit[j] == 0){
                    minDis = dis[j];
                    next = j;
                    cout<<minDis<<" "<<next<<"\n";
                }
            }
        }
        isVisit[next] = 1;
        cout<<"next is "<<next<<", minDis is "<<minDis<<"\n";

        // 업데이트 시킨다.
        for(int j=1; j<=N; j++){
            if(graph[next][j] != 0){
                if(dis[j] > dis[next] + graph[next][j]){
                    dis[j] = dis[next] + graph[next][j];
                }
            }
        }

        printDis();
        printGraph();
    }
    return dis[finish];
}

/*
5
8
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
1 5

4

5
6
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6
1 4

7

8
12
1 2 4
1 8 8

*/
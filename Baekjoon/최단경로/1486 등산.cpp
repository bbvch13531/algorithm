// https://www.acmicpc.net/problem/1486
#include <iostream>
#include <queue>
#include <utility>
#include <string>

using namespace std;

typedef struct _Node{
    int x;
    int y;
    int time;
} Node;

priority_queue<Node> pq;
int N, M, T, D;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool operator < (Node a, Node b){
    return a.time < b.time;
}

bool isValid(int i, int j){
    if(0 <= i && i<N && 0<=j && j<=M)
        return true;
    else
        return false;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char map[30][30];
    string map1[30];
    
    cin >> N >> M >> T >> D;

    for(int i=0; i<N; i++){
        cin >> map1[i];
    }
    
    pq.push( Node{0, 0, 0} );
    
    while(!pq.empty()){
        Node next = pq.top();
        pq.pop();

        int time = next.time;

        for(int i=0; i<4; i++){
            int x = next.x + dx[i];
            int y = next.y + dy[i];
            if(isValid(x, y)){
                int nextMt = map1[x][y];
                
            }
        }
    }
    return 0;
}
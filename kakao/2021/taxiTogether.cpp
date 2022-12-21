#include <bits/stdc++.h>
#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"
const int INF = 0x013ff7f7f;
using namespace std;

int distA[210], distB[210], distS[210];
vector<pair<int, int> > g[210];
int N, M, S, A, B;

void runFW(int n, int start){
    int dist[210];
    fill(dist, dist+210, INF);
    queue<int> q;
    
    q.push(start);
    dist[start] = 0;

    while(!q.empty()){
        int here = q.front();
        q.pop();

        for(auto pii: g[here]){
            int next,val;
            tie(next,val) = pii;

            if(dist[next] > dist[here] + val) {
                dist[next] = dist[here] + val;
                q.push(next);
            }
        }
        // debug1(here);
    }
    if(start == S){
        memcpy(distS, dist, sizeof(int)*(n+1));
    } else if(start == A){
        memcpy(distA, dist, sizeof(int)*(n+1));
    } else if(start == B){
        memcpy(distB, dist, sizeof(int)*(n+1));
    }
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    fill(distA, distA+210, INF);
    fill(distB, distB+210, INF);
    fill(distS, distS+210, INF);

    for(auto fare: fares){
        int u = fare[0];
        int v = fare[1];
        int d = fare[2];

        g[u].emplace_back(v, d);
        g[v].emplace_back(u, d);
    }
    runFW(n, a);
    runFW(n, b);
    runFW(n, s);

    int minDist=INF;
    for(int i=1; i<=n; i++){

        int totalDist = distS[i] + distA[i] + distB[i];
        minDist = min(minDist, totalDist);
        debug1(totalDist);
    }
    answer = minDist;
    return answer;
}
int main(){

    int u, v, d;
    vector<vector<int>> fares;

    freopen("input-taxiTogether.txt", "r", stdin);
    cin >>N >>S >> A >> B;
    cin >> M;

    for(int i=0; i<M; i++){
        vector<int> row;
        cin>> u>>v>>d;
        row.push_back(u);
        row.push_back(v);
        row.push_back(d);
        fares.push_back(row);
    }
    solution(N, S, A, B, fares);
    return 0;
}
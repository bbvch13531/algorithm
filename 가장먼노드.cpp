#include <bits/stdc++.h>
#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"
#define INF 0x33ffffff
#define pii pair<int,int>
using namespace std;

vector<int> graph[20010];
vector<int> dist;
queue <int> qq;

int main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    freopen("input-farthestNode.txt", "r", stdin);

    int N, M;
    cin >> N >> M;

    dist.resize(N+1);
    fill(dist.begin(), dist.end(), INF);

    for(int i=0; i<M; i++){
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    qq.push(1);
    dist[1] = 0;
    
    while(!qq.empty()){
        int here = qq.front();
        qq.pop();

        for(int next: graph[here]){
            if(dist[next] > dist[here]+1){
                qq.push(next);
                dist[next] = dist[here] + 1;
            }
        }
        debug1(here);
    }
    sort(dist.begin(), dist.end());
    int maxDist = dist[N];
    int cnt=0;
    for(int i=1; i<=N; i++){
        if(dist[i] == maxDist)
            cnt++;
    }
    
    
    return 0;
}
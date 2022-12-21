#include <bits/stdc++.h>
#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"
#define ll long long 
#define pii pair<int, int>
using namespace std;

vector <pii> graph[10010], farthest;
vector <pii> bidirect[10010];
int visit[10010];
int N;

int dfs(int n, int d){
    if(graph[n].empty()){
        // debug2(n, d);
        farthest.emplace_back(d, n);    // (distance, node number)
        return 0;
    }

    for(int i=0; i<graph[n].size(); i++){
        int e, dist;
        tie(e, dist) = graph[n][i];
        // debug2(n, e);
        dfs(e, d + dist);
    }
    return 0;
}

int main(){
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    freopen("1967input.txt", "r", stdin);
    int s, e, d;
    cin >> N;
    
    // 1 is always root
    for(int i=0; i<N-1; i++){
        cin >> s >> e >> d;
        graph[s].emplace_back(e,d);

        bidirect[s].emplace_back(e,d);
        bidirect[e].emplace_back(s,d);
    }

    dfs(1, 0);
    sort(farthest.begin(), farthest.end(), greater<pii>());
    // cout << farthest[0].second;

    queue<pii> q;
    q.emplace(farthest[0].second, 0);
    visit[farthest[0].second] = 1;
    int maxDist = -1;
    while(!q.empty()){
        int here, dist;
        tie(here, dist) = q.front();
        if(dist > maxDist) maxDist = dist;
        q.pop();
        // debug2(here, dist);
        for(int i=0; i<bidirect[here].size(); i++){
            int next, w;
            tie(next, w) = bidirect[here][i];
            if(visit[next] == 0){
                q.emplace(next, dist+w);
                visit[next] = 1;
            }
        }
    }
    cout << maxDist;
    return 0;
}
#include <bits/stdc++.h>

#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"
#define INF 0x33ffffff
using namespace std;

int d[1024][1024];
vector <pair<int, int>> adj[1010], adjrev[1010];
int trapIdx[1010];


int solution(int n, int start, int end, vector<vector<int> > roads, vector<int> traps) {
    int answer = 0;
    if(start == end) return 0;
    for(auto vv: roads){
        int u = vv[0];
        int v = vv[1];
        int val = vv[2];

        adj[u].emplace_back(v, val);
        adjrev[v].emplace_back(u, val);
    }
    
    fill(trapIdx+1, trapIdx+n+1, -1);

    for(int i=0; i<traps.size(); i++)   trapIdx[traps[i]] = i;
    for(int i=1; i<=n; i++)  fill(d[i], d[i]+1024, INF);
    
    d[start][0] = 0;
    priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;
    
    pq.push({d[start][0], start, 0});

    while(!pq.empty()) {
        int val, idx1, idx2;
        tie(val, idx1, idx2) = pq.top();
        pq.pop();

        if(idx1 == end) return val;
        if(d[idx1][idx2] != val) continue;
        for(auto p: adj[idx1]) {
            int next = p.first;
            int dist = p.second;
            int rev = 0;
            if(trapIdx[idx1] != -1 && ((1 << trapIdx[idx1]) & idx2) ) rev ^= 1;
            if(trapIdx[next] != -1 && ((1 << trapIdx[next]) & idx2) ) rev ^= 1;
            if(rev) continue;
            int next_state = idx2;
            if(trapIdx[next] != -1) next_state ^= (1 << trapIdx[next]);
            if(d[next][next_state] > dist + val) {
                d[next][next_state] = dist + val;
                pq.push({d[next][next_state], next, next_state});
            }
        }

        for(auto p: adjrev[idx1]) {
            int next = p.first;
            int dist = p.second;
            int rev = 0;
            if(trapIdx[idx1] != -1 && ((1 << trapIdx[idx1]) & idx2) ) rev ^= 1;
            if(trapIdx[next] != -1 && ((1 << trapIdx[next]) & idx2) ) rev ^= 1;
            if(!rev) continue;
            int next_state = idx2;
            if(trapIdx[next] != -1) next_state ^= (1 << trapIdx[next]);
            if(d[next][next_state] > dist + val) {
                d[next][next_state] = dist + val;
                pq.push({d[next][next_state], next, next_state});
            }
        }
    }
    assert(0);
    return -1;
}

int main(){
    vector<vector<int>> roads;
    vector<int> traps;
    int N, start, end, w,h,trapNum;
    int tmp;

    freopen("input-escapeMaze.txt", "r", stdin);
    
    cin >> N >> start >> end;
    cin >> h >> w;
    
    for(int i=0; i<h; i++){
        vector<int> row;
        for(int j=0; j<w; j++){
            cin >> tmp;
            row.push_back(tmp);
        }
        roads.push_back(row);
    }
    cin >> trapNum;
    
    for(int i=0; i<trapNum; i++){
        cin >> tmp;
        traps.push_back(tmp);
    }

    int anwser = solution(N, start, end,roads, traps);
    debug1(anwser);
    return 0;
}
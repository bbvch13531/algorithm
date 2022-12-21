#include <bits/stdc++.h>

#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"
#define INF 0x33ffffff
using namespace std;

vector<vector<int> > w;
vector<int> dist;
vector<bool> visit;

priority_queue<pair<int, int> > pq;

void switchTrap(int N, int trap) {
    vector<int> out = w[trap];
    vector<int> in (N+1, 0), tmp;

    for(int i=1; i<=N; i++) {
        if(w[i][trap] != 0){
            in[i] = w[i][trap];
            visit[i] = false;
        }
        if(w[trap][i] != 0){
            visit[i] = false;
        }
    }

    for(int i=1; i<=N; i++){
        w[trap][i] = in[i];
        w[i][trap] = out[i];
    }
}

void printW(){
    for(int i=1; i<w.size(); i++){
        for(int j=1; j<w.size(); j++){
            cout << w[i][j] << " ";
        }
        cout << "\n";
    }
}

int solution(int n, int start, int end, vector<vector<int> > roads, vector<int> traps) {
    int answer = 0;

    visit.assign(n+1, false);
    dist.assign(n+1, INF);
    // for(int i=0; i<=n; i++){
    //     dist.push_back(-1 * INF);
    // }
    
    for(int i=0; i<=n; i++){
        vector<int> row (n+1, 0);
        w.push_back(row);
    }

    for(auto road: roads){
        int p = road[0];
        int q = road[1];
        int s = road[2];

        w[p][q] = s;
    }
    // debug1(w.size());
    // printW();

    dist[start] = 0;
    visit[start] = true;
    pq.emplace(start, 0);

    while(!pq.empty()) {
        int here, hereW;
        tie(here, hereW) = pq.top();
        pq.pop();
        if(here == end){
            answer = hereW;
            break;
        }
        // debug2(here, hereW);

        for(int trap: traps) {
            if(trap == here){
                switchTrap(n, here);
            }
        }

        for(int i=1; i<w[here].size(); i++){
            if(w[here][i] != 0 && !visit[i]){
                //  && hereW + w[here][i] <= dist[i]){
                dist[i] = hereW + w[here][i];
                pq.emplace(i, dist[i]);
                // debug2(i, dist[i]);
            }
        }
    }
    return answer;
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
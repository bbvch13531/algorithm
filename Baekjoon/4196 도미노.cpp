#include <bits/stdc++.h>
#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"
#define INF 0x33ffffff
#define pii pair<int,int>
using namespace std;

vector<int> d[100010];
vector<int> visit, indegree;
queue <int> qq;

int main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);

    int T, N, M, x, y;
    cin >>T;

    while(T--){
        cin >> N >> M;
        visit.resize(N);
        indegree.resize(N);
        fill(indegree.begin(), indegree.end(), 0);

        for(int i=0; i<M; i++){
            cin >> x >> y;
            d[x].push_back(y);
            indegree[y]++;
        }

        for(int i=1; i<=N; i++){
            if(indegree[i] == 0)
                qq.push(i);
        }

        while(!qq.empty()){
            int here = qq.front();

            for(int i=1; i<=N; i++)
            if( visit[here] == 0) {

            }
            here++;
            if(here == N) break;
            
        }
    }
	return 0;
}

#include <bits/stdc++.h>
#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"
const int INF = 0x0f7f7f7f;
using namespace std;

int items[110];
int dist[110][110];

int main(){
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int N, M, R;
    int tmp;
    cin >> N >> M >> R;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i!=j){
                dist[i][j] = INF;
            }
        }
    }
    for(int i=1; i<=N; i++){
        cin >> tmp;
        items[i] = tmp;
    }

    for(int i=1; i<=R; i++){
        int a,b,l;
        cin >> a >> b >> l;
        dist[a][b] = dist[b][a] = l;
    }

    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    int cnt=0, ans = -1;
    for(int i=1; i<=N; i++){
        cnt = items[i];
        for(int j=1; j<=N; j++){
            if(dist[i][j] <= M && i != j){
                cnt += items[j];
            }
        }
        ans = max(cnt, ans);
    }

    cout << ans;
    return 0;
}
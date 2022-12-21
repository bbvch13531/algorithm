#include <bits/stdc++.h>
#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"
const int INF = 0x033ff7f7f;
using namespace std;
int N,T,W;
queue<pair<int,int>> q;

int main(){
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N, M;
    freopen("input-searchRank.txt", "r", stdin);

    cin >> N >> T >> W;
		int px,tx, cx;
    for(int i=0; i<N; i++){
			cin >> px >> tx;
			q.emplace(px, tx);
		}
		cin >> M;
    for(int i=0; i<M; i++){
			cin >> px >> tx >> cx;

    }
    vector<int> ans = solution();
    return 0;
}

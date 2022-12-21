#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>

#define debug(x) cout << #x << " is " << x << "\n"
using namespace std;

int mdx[4] = {-1, 1, 0, 0};
int mdy[4] = {0, 0, -1, 1};
int hdx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int hdy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool visit[300][300][40];
int map[300][300];

int K, W, H;

int main(void){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	queue <tuple<int, int, int, int> > que;
	int num,ans=0;
	bool success = false;

	cin >> K;
	cin >> W >> H;

	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			cin >> num;
			map[i][j] = num;
		}
	}

	que.emplace(0,0,0,0);
	visit[0][0][0] = true;

	while(!que.empty()) {
		auto q = que.front();
		
		int x,y,k,s;
		tie(x,y,k,s) = q;
		que.pop();

		
		if(x == H-1 && y == W-1){
			ans = s;
			success = true;
			break;
		}

		if(k < K){
			for(int i=0; i<8; i++){
				int dx = x + hdx[i];
				int dy = y + hdy[i];
				if(dx < 0 || dx >= H || dy < 0 || dy >= W) continue;
				if(visit[dx][dy][k+1]) continue;
				if(map[dx][dy] == 1) continue;
				
				visit[dx][dy][k+1] = true;
				que.emplace(dx, dy, k+1, s+1);
			}
		}
		for(int i=0; i<4; i++){
			int dx = x + mdx[i];
			int dy = y + mdy[i];
			if(dx < 0 || dx >= H || dy < 0 || dy >= W) continue;
			if(visit[dx][dy][k]) continue;
			if(map[dx][dy] == 1) continue;
			
			visit[dx][dy][k] = true;
			que.emplace(dx, dy, k, s+1);
		}
	}
	if(success)
		cout << ans <<"\n";
	else
		cout << -1 <<"\n";
	return 0;
}
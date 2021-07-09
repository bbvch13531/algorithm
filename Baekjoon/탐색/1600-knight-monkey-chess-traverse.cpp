// not solved
#include <iostream>
#include <vector>
#include <utility>
#define debug(x) cout << #x << " is " << x << "\n"
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define PER(i,a,b) for (auto i = (b); i >= (a); --i)
using namespace std;

int mdx[4] = {-1, 1, 0, 0};
int mdy[4] = {0, 0, -1, 1};
int hdx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int hdy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool visit[300][300];
int map[300][300];

int K, W, H;
void dfs(int x, int y);


int main(void){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num;

	cin >> K;
	cin >> W >> H;

	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			cin >> num;
			map[i][j] = num;
		}
	}
	dfs(0,0);
	return 0;
}

void dfs(int x, int y){
	cout << "(" << x <<", "<<y<<")\n";
	if(x<0 || x>=H || y<0 || y>=W){
		return;
	}
	REP(i, 0, 4) {
		// int dx = x + mdx[i];
		// int dy = y + mdy[i];

		// dfs(dx, dy);

		int dx = x + hdx[i];
		int dy = y + hdy[i];
		if(dx<0 || dx>=H || dy<0 || dy>=W) continue;
		if(visit[dx][dy]) continue;
		if(map[dx][dy] == 1) continue;
		
		visit[dx][dy] = true;
		dfs(dx, dy);
	}
}
1
4 4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
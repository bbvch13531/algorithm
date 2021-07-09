#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

bool visit[1010][1010];
bool count[1010][1010];
vector <string> maps;
queue <pair<int, int> > q;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(void){
	int N, M;
	char buf[1010];
	string input;
	int ans=0;

	scanf("%d %d", &N, &M);

	for(int i=0; i<N; i++){
		scanf("%s", buf);
		input = buf;
		maps.push_back(input);
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(maps[i][j] != '.'){
				q.push(make_pair(i, j));
	//			printf("%d %d, map=%c\n", i, j, maps[i][j]);
			}
		}
	}

	while(!q.empty()){
		pair<int, int> fp = q.front();
		q.pop();

		int fx = fp.first;
		int fy = fp.second;
//		printf("fx = %d, fy = %d\n", fx, fy);
		if(maps[fx][fy] == '.' || visit[fx][fy] == true) continue;

		visit[fx][fy] = true;
		char current = maps[fx][fy];
		for(int i=0; i<4; i++){
			int nx = fx + dx[i];
			int ny = fy + dy[i];

			if(0<= nx && nx <N && 0 <= ny && ny < M){
			char near = maps[nx][ny];
				//	printf("%d %d, near=%c, current=%c\n", nx, ny, near, current);
				if(near != '.' && near != current){
					if(!count[current-'A'][near-'A'] && !count[near-'A'][current-'A']){
					ans++;
					count[current-'A'][near-'A'] = count[near-'A'][current-'A'] = true;
					visit[nx][ny] = true;
					}
				}
			}
		}
	}
	int max = -1, curcnt;
	for(int i=0; i<26; i++){
		curcnt = 0;
		for(int j=i; j<26; j++){
			if(count[i][j])	curcnt++;
//			if(count[j][i]) curcnt++;
		}
		if(curcnt > max) max = curcnt;
	}
	printf("%d %d",ans, max);
	return 0;
}
/*
11 10
..........
AAACC.....
.AAA.....Z
..AAAA..C.
...BBBBB..
....BBB...
...ZBBB...
ZZZZAAAC..
.....CCCC.
QQ......C.
..........

2 7
A.B.C.D
.B.C.D.
 */

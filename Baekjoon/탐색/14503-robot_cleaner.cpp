#include <cstdio>
#include <vector>

using namespace std;

vector <vector<int> > map(60, vector<int>(60, 0)); 

void dfs(int x, int y, int d);
bool shouldGo(int x, int y, int d);
void print_map();
int N, M;
int cleanCnt = 0;

int main(void){
	int r, c ,d;
	int in, ans=0;
	
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &d);
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%d", &in);
			map[i][j] = in;
		}
	}
	print_map();
	dfs(r-1, c-1, d);
	printf("ans = %d", cleanCnt);
	return 0;
}

void dfs(int x, int y, int d){
	int nextDir = d+3;
	int nextX, nextY;
	nextDir %= 4;
	printf("dfs(%d %d %d)\n", x, y, d);
	if(map[x][y] == 0){
		cleanCnt++;	
		map[x][y] = cleanCnt;
	}

	print_map();
	int flag = 0;
	for(int i=0; i<4; i++){
		if(shouldGo(x, y, i)) flag =  1;
	}
	// 네 방향 모두 갈 수 없음
	if(flag == 0){
		if(d == 0)	nextX = x - 1, nextY = y;
		else if(d == 1) nextX = x, nextY = y + 1;
		else if(d == 2) nextX = x + 1, nextY = y;
		else nextX = x, nextY = y - 1;
		
		if(0 <= nextX && nextX < N && 0 <= nextY && nextY < M){
			// 뒤쪽 방향이 벽인 경우
			if(map[nextX][nextY] == 1){
				return;
			}
			else{
				printf("goBack(%d %d %d)\n", nextX, nextY, d);
				dfs(nextX, nextY, d);
			}
		}
		else{
			// 뒤쪽 방향이 map 밖을 벗어난 경우
			return ;
		}
	}

	// 왼쪽 방향에 청소하지 않은 공간이 있다면
	printf("shouldGo(%d %d %d) = %d\n", x, y, nextDir, shouldGo(x,y,nextDir));
	if(shouldGo(x, y, nextDir)){
		if(nextDir == 0)	nextX = x - 1, nextY = y;
		else if(nextDir == 1) nextX = x, nextY = y + 1;
		else if(nextDir == 2) nextX = x + 1, nextY = y;
		else nextX = x, nextY = y - 1;
		
		if(0 <= nextX && nextX < N && 0 <= nextY && nextY < M){
			printf("left: %d %d %d\n", nextX, nextY, nextDir);
			dfs(nextX, nextY, nextDir);
		}
	}
	// 왼쪽 방향에 청소할 공간이 없다면
	else{
		printf("no left: %d %d %d\n",x ,y ,nextDir);
		dfs(x, y, nextDir);
	}
	
}

// x, y is valid. 
bool shouldGo(int x, int y, int d){
	bool flag = false;

	// map 밖을 벗어난 경우 false
	if(x < 0 || x >= N || y < 0 || y >= M) return false;
	if(d == 0){
		for(int i=x-1; i>=0; i--){
				if(map[i][y] != 0)
					return true;
		}
		return false;
	}
	else if(d == 1){
		for(int i=y+1; i>M; i++){
			if(map[x][i] == 0)
				return true;
		}
		return false;
	}
	else if(d == 2){
		for(int i=x+1; i<N; i++){
			if(map[i][y] == 0)
				return true;
		}
		return false;
	}
	else {
		for(int i=y-1; i>=0; i--){
			if(map[x][i] == 0)
				return true;
		}
		return false;
	}
	printf("not found");
}


void print_map(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			printf("%2d ", map[i][j]);
		}
		printf("\n");
	}
}

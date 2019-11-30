#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int move(int dir, int map[][30]);
int getMax(int map[][30]);
void printMap(int map[][30]);
void DFS(int cnt, int map[][30]);
int N, ans=-1;

int main(void){

	int map[30][30];
	int next[30][30];
	scanf("%d", &N);

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &map[i][j]);
		}
	}
	DFS(0, map);
	/*
	int ar[4][30][30];
	for(int i=0; i<4; i++){
		memcpy(ar[i], map, sizeof(map));
		move(i, ar[i]);
		printMap(ar[i]);
	}
	*/
//	memcpy(next, map, sizeof(map));
	
//	move(1, next);

//	printMap(next);
	printf("%d\n",ans);
	return 0;
}

void DFS(int cnt, int map[][30]){
	if(cnt==5)
		return;

	int max=-1;

	for(int i=0; i<4; i++){
		int next[30][30];
		memcpy(next, map, 30*30*4);
		max = move(i, next);
		if(max > ans) ans = max;
		DFS(cnt+1, next);
	}

	return;
}
int move(int dir, int map[][30]){
	int fill_idx = 0;

	if(dir == 0){	// up
		for(int i=0; i<N; i++){
			fill_idx = 0;
			for(int j=0; j<N; j++){
				if(map[j][i] != 0){
					int tmp = map[j][i];
					map[j][i] = 0;
					map[fill_idx][i] = tmp;
					fill_idx++;
				}
			}
		}
		for(int i=0; i<N; i++){
			for(int j=0; j<N-1; j++){
				if(map[j][i] == map[j+1][i]){
					map[j][i] *= 2;
					map[j+1][i] = 0;
				}
			}
		}
		for(int i=0; i<N; i++){
			fill_idx = 0;
			for(int j=0; j<N; j++){
				if(map[j][i] != 0){
					int tmp = map[j][i];
					map[j][i] = 0;
					map[fill_idx][i] = tmp;
					fill_idx++;
				}
			}
		}
	}
	
	else if(dir == 1){	// right
		for(int i=0; i<N; i++){
			fill_idx = N-1;
			for(int j=N-1; j>=0; j--){
				if(map[i][j] != 0){
					int tmp = map[i][j];
					map[i][j] = 0;
					map[i][fill_idx] = tmp;
					fill_idx--;
				}
			}
		}
		for(int i=0; i<N; i++){
			for(int j=N-1; j>0; j--){
				if(map[i][j] == map[i][j-1]){
					map[i][j] *= 2;
					map[i][j-1] = 0;
//					printf("[%d][%d] + [%d][%d]\n", i, j, i, j-1);
				}
			}
		}
		for(int i=0; i<N; i++){
			fill_idx = N-1;
			for(int j=N-1; j>=0; j--){
				if(map[i][j] != 0){
					int tmp = map[i][j];
					map[i][j] = 0;
					map[i][fill_idx] = tmp;
					fill_idx--;
				}
			}
		}
	}
	
	else if(dir == 2){	// down
		for(int i=0; i<N; i++){
			fill_idx = N-1;
			for(int j=N-1; j>=0; j--){
				if(map[j][i] != 0){
					int tmp = map[j][i];
					map[j][i] = 0;
					map[fill_idx][i] = tmp;
					fill_idx--;
				}
			}
		}
		for(int i=0; i<N; i++){
			for(int j=N-1; j>0; j--){
				if(map[j][i] == map[j-1][i]){
					map[j][i] *= 2;
					map[j-1][i] = 0;
				}
			}
		}
		for(int i=0; i<N; i++){
			fill_idx = N-1;
			for(int j=N-1; j>=0; j--){
				if(map[j][i] != 0){
					int tmp = map[j][i];
					map[j][i] = 0;
					map[fill_idx][i] = tmp;
					fill_idx--;
				}
			}
		}
	}

	else {	// left
		for(int i=0; i<N; i++){
			fill_idx = 0;
			for(int j=0; j<N; j++){
				if(map[i][j] != 0){
					int tmp = map[i][j];
					map[i][j] = 0;
					map[i][fill_idx] = tmp;
					fill_idx++;
				}
			}
		}
		for(int i=0; i<N; i++){
			for(int j=0; j<N-1; j++){
				if(map[i][j] == map[i][j+1]){
					map[i][j] *= 2;
					map[i][j+1] = 0;
				}
			}
		}
		for(int i=0; i<N; i++){
			fill_idx = 0;
			for(int j=0; j<N; j++){
				if(map[i][j] != 0){
					int tmp = map[i][j];
					map[i][j] = 0;
					map[i][fill_idx] = tmp;
					fill_idx++;
				}
			}
		}
	}
	int max = getMax(map);
	return max;
}

int getMax(int map[][30]){
	int max = -1;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(map[i][j] > max)
				max = map[i][j];
		}
	}
	return max;
}

void printMap(int map[][30]){
	printf("printMap\n");
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

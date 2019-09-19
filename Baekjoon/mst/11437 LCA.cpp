#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void swap(int *a, int *b);
void dfs(int x, int l);
void makeParent();
void printadj();

vector<int> adj[50010];
int parent[50010][25];
bool visit[50010];
int level[50010];
int maxLevel = 22; 
int N, M;

int main(void){
	int s, e, q1, q2;

	scanf("%d", &N);

	for(int i=1; i<N; i++){
		scanf("%d %d", &s, &e);
//if(s > e)		swap(&s, &e);

		adj[s].push_back(e);
	}
	//printadj();
		dfs(1, 1);
	/*
	printf("afterdfs\n");
	parent[1][0] = 1;
	for(int i=0; i<=maxLevel; i++){
		for(int j=0; j<=N; j++){
			printf("%d ",parent[j][i]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i=1; i<=N; i++)
		printf("%d ",level[i]);
	printf("\n");
	*/
	makeParent();

	scanf("%d", &M);
	//printf("M = %d\n", M);
	
	for(int j=1; j<=M; j++){
		scanf("%d %d", &q1, &q2);
		//printf("q1 = %d, q2 = %d\n", q1, q2);
		if(level[q1] < level[q2]){
			swap(&q1, &q2);
		}
		//printf("after swap q1 = %d, q2 = %d\n", q1, q2);
		for(int i=maxLevel; i>=0; i--){
			// if(level[q2] <= level[parent[q1][i]]){
			if(level[q1] - level[q2] >= (1 << i)){

				q1 = parent[q1][i];

				 //printf("q2lv = %d, parent q1lv = %d, q1 = %d, q2 = %d, parent q1 = %d (1 << i) = %d\n",level[q2], level[parent[q1][i]], q1, q2, parent[q1][i], 1 << i);
				 //printf("after up. q1 = %d, level q1 = %d, i = %d\n", q1, level[q1], i);
			}
		}
		//printf("after match, level[%d] = %d, level[%d] = %d\n", q1, level[q1], q2, level[q2]);
		if(q1 == q2){
			printf("%d\n", q1);
			continue;
		}
		// Find minimum common ancestor
		for(int i=maxLevel; i>=0; i--){
			if(parent[q1][i] != parent[q2][i]){
				 //printf("i=%d, q1=%d, q2=%d, parent[q1]=%d, parent[q2]=%d\n", i, q1, q2, parent[q1][i], parent[q2][i]);
				q1 = parent[q1][i];
				q2 = parent[q2][i];
			}
			/*
			else{
				printf("i=%d, q1=%d, q2=%d, %d\n", i, q1, q2, parent[q1][i]);
				break;
			}
			*/
		}
		printf("%d\n", parent[q1][0]);
	}

	return 0;
}

void makeParent(){
	parent[1][0] = 1;
	for(int i=1; i<=maxLevel; i++){
		for(int j=1; j<=N; j++){
			parent[j][i] = parent[parent[j][i-1]][i-1];
		}
	}
	/*
	printf("makeParent\n");	
	for(int i=0; i<=maxLevel; i++){
		for(int j=0; j<=N; j++){
			printf("%d ",parent[j][i]);
		}
		printf("\n");
	}
	*/
}

void dfs(int x, int l){
	level[x] = l;
//	printf("dfs: level[%d] = %d\n", x, l);
	for(int next: adj[x]){
	//printf("dfs: next=%d\n", next);
			parent[next][0] = x;
			dfs(next, l+1);
	}
}

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


void printadj(){
	printf("printadj\n");
	for(int i=1; i<=N; i++){
		for(int next: adj[i]){
			printf("%d %d\n", i, next);	
		}
	}
}

#include <cstdio>
#include <vector>
// #include <cstdio>

using namespace std;

typedef struct _Edge {
	int des;
	int w;
	_Edge(int des, int w){
		this->des = des;
		this->w = w;
	}
} Edge;

int level[40010];
bool visit[40010];
int parent[25][40010];
int len[25][40010];
vector <Edge> adj[40010];
int maxLevel = 25;

int dfs(int x, int l);
void makeParent();
int swap(int*a, int*b);
int N, M;
int main(void){
	int s, e, w, a, b;
	int sum = 0;
	scanf("%d", &N);

	for(int i=0; i<N-1; i++){
		scanf("%d %d %d", &s, &e, &w);
		
		adj[s].push_back(Edge(e, w));
		adj[e].push_back(Edge(s, w));
	}
	dfs(1, 1);
	makeParent();

	scanf("%d", &M);
	for(int i=0; i<M; i++){
		sum = 0;
		scanf("%d %d", &a, &b); 

		if(level[a] < level[b])
			swap(&a, &b);	
		for(int j=maxLevel; j>=0; j--){
			if(level[a] - level[b] >= (1 >> j)){
				a = parent[j][a];
				sum += len[j][a];
			}
		}

		if(a == b){
			printf("%d\n",sum);
			continue;
		}

		for(int j=maxLevel; j>=0; j--){
			if(parent[j][a] != parent[j]){

			}
		}
	}



	return 0;
}

int dfs(int x, int l){
	level[x] = l;
	int next, w;
	for(Edge child: adj[x]){
		next = child.des;
		w = child.w;
		if(!visit[next]){
			visit[next] = true;
			parent[0][next] = x;
			len[0][next] = w;
			dfs(next, l+1);
		}
	}
}

void makeParent(){
	for(int i=1; i<maxLevel; i++){
		for(int j=1; j<=N; j++){
			parent[i][j] = parent[j-1][parent[i][j-1]];
			len[i][j] = len[i-1][j] + len[i-1][parent[i-1][j]];
		}
	}
}


int swap(int*a, int*b){
	int tmp = *a;
	*a = *b;
	*b = *a;
}


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void swap(int *a, int *b);
int find(int x);
int merge(int a, int b);

typedef struct _Edge {
	int s;
	int e;
	int w;
	_Edge(int s, int e, int w) {
		this->s = s;
		this->e = e;
		this->w = w;
	}
} Edge;

struct cmp{
	bool operator()(Edge a, Edge b){
		return a.w > b.w;
	}
};

int parent[10010];
vector <int> adj;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int V, E;
	int a, b, c, sum=0;
	priority_queue <Edge, vector<Edge>, cmp> edgeVec;

	cin >> V >> E;

	for(int i=1; i<=V; i++){
		parent[i] = i;
	}
	for(int i=0; i<E; i++){
		cin >> a >> b >> c;
		
		if(a > b)		swap(&a, &b);
		edgeVec.push(Edge(a, b, c));
		
	}
	while(!edgeVec.empty()){
		Edge edge = edgeVec.top();
		edgeVec.pop();
		int s = edge.s;
		int e = edge.e;
		int w = edge.w;
		if(find(s) == find(e))	continue;
		//cout <<"add " << s <<" "<< e <<" "<< w<<'\n';
		//cout << "s = " <<find(s) << " e = "<<find(e)<<'\n';
		merge(s, e);
		sum += w;
	}

	cout << sum;	
	return 0;
}

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int find(int x){
	if(parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

int merge(int a, int b){
	a = find(a);
	b = find(b);

	if(a > b)		swap(&a, &b);

	parent[b] = a;
}



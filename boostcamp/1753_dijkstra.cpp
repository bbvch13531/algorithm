#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define INF 0x3FFFFFFF

using namespace std;

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int>b) {
		return a.second > b.second;
	}
};

priority_queue <pair<int, int>, vector<pair<int, int> >, cmp > pq;

vector <pair<int, int> > W[20010];
vector <int> dist(20010, INF);

int main() {
	int V, E, K;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;
	cin >> K;

	for(int i=0; i<E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		W[u].push_back(make_pair(v, w));
	}

	dist[K] = 0;
	pq.push(make_pair(K, 0));

	while(!pq.empty()){
		int here = pq.top().first;
		int w = pq.top().second;

		pq.pop();

		if(w > dist[here])
			continue;

		for(int i=0; i<W[here].size(); i++){
			int near = W[here][i].first;
			int near_w = w + W[here][i].second;
//			cout << near << near_w << "\n";
			if(near_w < dist[near]) {
				dist[near] = near_w;
				pq.push(make_pair(near, near_w));
			}
		}
	}

	for(int i=1; i<=V; i++){
		if(dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}

	return 0;
}

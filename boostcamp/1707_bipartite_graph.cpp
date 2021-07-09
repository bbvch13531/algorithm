#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define ONE 1
#define TWO 2

using namespace std;

vector <int> graph[20010];
queue <int> q;
int visited[20010];

int K, V, E;

int main(){
	int u, v;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K;

	for(int t=0; t<K; t++){
		cin >> V >> E;
	
		for(int j=0; j<E; j++){
			cin >> u >> v;

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		for(int i=1; i<=V; i++){
			if(visited[i] == 0){
				visited[i] = ONE;
				
				q.push(i);
				int color = ONE;

				while(!q.empty()) {
					int here = q.front();
		//			cout << here << " ";
					q.pop();

					if(visited[here] == ONE )
						color = TWO;
					else
						color = ONE;

					for(int j=0; j<graph[here].size(); j++){
						int next = graph[here][j];
						if(visited[next] == 0){
							visited[next] = color;
							q.push(next);
						}
					}
				}

			}
		}
	//	cout << "--------------\n";
		int flag = 0;
		for(int i=1; i<=V; i++){
			for(int j=0; j<graph[i].size(); j++){
				int near = graph[i][j];
				if(visited[i] == visited[near]){
					// NO
//					cout << near << " " << i << "\n";
					flag = 1;
					break;
				}
			}
			if(flag == 1) break;
		}
		
		if(flag == 1) cout <<"NO\n";
		else cout <<"YES\n";

		memset(visited, 0, sizeof(visited));
		
		for(int i=1; i<=V; i++){
			graph[i].clear();
		}
	}

	return 0;
}


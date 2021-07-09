#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <int> arr[110];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, p, lt;
	
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		scanf("%d %d", &p, &lt);
		arr[p].push_back(lt);
	}

	for(int i=1; i<=N; i++){
		for(int j=0; j<arr[i].size(); j++){
			printf("%d:%d %d\n", i, j, arr[i][j]);
		}
	}
	return 0;
}

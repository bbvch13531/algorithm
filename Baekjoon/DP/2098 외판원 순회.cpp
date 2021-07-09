#define INF 1e+10
#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;

int TSP(int visited, int cur);

int N, dist[20][20], dp[20][1<<17];
int powerOfN;

int main(void){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
	scanf("%d", &N);
	powerOfN = pow(2, N);

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &dist[i][j]);	
		}
	}

	return 0;
}

int TSP(int visited, int cur){
	int k=0;
	if()
	if(visited == powerOfN)
		return dist[cur][0];
	else{
		while(1){
			if(visited & 1){	// 포함되어있음.
				return TSP(visited | (1 << k), k) + dist(cur, k);
			}
			else{
				k ++;
				visited >> 1;
			}
		}
	}
}

// http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220557403491

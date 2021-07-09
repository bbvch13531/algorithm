#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int TSP(int current, int visited);

int N, start, W[16][16], cache[16][65536];
const int IMPOSSIBLE = 1000000000;

int main(void){
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		
		int ans;
		cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
					cin >> W[i][j];
					
    memset(cache, -1, sizeof(cache));
		ans = TSP(0, 1);
		cout << ans;
		return 0;
}
/*
현재 외판원이 current번 마을에 있고, 방문한 마을 집합이 visited일 때
앞으로 남은 모든 마을을 방문하고 0번 마을로 돌아갈 때 드는 최소 비용
*/
int TSP(int current, int visited){
    /*
    기저 사례: 모든 마을을 방문한 경우,
    현재 마을에서 시작지점으로 갈 수 있으면 해당 비용을 리턴하고
    아닐 경우 불가능 값을 리턴한다.
    */
    if(visited == (1<<N)-1)
        return W[current][start]?W[current][start]:IMPOSSIBLE;
    int &ret = cache[current][visited];
    if(ret != -1) return ret;
 
    ret = IMPOSSIBLE;
    // 아직 방문하지 않은 모든 마을을 순회해 봄
    for(int i=0; i<N; i++){
        if(visited & (1<<i)) continue;
        if(W[current][i]==0) continue;
        ret = min(ret, TSP(i, visited | (1<<i)) + W[current][i]);
    }
    return ret;
}
 

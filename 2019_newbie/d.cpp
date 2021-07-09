#include <cstdio>

using namespace std;

int main(void){
	int dp[110] = {0, 0, 2, 6};
	int N;

	scanf("%d", &N);

	for(int i=4; i<=N; i++){
		dp[i] = 2 * dp[i-2] + dp[i-1];
	}
	
	for(int i=1; i<15; i++){
		printf("%d ", dp[i]);
	}
	return 0;
}

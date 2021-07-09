#include <cstdio>

using namespace std;

int main(void){
	long long N,M;
	long long ans=0;

	scanf("%lld %lld", &N, &M);
// M + M-1 + M-2 + ... + M-(N-1)	
//	ans = N * (2*M - N + 1) / 2;

	if(N > M){
		ans = M*(M+1)/2;
	}
	else {
		ans = N * (2 * M - N + 1) / 2;
	}
	printf("%lld", ans);
	return 0;
}
// 8 + 7 + 6 5 4 3 2

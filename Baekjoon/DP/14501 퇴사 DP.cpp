#include <iostream>
#include <vector>
#include <cstdio>

int t[20], p[20], dp[20];
int max(int a, int b);
int main(void){
	int N, maxNum = 0;
	
	scanf("%d", &N);
	
	for(int i=0; i<N; i++){
		scanf("%d %d", &t[i], &p[i]);
		dp[i] = p[i];
	}

	for(int i=1; i<N; i++){
		for(int j=0; j<i; j++){
			if(i - j >= t[j])
				dp[i] = max(p[i] + dp[j], dp[i]);
		}
	}

	for(int i=0; i<N; i++){
//		printf("%d ", dp[i]);
		if(i + t[i] <= N)
			if(maxNum < dp[i])
				maxNum = dp[i];
	}
	printf("%d", maxNum);
	return 0;
}

int max(int a, int b){
	if(a > b) return a;
	else return b;
}


#include <cstdio>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
long long MAX = 1e12;
int N, K;
long long dp[MAX];
vector <long long> rn, ans;

int main(void){
	long long tmp;
	scanf("%d %d",&N, &K);
	for(int i=0; i<N; i++){
		scanf("%d", &tmp);
		rn.push_back(tmp);
	}

	for(int i=0; i<N; i++){
		long long item = rn[i];
		if(dp[item] == 0){
			dp[item]++;
			ans.push_back(item);
		}
		else {
			long long next = dp[item];
			dp[
		}
	}

	return 0;
}


#include <iostream>
#include <queue>

#include <algorithm>
#include <functional>

#define RES 987654321
long long dp[10010] = {1, 0, 1,};
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	long long sum=0;
	cin >> N;
	for (int j = 4; j <= N; j+=2) {
		sum = 0;
		for (int i = 0; i <= j-2; i += 2) {
			sum += dp[i] * dp[j - 2 - i];
			sum %= RES;
	//		cout <<i << " " << j - 2 - i <<" "<< sum << "\n";
		}
		dp[j] = sum;
		cout << "dp[" << j << "] = " << dp[j] << "\n";
	}
	cout << dp[N] % RES ;
	return 0;
}

/*1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700, 1767263190, 6564120420, 24466267020, 91482563640, 343059613650, 1289904147324, 4861946401452, 18367353072152, 69533550916004, 263747951750360, 1002242216651368, 3814986502092304
 */
//
//
//779608869


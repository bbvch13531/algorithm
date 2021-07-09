#define ll long long
#include <iostream>
#include <vector>

using namespace std;

ll fastPow(ll a, ll b);

ll A, B, C;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> B >> C;

	cout << fastPow(A, B);
	return 0;
}

ll fastPow(ll a, ll b){
	if(b == 0) return 1;
	else if(b == 1) return a % C;
	
	ll n = fastPow(a, b/2);
	n %= C;
	if(b%2 == 1){
		return ((a * n) % C * n) % C;
	}
	else {
		return (n * n) % C; 
	}
}
/*
 * 곱셈 실패
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	14980	3625	2684	25.917%
문제
자연수 A를 B번 곱한 수를 알고 싶다. 단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 A, B, C가 빈 칸을 사이에 두고 순서대로 주어진다. A, B, C는 모두 2,147,483,647 이하의 자연수이다.

출력
첫째 줄에 A를 B번 곱한 수를 C로 나눈 나머지를 출력한다.

예제 입력 1
10 11 12
예제 출력 1
4
출처
문제를 만든 사람: author5
알고리즘 분류
수학
 */ 

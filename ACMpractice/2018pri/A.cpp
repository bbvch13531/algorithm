#define ll long long

#include <iostream>
#include <vector>
#include <vector>
#include <vector>

using namespace std;
ll expo2(int n);
ll process(int n);

ll ans[1000] = {0, 7,};
ll exp2[1000];
// 28 * 2n-1 - 5
//
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	ll num = 0, res = -1;
	cin>>N;

	for(int i=3; num <= N; i++){
		num = process(i);
		ans[i-1] = num;
	}
/*
	for(int i=0; i<100; i++){
		if(ans[i] != 0)
			//cout <<"ans["<<i<<"] ="<<ans[i]<<" ";
	}
	*/
	for(int i=1; i<1000; i++){
		if(ans[i] > N){
			res = i; 
			break;
		}
	}
	cout << res; 
	return 0;
}

ll expo2(int n){
	ll num=1;
	if(exp2[n] != 0)
		return exp2[n];

	for(int i=0; i<n; i++){
		num *= 2;
	}
	exp2[n] = num;
//	cout <<"exp2["<<n<<"] = "<<num<<"\n";
	return num;
}

ll process(int n){
	ll res = n * expo2(n) - 1;
}


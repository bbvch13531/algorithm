#include <iostream>
#include <vector>

using namespace std;

int main(void){
	int N, arr[110] = {0,};
	int sol[110] = {0,};
	
	cin >> N;

	for (int i=0; i<N; i++){
		int tmp;
		cin >> tmp;
		arr[i] = tmp;
	}
	int target = 0;
	int cnt = 1;
	for (int i=0; i<N; i++){
		int num = arr[i];
		sol[num]++;
	}
	
	int ans[110] = {0,};

	cnt = 0;
	for(int i=0; i<100; i++){
		if(sol[i] >1){
			ans[cnt] = sol[i];
			cnt++;
		}
	}

	for(int i=0; i<N; i++) {
		cout << sol[i] << " ";
	}
	cout <<endl;
	for(int i=0; i<N; i++) {
		cout <<ans[i]<< " ";
	}
		return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	string input, bomb;
	char answer[1000010] = {0,};
	int idx=0;

	cin >> input >> bomb;

	N = input.length();
	M = bomb.length();
	
	for(int i=0; i<N; i++){
		
		answer[idx] = input[i];
		idx++;

		if(answer[idx-1] == bomb[M-1]) {
			bool match = true;
			
			if(idx < M){
				continue;
			}
			for(int j=0; j<M; j++){
				if(answer[idx-j-1] != bomb[M-j-1]){
					match = false;
					break;
				}
			}
			
			if(match) {
				idx -= M;
			}
		}
	}

	if(idx == 0)
		cout << "FRULA";
	else{
		for(int i=0; i<idx; i++){
			cout << answer[i];
		}
	}
	return 0;
}

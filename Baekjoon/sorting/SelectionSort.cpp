#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(NULL), ios_base::sync_with_stdio(false);

	int N, tmp;
	vector <int> vec;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> tmp;
		vec.push_back(tmp);
	}
	
	for(int i=0; i<vec.size(); i++){
	  int minVal = 9999, minI = -1;
		for(int j=i; j<vec.size(); j++){
			if(vec[j] < minVal){
				minVal = vec[j];
				minI = j;
			}
		}
		tmp = vec[i];
		vec[i] = vec[minI];
		vec[minI] = tmp;
	}
	for(int ele: vec){
		cout << ele << "\n";
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int N, tmp;
vector <int> vec;

int partition(int low, int high) {
	int pivot = vec[low];
	int idx = low-1;

	for(int i=low+1; i<=high; i++){
		if(vec[i] < pivot){
			idx++;
			int tmp = vec[idx];
			vec[idx] = vec[i];
			vec[i] = tmp;
		}
	}
	int tmp = vec[idx+1];
	vec[idx+1] = vec[high];
	vec[high] = tmp;

	return idx+1;
}

void quickSort(int low, int high) {
	if(low < high) {
		int pi = partition(low, high);
		quickSort(low, pi - 1);
		quickSort(pi + 1, high);
	}
}

int main(){
	cin.tie(NULL), ios_base::sync_with_stdio(false);

		cin >> N;
	for(int i=0; i<N; i++){
		cin >> tmp;
		vec.push_back(tmp);
	}

	quickSort(0, N-1);

	for(int ele: vec){
		cout << ele << "\n";
	}
	return 0;
}

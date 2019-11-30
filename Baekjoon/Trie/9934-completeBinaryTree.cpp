#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main(void){
	int K, tmp;
	vector <int> arr;

	scanf("%d", &K);
	for(int i=0; i<K; i++){
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}
	return 0;
}


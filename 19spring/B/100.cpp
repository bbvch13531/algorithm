#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
	int N,D,ten=1;
	scanf("%d %d",&D, &N);

	for(int i=0; i<D; i++){
		ten *= 100;
	}
	if(N == 100){
		N = 101;
	}
	printf("%d",ten * N);
	return 0;
}

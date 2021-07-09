#include <cstdio>

using namespace std;

int main(void){
	int in[110], accu[110]={0,};
	int N;

	scanf("%d", &N);

	for(int i=0; i<N; i++){
		scanf("%d", &in[i]);
		if(i!=0){
			accu[i] = accu[i-1] + in[i];
		}
		else accu[i] = in[i];
	}
	int flag = 0;

	for(int i=0; i<N; i++){
		if(accu[i] == accu[N-1] - accu[i]){
			flag = 1;
			break;
		}
	}
	if(flag) printf("walga");
	else printf("walbu");
	return 0;
}
// 1 2 3 5 1
// 1 3 6 11 12

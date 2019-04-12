#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	int A,B;
	scanf("%d %d",&A, &B);

	if(A>8 || B>8){
		printf(":(");
	}
	else{
		printf("Yay!");
	}
	return 0;
}

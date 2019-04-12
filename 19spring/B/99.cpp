#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
	int A,B, i;
	scanf("%d %d",&A, &B);
	i = B-A-1;
	printf("%d", (i * (i+1)) / 2 - A);
	return 0;
}

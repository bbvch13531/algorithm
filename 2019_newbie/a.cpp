#include <cstdio>

using namespace std;

int main(void){
	int a,b,c,ans;
	scanf("%d %d %d",&a,&b,&c);
	if((a+b)%c == 0)
		ans = (a+b)/c;
	else
		ans = (a+b)/c +1;
	printf("%d",ans);
	return 0;
}

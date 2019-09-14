#include <iostream>
#include <stdio.h>

using namespace std;
void func(int n, int x, int y);
int twoexp(int n);
int cnt;
int map[16][16];
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, R, C, exp;
	cin>> N >> R >> C;
	exp = twoexp(N);
	cout<<"exp is "<<exp<<"\n";
	func(N, exp-1, exp-1);

	for(int i=0; i<exp; i++){
		for(int j=0; j<exp; j++){
			cout<<map[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}

void func(int n, int x, int y){
	if(n == 0){
		cout<<n<<" "<<cnt<<" "<<x<<" "<<y<<"\n"; 
		map[x][y] = cnt;
		cnt++;
		return ;
	}

	func(n/2, x/2, y/2);
	func(n/2, x/2, y);
	func(n/2, x, y/2);
	func(n/2, x, y);
}

int twoexp(int n){
	int num = 1;
	for(int i=0; i<n; i++)
		num *= 2;
	return num;
}

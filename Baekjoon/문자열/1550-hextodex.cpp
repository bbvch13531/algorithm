//solved
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	string hex;
	int dec=0;
	int digit=1;

	cin >> hex;
	
	int len = hex.length();
	for(int i=0; i<len; i++){
		char ch = hex[len-i-1];

		if('A' <= ch && ch <= 'F'){
			dec += (ch-'A'+10) * digit;
		}
		else if('0' <= ch && ch <= '9'){
			dec += (ch-'0') * digit;
		}
		digit *=16;
		
//		cout << dec << " ";
	}
	cout << dec;
	return 0;
}


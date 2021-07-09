// solved
#include <iostream>


using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num=0, tmp;
	for(int i=0; i<5; i++){
		cin >> tmp;

		num += tmp;
	}

	cout << num;
	return 0;
}

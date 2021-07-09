#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

vector <int> values;

void parseStr(string input);
int main(){
	string input;


	cin >> input;
	
	parseStr(input);

	
	return 0;
}

void parseStr(string input){
	int num;
	string str = input;
//	while(1){
	for(int i=0; i<10; i++){
		int minus = str.find("-");
		int plus = str.find("+");
		int next;
		if(minus ==-1 && plus == -1)
			break;
		else if(minus == -1)
			next = plus;
		else if(plus == -1)
			next = minus;
		else
			next =  min(minus, plus);
		cout << next << " ";
		
		string numstr = str.substr(0, next);
		sscanf(numstr.c_str(), "%d", &num);
		str = str.substr(next+1, str.length() - next);
		cout << num << " " << str<<endl;
		values.push_back(num);
	}
	
	sscanf(str.c_str(), "%d", &num);
	values.push_back()
}

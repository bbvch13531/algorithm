#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	int N;
	int len;
	char ch;
	string input, answer="";
	vector<string> filenames;
	
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> input;

		filenames.push_back(input);
	}
	
	len = input.length();
	
	for(int i=0; i<len; i++){
		int flag=0;

		for(int j=0; j<N-1; j++){
			ch = filenames[j][i];
			char next = filenames[j+1][i];

			if(ch != next){
				flag = -1;
			}
		}

		if(N==1){
			answer = filenames[0];
		} else{

		if(flag == 0){
			// all match
			answer.push_back(ch);
		} else {
			answer.push_back('?');
		}
		}
	}
	cout << answer;
	return 0;
}

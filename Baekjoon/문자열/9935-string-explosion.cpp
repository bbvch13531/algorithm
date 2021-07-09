#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

string reverse(string str);
int str_contain(string str1, string str2);
int main(){
	stack <char> stk;
	int N, M;
	string input, bomb;
	string tmp1, tmp2;
	cin>> input >>bomb;

	N = input.length();
	M = bomb.length();

	for(int i=0; i<N; i++){
		// stack에 들어있는 문자열과 bomb을 비교한다.
		stk.push(input[i]);

		for(int j=0; j<M; j++){
			tmp1 = "";

			if(stk.size() >= M){
			while(!stk.empty()){
				char top = stk.top();
				stk.pop();
				tmp1.push_back(top);
			}

//			cout << tmp1 <<endl;
			tmp2 = reverse(tmp1);
	//		cout << "compare tmp2 = " << tmp2 << endl;
			int idx = str_contain(tmp2, bomb); // tmp2에서 bomb를 찾으면
				if(idx != -1){
			//		cout << "match" <<endl;		
//					tmp2.erase(idx, M);
					
					// 지운다
		//			cout << "erased tmp2 = " << tmp2 << endl;
				}
			
				for(int k=0; k<tmp2.length(); k++){

					// 일치하는 문자열을 빼고 stk에 넣는다
					if(k == idx && idx != -1) {
						k+= M;
					}
					stk.push(tmp2[k]);
				}
			}
		}
	}
	string answer;

	if(stk.empty()){
		cout <<"FRULA";
	} else {
		while(!stk.empty()){
			char ch = stk.top();
			stk.pop();
			answer.push_back(ch);
		}
		cout << answer;
	}

	return 0;
}

string reverse(string str){
	string a;
	int len = str.length();
	for(int i=0; i<len; i++){
		a.push_back(str[len-i-1]);
	}
	return a;
}

int str_contain(string str1, string str2){
	bool flag;
	int len1 = str1.length();
	int len2 = str2.length();
	for(int i=0; i<len1-len2+1; i++){
	
		string sub = str1.substr(i, len2);
		
		if(sub == str2){
			//cout << "str_contain "<< str1 << " " << str2 << endl;
			return i;
		}
	}

	return -1;
}

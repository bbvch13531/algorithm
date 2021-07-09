#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <deque>

using namespace std;
vector<vector<int> > v;
string s;
int cnt_num[100010], ans[100010];

void parse(void);
int strtonum(int idx);
void print(void);

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int M=-1, ele;
	deque <int> ans_v;
	cin >> s;
	parse();
	print();

	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v[i].size(); j++){
			ele = v[i][j];
			if(ele>M)
				M = ele;
			cnt_num[ele]++;
		}
	}
	cout<<"M = "<<M<<"\n";

	for(int i=0; i<=M; i++){
		if(cnt_num[i] !=0)
			ans[cnt_num[i]] = i;
	}
	for(int i=0; i<10; i++){
		if(ans[i]!=0)
			ans_v.push_front(ans[i]);
	}
	for(int i=0; i<ans_v.size(); i++){
		cout<<ans_v[i]<<" ";
	}
	return 0;

}

void parse(void){
	int n = s.length();
	int ele_num=0, tuple_num=0;
	vector<int> tmp;

	for(int i=1; i<n-1; i++){
		if(s[i] == '{'){
			tmp.clear();	
		}
		else if('0' <= s[i] && s[i] <= '9'){
			if('0' <= s[i-1] && s[i-1] <= '9') continue;
			// get number from idx
			int res = strtonum(i);
//			cout<<"i = "<<i<<"\n";
			tmp.push_back(res);
		}
		else if(s[i] == ','){
			if(s[i+1] == '{'){
//				cout<<"push i = "<<i<<"\n";
				v.push_back(tmp);
			}
		}
		if(s[i] == '}' && s[i+1] == '}')
			v.push_back(tmp);
	}
}

int strtonum(int idx){
	int res = 0;
	for(int i=idx; i<s.length(); i++){
		if('0' <= s[i] && s[i] <= '9')
			res = res*10 + (s[i] - '0');
		else
			return res;
	}
	return res;
}

void print(){
	cout<<"print\n";
	for(int i=0; i<v.size(); i++){
			for(int j=0; j<v[i].size(); j++){
				cout<<v[i][j]<<" ";
			}
			cout<<"\n";
		}
}

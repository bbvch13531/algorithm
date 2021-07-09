#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

vector <int> ban_idx[10];
vector <string> user, ban;
int v[10], skip[10][10];
int skip_sum[10], total_sum;
int N, M, ans=0, skip_num, skip_cnt;
void match(void);
int nCm(int n, int m); 
int compare(string a, string b);
void DFS(int idx);

int main(void){
	string s;
	cin>>N>>M;

	for(int i=0; i<N; i++){
		cin>>s;
		user.push_back(s);
	}
	for(int i=0; i<M; i++){
		cin>>s;
		ban.push_back(s);
	}
	for(int i=0; i<M; i++){
		for(int j=i+1; j<M; j++){
			if(ban[i] == ban[j]){
				skip[skip_cnt][i] = skip[skip_cnt][j] = 1;
			}
		}
		skip_cnt++;
	}
	for(int i=0; i<skip_cnt; i++){
		for(int j=0; j<M; j++){
			if(skip[i][j] == 1){
				skip_sum[i]++;
				total_sum++;
			}
		}
	}
	match();
	DFS(0);
	for(int i=0; i<skip_cnt; i++){
		ans * nCm(ban_idx[i]
	}
	for(int i=0; i<M; i++){
		for(int j=0; j<ban_idx[i].size(); j++){
			cout<<ban_idx[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	cout<<"ans = "<<ans<<"\n";
	return 0;
}

void DFS(int idx){
	int ele=0;
	cout<<"DFS("<<idx<<"), size = "<<ban_idx[idx].size()<<"\n";
	if(idx == M-total_sum){
		ans++;
		cout<<"ans\n";
	}
	for(int i=0; i<ban_idx[idx].size(); i++){
//		cout<<"ban_idx[i] = "<<ban_idx[idx][i]<<"v[i] = "<<v[ele]<<"\n";
		ele = ban_idx[idx][i];
		if(!v[ele] && !skip[idx]){
			v[ele] = 1;
			cout<<"i = "<<i<<" idx = "<<idx<<" ele = "<<ele<<"\n";
			DFS(idx+1);
			v[ele] = 0;
		}
	}
}

void match(void){
    int flag = 0;
    for(int i=0; i<ban.size(); i++){
        flag = 0;
        for(int j=0; j<user.size(); j++){
          if(compare(ban[i], user[j])){
						// if match
						cout<<ban[i]<<" "<<user[j]<<"\n";
						ban_idx[i].push_back(j);
					}
        }
    }
}

int compare(string a, string b){
	int flag = 1;
	if(a.size() != b.size()) return false;

	for(int i=0; i<a.size(); i++){
			if(a[i] != b[i] && a[i] != '*')
				return false;
	
	}
	return true;
}

int nCm(int n, int m){
	int nfac=1, mfac=1;
	if(m > n/2)
		m = n-m;
	for(int i=0; i<m; i++){
		nfac = nfac*(n-i);
	}
	for(int i=1; i<=m; i++)
		mfac*=i;
	cout<<nfac<<" "<<mfac<<"\n";
	return nfac/mfac;
}

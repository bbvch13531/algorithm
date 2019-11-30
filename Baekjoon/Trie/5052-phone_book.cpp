#include <cstdio>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct Trie{
	Trie* next[10];
	bool isFinished;

	Trie(){
		memset(next, 0, sizeof(next));
	}
};


void insert(const string &key, int idx, Trie *t);
bool find(const string &key, int idx, Trie *t);
Trie root;
vector <string> in;

int main(void){
	int T, N;
	string str;
	char tmp[20];
	
	scanf("%d", &T);

	while(T--){
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			scanf("%s", tmp);
			str = tmp;
			in.push_back(str);
			insert(in[i], 0, &root);
		}
		int flag = 0;
		for(int i=0; i<N; i++){
			if(!find(in[i], 0, &root))
				flag = 1;
		}
		if(flag)	printf("NO\n");
		else	printf("YES\n");
	}
	return 0;
}

void insert(const string &key, int idx, Trie *t){
	if(idx == key.length()-1){
		t->isFinished = true;
		return ;
	}

	else {
		int cur = key[idx+1] - '0';
		if(t->next[cur] == NULL)
			t->next[cur] = new Trie;
		insert(key, idx+1, t->next[cur]);
	}
}

bool find(const string &key, int idx, Trie *t){
	if(t == NULL) 
		return false;
	if(idx == key.length()-1)
		return true;
	int cur = key[idx+1] - '0';
	return find(key, idx+1, t->next[cur]);
}

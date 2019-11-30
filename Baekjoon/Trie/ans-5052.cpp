#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

struct Trie {
	Trie* next[26];
	bool finish;

	Trie(){
		memset(next, 0, sizeof(next));
	}

	~Trie(){
		for(int i=0; i<26; i++){
			if(next[i] != NULL)
				delete next[i];
		}
	}

	void insert(const char* key){
		// 문자열이 끝난 경우
		if(*key == NULL) finish = true;
		else {
			int cur = *key - '0';
			if(next[cur] == NULL)
				next[cur] = new Trie();
			next[cur]->insert(key+1);
		}
	}

	bool find(const char* key){
		if(*key == NULL) return false;
		if(finish) return true;

		int cur = *key - '0';
		return next[cur]->find(key+1);
	}
};

Trie* root;

int main(void){
	int T, N;
	char input[10010][20];
	
	scanf("%d", &T);
	for(int i=0; i<T; i++){
		scanf("%d", &N);
		getchar();
		root = new Trie;
		
		for(int j=0; j<N; j++){
			scanf("%s", input[j]);

			root->insert(input[j]);
		}
	
	int flag = 0;
	for(int j=0; j<N; j++){
		if(root->find(input[j]))
			flag = 1;
	}
	if(flag)	printf("NO\n");
	else printf("YES\n");
	}

	return 0;
}

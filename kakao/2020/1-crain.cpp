#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

void print(void);

vector <vector<int> > board;
vector <int> moves;
stack <int> stk;

int N, M;

int main(void){
	int in, ans=0;
	int tmp_board[40][40];
	vector<int> tmp;
	scanf("%d", &N);
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &tmp_board[i][j]);
		}
	}

	for(int i=0; i<N; i++){
		for(int j=N-1; j>=0; j--){
			if(tmp_board[j][i] != 0){
				tmp.push_back(tmp_board[j][i]);
			}
		}
		board.push_back(tmp);
		tmp.clear();
	}

	scanf("%d", &M);
	for(int i=0; i<M; i++){
		scanf("%d", &in);
		moves.push_back(in);
	}
//	print();
	
	for(int i=0; i<moves.size(); i++){
		int idx = moves[i];
		if(board[idx-1].empty())
			continue;
		int item = board[idx-1].back();
	//	printf("%d item=%d\n", idx, item);
		board[idx-1].pop_back();
	
		if(stk.empty()){
		//	printf("push %d\n",item);
			stk.push(item);
		}
		else if(stk.top() == item){	
			stk.pop();
			//printf("pop %d\n",item);
			ans++;
		}
		else{
			//printf("push %d\n", item);
			stk.push(item);
		}
	}
	/*
	for(int i=0; i<stk.size(); i++){
		int top = stk.top();
		stk.pop();
	}
	*/
	printf("%d\n",ans*2);
	return 0;
}
void print(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
}


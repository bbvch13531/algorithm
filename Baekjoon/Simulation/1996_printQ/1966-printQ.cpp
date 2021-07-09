#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>
#include <utility>
using namespace std;

deque <pair<int, int> > q;
pair<int, int> ans[110];
void print();
int main(void){
	int T, N, M;
	int tmp, cnt=0, flag=0;

	scanf("%d",&T);

	for(int i=0; i<T; i++){
		scanf("%d %d", &N, &M);
		for(int j=0; j<N; j++){
			scanf("%d", &tmp);
			q.push_back(make_pair(tmp, j));
			// priority, index
		}
		
/*
		for(int j=0; j<N; j++)
			printf("%d ", q[j]);
		printf("\n");
	*/	
		while(!q.empty()){
			flag = 0;
			for(int j=1; j<q.size(); j++){
	//			print();
				if(q[0].first < q[j].first){	// compare priority
					// pop and push to back
					pair<int, int> front = q.front();
					q.pop_front();
					q.push_back(front);
					flag = 1;
					break;
				}
			}
			if(!flag){
				// if current item has highest priority
	//			printf("highest: %d %d\n", q[0].first, q[0].second);
//					print();
				// push it to ans arr and pop from `deque q`
				ans[cnt] = q[0];
				cnt++;
				q.pop_front();
			}
		
			if(cnt==N) break;
		}
		for(int i=0; i<N; i++){
			if(ans[i].second == M){
//				printf("ans: idx=%d, priority=%d\n", i+1, ans[i].first);
				printf("%d\n", i+1);
				break;
			}
		}

		// initialize to zero
		for(int i=0; i<cnt; i++)
			ans[i] = make_pair(0, 0);
		q.clear();
		cnt=0;
	}
	return 0;
}

void print(){
	for(int i=0; i<q.size(); i++){
		printf("%d ", q[i].first);
	}
	printf("\n");
}

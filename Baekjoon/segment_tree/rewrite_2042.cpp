#define ll long long

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

ll init(int l, int h, int n);
ll sum(int l, int h, int n, int s, int e);
void update(int l, int r, int i, ll diff);
int	get_tree_height(int N);
void print_tree();

vector<ll> input;
vector<ll> seg_tree;

int tree_height=0;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M, K;
	int num, b, c;
	ll ans=0;

	cin >> N >> M >> K;

	for(int i=0; i<N; i++){
		cin >> num;
		input.push_back(num);
	}
	ll size = pow(2, N);
	seg_tree.resize(size);
	tree_height =	get_tree_height(N);
	// seg_tree 생성
	init(0, N-1, 0);
	for(int i=0; i<N*2; i++){
		cout << seg_tree[i] <<" ";

	}
/*	
	for(int i=0; i<M+K; i++){
		cin >> num >> b >> c;
		
		if(num == 1){		// update
			update(0, N-1, b-1, c-1);
			print_tree();
		}

		else{		// get_sum
			ans = sum(0, N-1, 0, b-1, c-1);
			cout << ans << "\n";
		}
	
	}
*/
	print_tree();
	return 0;
}

// 찾으려는 구간 [l, h]
// node의 범위 [s, e]
ll sum(int l, int h, int n, int s, int e){
	int mid = (s + e) / 2;

	if(h < s || e < l)	return 0;
	else if(l <= s && e <= h) return seg_tree[n];
	else {
		return sum(l, h, n * 2+1, s, mid) + sum(l, h,(n+1) * 2, mid+1, e);
	}
}

ll init(int l, int h, int n){
	int mid = (l + h) / 2;
//	cout <<"init(): " << l <<" "<<h <<" "<<n<<" ";
	if(l == h) return seg_tree[n] = input[l];
	else {
		seg_tree[n] = init(l, mid, n * 2 + 1) + init(mid+1, h, (n+1) * 2);
//		cout <<seg_tree[n]<<"\n";
		return seg_tree[n];
	}
}

void update(int l, int h, int n, ll diff){
	if( n < l || h < n) return ;
	int m = (l + h) / 2;
	seg_tree[n] = seg_tree[n] + diff;

	if(l != h){
		update(l, m, n*2+1, diff);
		update(m+1, h, (n+1)*2, diff);
	}
}

int	get_tree_height(int N){
	int lv = 0;

	while(1){
		if(pow(2, lv) >= N)
			return lv;
		lv++;
	}
}

void print_tree(){
	int size = seg_tree.size();
	for(int i=0; i<size; i++){
		printf("%lld ", seg_tree[i]);
	}
	printf("\n\n");
}

/*
5 2 2
1
2
3
4
5
1 3 6
2 2 5
1 5 2
2 3 5
 */

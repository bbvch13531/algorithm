/*
2042 구간 합 구하기.cpp

I번째 수를 바꾸고 [a,b]의 구간합을 구하는 문제.
*/

#include <iostream>
#include <vector>
#include <cmath>

#define ll long long

using namespace std;

vector <ll> seg_tree;
vector <ll> input;

void update(int l, int r, int i, ll diff);
ll init(int l, int r, int i);
ll get_sum(int l, int r, int i, int a, int b);

int tree_height=0;
// 세그트리 공부 다시하자..
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    int num, opt;
    int idx, sum_start, sum_end;
    ll chg;

    cin>> N>> M>> K;
    
		// calculate tree height
    while(1){
        if(pow(2, tree_height) >= N)
            break;
        tree_height++;
    }

    for(int i=0; i<N; i++){
        cin>> num;
        input.push_back(num);
    }

		// build seg tree
    init(0, N-1, 0);

    for(int i=0; i<M+K; i++){
        cin>> opt;
        if(opt == 1){
            cin>> idx >> chg;
        }
        else if(opt == 2){
            cin>> sum_start>> sum_end;
        }
    }
    return 0;
}

ll init(int l, int r, int i){
    int mid = (l + r) / 2;
    if(l == r){
        return seg_tree[i] = input[l];
    }
    else{
        seg_tree[i] = init(l, mid, i*2) + init(mid+1, r, i*2 + 1);
        return seg_tree[i];
    }
}

// update
// l: left index
// r: right index
// i: index of node to be updated
// diff: difference
void update(int l, int r, int i, ll diff){
    int m = (l + r) / 2;
    if(i < l || r < i) return;
    seg_tree[i] = seg_tree[i] + diff;

    if(l != r){
        update(l, m, i*2, diff);
        update(m+1, r, i*2+1, diff);
    }
}

// get_sum
// l: left index
// r: right index
// i: index of node
// a: from a
// b: to b
ll get_sum(int l, int r, int i, int a, int b){
    int m = (l+r)/2;
    if(l >  b || r < a){
        return 0;
    }
    if(l <= a && b <= r){
        return seg_tree[i];
    }
    return get_sum(l, m, i*2, a, b) + get_sum(m+1, r, i*2 + 1, a, b);
}

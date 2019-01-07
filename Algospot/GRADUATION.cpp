//
//  GRADUATION.cpp
//  Algorithm
//
//  Created by KyungYoung Heo on 2018. 10. 4..
//  Copyright © 2018년 KyungYoung Heo. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <vector>

#define CIN_FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x6fffffff

using namespace std;

int bitCount(int n);

// 현재 학기가 semester이고, 지금까지 들은 과목의 집합이 taken일 때 앞으로 다녀야 하는 최소 학기의 수
int graduate(int semester, int taken);

int cache[15][1<<12], prerequisite[15], classes[15];
int C,N,K,M,L;

int main(){
	int ri,bit,ci;
	CIN_FAST
	
	cin>>C;
	
	for(int tc=0; tc<C; tc++){
		// cache 초기화
		for(int i=0; i<15; i++){
			for(int j=0; j<1<<12; j++){
				cache[i][j] = -1;
			}
		}
		for(int i=0; i<15; i++){
			prerequisite[i] = 0;
			classes[i] = 0;
		}
		cin >> N >> K >> M >> L;
		for(int i=0; i<N; i++){
			cin >> ri;
			for(int j=0; j<ri; j++){
				cin >> bit;
				// prerequisite[ri] 의 bit번째 자리를 1로 만든다.
				prerequisite[i] |= (1 << bit);
			}
		}
		for(int i=0; i<M; i++){
			cin >> ci;
			for(int j=0; j<ci; j++){
				cin >> bit;
				// classes[ci] 의 bit번째 자리를 1로 만든다.
				classes[i] |= (1 << bit);
			}
		}
		int ans = graduate(0, 0);
		if(ans>=INF)
			cout<<"IMPOSSIBLE"<<endl;
		else
			cout<<ans<<endl;
		/*
		 2
		 4 4 4 4
		 0
		 1 0
		 3 0 1 3
		 0
		 4 0 1 2 3
		 4 0 1 2 3
		 3 0 1 3
		 4 0 1 2 3
		 4 2 2 4
		 1 1
		 0
		 1 3
		 1 2
		 3 0 2 3
		 3 1 2 3
		 */
	}
	return 0;
}

int bitCount(int n){
	// n의 이진수 표현에서 켜진 비트의 수를 반환.
	int cnt=0;
	while(n != 0){
		if(n % 2 == 1) cnt++;
		n /= 2;
	}
	return cnt;
}

int graduate(int semester, int taken){
	// 기저사례: 과목 K개 이상 수강한 경우
	if(bitCount(taken) >= K) return 0;
	// 기저사례: 학기 M개 이상 지나간 경우
	if(semester == M) return INF;
	
	// 메모이제이션
	int &ret = cache[semester][taken];
	if(ret!=-1)
		return ret;
	ret = INF;
	
	// 이번 학기에 들을 수 있는 과목 중 아직 듣지 않은 과목들을 찾는다.
	int canTake = (classes[semester] & ~taken);
	
	// 선수 과목을 다 듣지 않은 과목들을 걸러낸다.
	
	for(int i=0; i<N; i++){
		if((canTake & (1 << i)) && (taken & prerequisite[i]) != prerequisite[i])
			canTake &= ~(1 << i);
	}
	// 이 집합의 모든 부분집합들을 순회한다.
	
	for(int take = canTake; take > 0; take = ((take - 1) & canTake)){
	// 한 학기에 1과목까지만 들을 수 있다.
		if(bitCount(take) > L) continue;
		ret = min(ret, graduate(semester + 1, taken | take) + 1);
	}
	
	// 이번 학기에 아무 것도 듣지 않을 경우
	ret = min(ret, graduate(semester + 1, taken));
	return ret;
}

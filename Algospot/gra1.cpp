//
//  gra1.cpp
//  Algorithm
//
//  Created by KyungYoung Heo on 2018. 10. 5..
//  Copyright © 2018년 KyungYoung Heo. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N, K, M, L; // 전공과목수, 들어야할 과목수, 학기의 수, 한학기 최대들을수있는 과목수

const int MAXN = 12;
const int INF = 987654321;

int prerequisite[MAXN]; // 선수과목의 수
int classes[10]; // i 번학기에 개설되는 과목의 집합
int cache[10][1 << MAXN];

int bitCount(int n) {
	int bitcount = 0;
	int checkbit;
	for (int i = 0; i < 12; ++i) {
		checkbit = (1 << i);
		
		if ((checkbit & n) == 0) continue;
		else ++bitcount;
	}
	
	return bitcount;
	/*if (n == 0) return 0;
	 return n % 2 + bitCount(n / 2);*/
}

int graduate(int semester, int taken) {
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

void init() {
	memset(prerequisite, 0, sizeof(prerequisite));
	memset(classes, 0, sizeof(classes));
	memset(cache, -1, sizeof(cache));
}

int main() {
	std::ios::sync_with_stdio(false);
	
	int C, num, num2;
	cin >> C;
	
	while (C--) {
		cin >> N >> K >> M >> L;
		
		init();
		for (int i = 0; i < N; ++i) { // 전공과목 정보 입력
			cin >> num;
			
			for (int j = 0; j < num; ++j) {
				cin >> num2;
				//pre_sub[i] += (int)pow(2.0, num2);
				prerequisite[i] |= (1 << num2);
			}
		}
		
		for (int i = 0; i < M; ++i) {
			cin >> num;
			for (int j = 0; j < num; ++j) {
				cin >> num2;
				//classes[i] += (int)pow(2.0, num2);
				classes[i] |= (1 << num2);
			}
		}
		
		int answ = graduate(0, 0);
		if (answ >= INF) {
			cout << "IMPOSSIBLE" << endl;
		}
		else {
			cout << answ << endl;
		}
	}
	
	return 0;
}

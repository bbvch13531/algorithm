//
//  13333 q-index.cpp
//  Algorithm
//
//  Created by KyungYoung Heo on 2018. 9. 28..
//  Copyright © 2018년 KyungYoung Heo. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	int N,arr[1010];
	int max = -1, cnt;
	bool isTrue;
	scanf("%d",&N);
	
	for(int i=0; i<N; i++){
		scanf("%d",&arr[i]);
		if(arr[i]>max) max = arr[i];
	}
	
	
	return 0;
}

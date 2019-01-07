//
//  13335 Truck.cpp
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
	int N,W,L;
	int trucks[1010],truckSum[1010]={0,};
	int idx=0,sum=0,time=0,cnt=0;
	
	scanf("%d %d %d",&N,&W,&L);
	
	for(int i=0; i<N; i++){
		scanf("%d",&trucks[i]);
		if(i==0) truckSum[i] = trucks[i];
		else truckSum[i] = truckSum[i-1] + trucks[i];
	}
	
	while(1){  // 트럭 n대 반복
		
		if(idx >= N) break;
			
		for(int i=W-1; i>=0; i--){ // 한번에 다리에 올라갈 수 있는 트럭 W대, 최대무게 L이내인지 확인
			if(idx + i <N){
			if(idx == 0){
				if(truckSum[idx+i] <= L){
					idx += i;
					if(i!=0)	cnt++;
					
				}
			}
			
			else{
				if(truckSum[idx+i] - truckSum[idx-1] <= L ){
					idx += i;
					if(i!=0)	cnt++;
					break;
				}
			}
			}
		}
		idx++;
		time++;
	}
	printf("cnt : %d\n",cnt);
	printf("%d\n",N * W - 1 - cnt);
	return 0;
}

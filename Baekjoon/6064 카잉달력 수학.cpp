//
//  6064 카잉달력 수학.cpp
//  Algorithm
//
//  Created by KyungYoung Heo on 2018. 9. 14..
//  Copyright © 2018년 KyungYoung Heo. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> canX,canY;

int gcd(int a,int b);

int main(void){
	int T,M,N,X,Y,x,y;
	int ans,iterX,iterY;
	long long lcm,i;
	bool isSuccess;
	
	scanf("%d",&T);
	for(int t=0; t<T; t++){
		scanf("%d %d %d %d",&M,&N,&X,&Y);
		isSuccess = false;
		x=y=1;
		lcm = M / gcd(M,N);
		lcm *= N;
		canX.clear();
		canY.clear();
		
		iterX = lcm / M;
		if(lcm%M==0) iterX++;
		iterY = lcm / N;
		if(lcm%N==0) iterY++;
		
		for(int ii=0; ii<iterX; ii++){
			canX.push_back(X+ii*M);
		}
		for(int jj=0; jj<iterY; jj++){
			canY.push_back(Y+jj*N);
		}
		
//		for(int j=0;j<canX.size();j++) printf("%d ",canX.at(j));
//		cout<<endl<<endl;
//		for(int j=0;j<canY.size();j++) printf("%d ",canY.at(j));
		
		
			for(int k=0;k<canY.size();k++){
				
				if(binary_search(canX.begin(), canX.end(), canY.at(k))){
					isSuccess = true;
					ans = canY.at(k);
					break;
				}
			}
		
////		printf("X = %d, Y = %d\n",X,Y);
////		cout<<"lcm = "<<lcm<<endl;
//		for(i=1; i<=lcm; i++){
//			if(x == X && y == Y){
//				isSuccess = true;
//				break;
//			}
//			x++;
//			y++;
//
//			if(x == M+1) x = 1;
//			if(y == N+1) y = 1;
//
////			cout<<"i = "<<i<<" x = "<<x<<" y = "<<y<<endl;
//		}
		
		if(isSuccess) printf("%d\n",ans);
		else printf("-1\n");
	}
	
	return 0;
}
int gcd(int a,int b){
	int res = -1;
	
	if(a<b){
		int tmp = a;
		a = b;
		b = tmp;
	}
	
	
	while (res!=0) {
		res = a % b;
		a = b;
		b = res;
	}
	
	return a;
}

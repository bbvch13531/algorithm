//
//  2750 수 정렬하기 정렬.cpp
//  Algorithm
//
//  Created by KyungYoung Heo on 2018. 11. 4..
//  Copyright © 2018년 KyungYoung Heo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv){
	int N,tmp,flag=0;
	vector <int> arr;
	
	cin>>N;
	
	for(int i=0; i<N; i++){
		cin>>tmp;
		arr.push_back(tmp);
	}
	
	for(int i=0; i<N; i++){
//		flag = 0;
		
		for(int j=i+1; j<N; j++){
			
//			if(flag == 1) continue;
			
			if(arr[i] > arr[j]){
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
				
//				flag = 1;
			}
		}
	}
	
	for(int i=0; i<N; i++){
		cout<< arr[i]<<"\n";
	}
	
	return 0;
}

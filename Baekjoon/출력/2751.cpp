//
//  2751 수 정렬하기2 정렬.cpp
//  Algorithm1
//
//  Created by KyungYoung Heo on 2018. 11. 4..
//  Copyright © 2018년 KyungYoung Heo. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argv, char**argc){
	int N,buf;
	vector <int> arr;
	
	cin>>N;
	
	make_heap(arr.begin(), arr.end());
	for(int i=0; i<N; i++){
		cin>>buf;
		
		arr.push_back(buf);
		push_heap(arr.begin(),arr.end());
	}
	sort_heap(arr.begin(), arr.end());
	for(int j=0; j<N; j++){
			cout<< arr[j]<<"\n";
	}
	return 0;
}
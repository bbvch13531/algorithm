//
//  13328 message passing.cpp
//  Algorithm
//
//  Created by KyungYoung Heo on 2018. 9. 28..
//  Copyright © 2018년 KyungYoung Heo. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
using matrix = vector<vector<int>>;

#define limit 31991

int D,T;

matrix operator * (matrix a,matrix b){
	matrix res=vector<vector<int>>(a.size(),vector<int>(b[0].size()));
	
	int i,j,k;
	
	for(i = 0;i < a.size();i++){
		for(j = 0;j < b[0].size();j++){
			int sum = 0;
			for(k = 0;k < a[0].size();k++){
				sum = (sum + (a[i][k] * b[k][j]) % limit) % limit;
			}
			
			res[i][j] = sum;
		}
	}
	
	return res;
}

matrix make_matrix(int d);
matrix powm(matrix x, int y);

int main(){
	scanf("%d %d",&D,&T);
	
	matrix A = make_matrix(D + 1);
	matrix K = powm(A, T - D);
	matrix X = vector<vector<int>>(D + 1,{0});
	
	int i;
	
	for(i = 0;i < D + 1;i++){
		X[D - i][0] = 1 << i;
	}
	
	matrix ANS = K * X;
	
	printf("%d\n",(ANS[0][0] - ANS[D - 1][0])%limit);
	
	return 0;
}
matrix make_matrix(int d){
	int i;
	matrix res = vector<vector<int>>(d,vector<int>(d));
	
	res[0][0] = 2;
	res[0][d - 1] = -1;
	
	for(i = 1;i < d;i++){
		res[i][i - 1] = 1;
	}
	
	return res;
}
matrix powm(matrix x, int y){
	static map<int,matrix> dict;
	
	auto p = dict.find(y);
	if(p == dict.end()){
		if(y == 0){
			matrix p(x.size(),vector<int>(x.size()));
			
			for(int i = 0;i < x.size();i++){
				for(int j = 0;j < x.size();j++){
					p[i][j] = (i == j) ? 1 : 0;
				}
			}
			
			dict[y] = p;
		}
		else if(y % 2 == 0)
			dict[y] = powm(x,y / 2) * powm(x,y / 2);
		else
			dict[y] = powm(x,y - 1) * x;
	}
	return dict[y];
}

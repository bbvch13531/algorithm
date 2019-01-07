//
//  6209 제자리 멀리뛰기 이분탐색.cpp
//  Algorithm
//
//  Created by KyungYoung Heo on 2018. 3. 30..
//  Copyright © 2018년 KyungYoung Heo. All rights reserved.
//
#define MAX_D 1000000000
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

bool solve(int);

int D,N,M,in[50010]={0,};

int main(void){
    
    int lb,ub,x;
    
    scanf("%d %d %d",&D,&N,&M);
    for(int i=0;i<N;i++){
        scanf("%d",&in[i+1]);
    }
    in[0]=0;
    in[N+1]=D;
    lb=0;
    ub=MAX_D;
    sort(in,in+N+2);
    while (lb<ub) {
        x=(lb+ub+1)/2;
        if(solve(x))    lb=x;
        else ub=x-1;
    }
    printf("%d",ub);
    return 0;
}

bool solve(int x){
    int cur=0,cnt=0;
    for(int i=1;i<N+2;i++){
        if(cur+x>in[i]) cnt++;
        else cur=in[i];
    }
    return (cnt<=M && cur==D);
    /*  cur==D가 있는 이유??
        만약 마지막 도착지점을 뛰어넘는 경우가 생긴다면?
        1) 도착지점을 뛰어넘는 경우는 발생하지 않는다 - x가 커지는 경우.
    */
}

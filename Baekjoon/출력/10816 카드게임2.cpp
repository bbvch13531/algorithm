//
//  10816 카드게임2.cpp
//  Algorithm
//
//  Created by KyungYoung Heo on 2018. 3. 23..
//  Copyright © 2018년 KyungYoung Heo. All rights reserved.
//
#define MAXN 10000010
#include <cstdio>
#include <iostream>
using namespace std;

int card1[MAXN],card2[MAXN];
int main(void){
    int N,M,buf;
    const int offset = 10000000;
    cin>>N;
    for(int i=0;i<N;i++){
        scanf("%d",&buf);
        if(buf>=0)  card1[buf]++;
        else    card2[buf+offset]++;
    }
    cin>>M;
    for(int i=0;i<M;i++){
        scanf("%d",&buf);
        if(buf>=0)  printf("%d ",card1[buf]);
        else    printf("%d ",card2[buf+offset]);
    }
    return 0;
}

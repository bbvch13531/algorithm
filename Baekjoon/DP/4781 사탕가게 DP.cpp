//
//  4781 사탕가게 DP.cpp
//  Algorithm
//
//  Created by KyungYoung Heo on 2018. 3. 14..
//  Copyright © 2018년 KyungYoung Heo. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int calory[5010],dp[10010],price[5010];
int main(void){
    int N=1,M,maxV;
    double buf=1.0;
    
    while(1){
        cin>>N>>buf;
        if(N==0 && buf==0.0) break;
        M=(int)(buf*100+0.5);
        
        memset(dp, 0, sizeof(dp));
        
        for(int i = 1; i <= N; i++){
            cin>>calory[i]>>buf;
            price[i]=(int)(buf*100+0.5);
        }
        for(int i=1;i<=N;i++){
            for(int j=0;j<=M;j++){
                if(j>=price[i]) dp[j]=max(dp[j] , dp[j - price[i]] + calory[i]);
            }
        }
        maxV=-1;
        for(int i=1;i<=M;i++){
            maxV = max(maxV, dp[i]);
        }

        cout<<maxV<<endl;
    }
    
    return 0;
}

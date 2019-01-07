//
//  14816 fresh chocolate.cpp
//  Algorithm
//
//  Created by bbvch13531 on 2018. 3. 24..
//  Copyright © 2018년 bbvch13531. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main(void){
    int T,N,P,a[110],b[10]={0,},ans,ret;
    cin>>T;
    
    for(int i=0;i<T;i++){
        ans=ret=0;
        cin>>N>>P;
        memset(b, 0, sizeof(b));
        for(int j=0;j<N;j++){
            cin>>a[j];
            b[ a[j] % P ]++;
        }
        ans+=b[0];
        if(P==2){
            ans+=(b[1]+1)/2;
        }
        
        else if(P==3){
            ret=min(b[1],b[2]);
            b[1]-=ret;
            b[2]-=ret;
            ans+=ret;
            
            ans+=(b[2]+2)/3;
            ans+=(b[1]+2)/3;
        }
        else{   //P==4
            ret=min(b[1],b[3]);
            b[1]-=ret;
            b[3]-=ret;
            ans+=ret;
            
            ret=b[2]/2;
            b[2]%=2;
            ans+=ret;
            //위 과정을 거치면 2는 0개 or 1개, 1만 남거나 3만 남는다.
            if(b[2]>0 && b[1]>=2){  //2+1+1
                b[2]=0;
                b[1]-=2;
                ans++;
            }
            if(b[2]>0 && b[3]>=2){  //2+3+3
                b[2]=0;
                b[3]-=2;
                ans++;
            }
            if(b[2]>0){ //2 1개 남는 경우
                b[2]=0;
                ans++;
            }
            else{   //1과 3이 남지만 위 조건에 해당하지 않는 경우
                ans+=(b[1]+3)/4;
                ans+=(b[3]+3)/4;
            }
        }
        printf("Case #%d: %d\n",i+1,ans);
    }
    return 0;
}

//
//  5527 전구장식 비트.cpp
//  Algorithm
//
//  Created by KyungYoung Heo on 2018. 3. 20..
//  Copyright © 2018년 KyungYoung Heo. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

int main(void){
    int N,maxRes=-1,ans;
    char ch;
    bitset<100010> bit1,bit01,bit10;
    
    cin>>N;
    
    for(int i=0;i<N;i++){
        cin>>ch;
        if(ch=='0') bit1.set(i,0);
        else bit1.set(i,1);
        if(i%2==0){
            bit10.set(i,0);
            bit01.set(i,1);
        }
        else{
            bit10.set(i,1);
            bit01.set(i,0);
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            //bit1 [i,j]를 비트반전시킨다.
            
            //010101과 101010과 bit cmp를 해서 최댓값 찾는다.
            
            //if(ans>maxRes) maxRes=ans;
        }
    }
    
    cout<<bit1;
    return 0;
}

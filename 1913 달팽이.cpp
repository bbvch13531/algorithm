//
//  달팽이.cpp
//  Baekjoon
//
//  Created by KyungYoung Heo on 2017. 9. 29..
//  Copyright © 2017년 KyungYoung Heo. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

vector <pair <int,int> > pos;

int main(void){
    int ar[1000][1000],N,K;
    int dir=1,num,cnt,i=-1,j=0;
    
    cin>>N>>K;  //입력
    num=N*N;
    pos.resize(N*N+1);  //크기 재할당
    cnt=N;
    while (1) {
        for(int m=0;m<cnt;m++){
            i=i+dir;
            ar[i][j]= num;
            pos[num]=make_pair(i,j);
            num--;
        }
        cnt--;
        
        if(cnt<0) break;
        
        for(int m=0;m<cnt;m++){
            j=j+dir;
            ar[i][j]=num;
            pos[num]=make_pair(i,j);
            num--;
        }
        
        dir*=-1;
   }
    
    for(int m=0;m<N;m++){
        for(int n=0;n<N;n++){
            printf("%d ",ar[m][n]);
        }
        printf("\n");
    }
    /*
    for(int k=0;k<N*N;k++){
        cout<<pos[k].first<<" "<<pos[k].second<<endl;
    }
    */
    cout<<pos[K].first+1<<" "<<pos[K].second+1;
    return 0;
}

//
//  2592 대표값 출력.cpp
//  Baekjoon
//
//  Created by KyungYoung Heo on 2017. 10. 9..
//  Copyright © 2017년 KyungYoung Heo. All rights reserved.
//

#include <iostream>

using namespace std;
int main(void){
    int arr[11],average=0,count[1000]={0,},min=1001,max=-1,maxcnt=0,num;
    for(int i=0;i<10;i++){
        cin>>arr[i];
        average+=arr[i];
        count[arr[i]]++;
        
        if(arr[i]>max) max=arr[i];
        if(arr[i]<min) min=arr[i];
    }
    average/=10;
    for(int i=min;i<=max;i++){
        if(count[i]>maxcnt){
          maxcnt=count[i];
            num=i;
        }
    }
    cout<<average<<endl<<num;
    return 0;

}

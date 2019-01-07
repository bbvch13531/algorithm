//
//  selfdup.cpp
//  Algorithm
//
//  Created by KyungYoung Heo on 2018. 1. 21..
//  Copyright © 2018년 KyungYoung Heo. All rights reserved.
//
#include <iostream>
using namespace std;
int main(){
    int t, x=10;
    for(int i=1;i<10000;i++){
        if(i==10 || i==100 || i==1000)
            x*=10;
        t = i*i;
        if(t%x == i)
            cout << i << endl;
    }
    return 0;
}

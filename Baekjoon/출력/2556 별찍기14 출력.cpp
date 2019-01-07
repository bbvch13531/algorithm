//
//  2556 별찍기14 출력.cpp
//  Algorithm
//
//  Created by KyungYoung Heo on 2018. 4. 2..
//  Copyright © 2018년 KyungYoung Heo. All rights reserved.
//

#include <cstdio>
#include <iostream>
using namespace std;

int main(void){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

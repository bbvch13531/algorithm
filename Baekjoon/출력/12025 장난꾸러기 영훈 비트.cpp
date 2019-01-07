//
//  12025 장난꾸러기 영훈 전탐색.cpp
//  Algorithm
//
//  Created by KyungYoung Heo on 2018. 3. 19..
//  Copyright © 2018년 KyungYoung Heo. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,char> > input;

int main(void){
   unsigned long long k,bit;
    char ch;
    string buf;
    
    cin>>buf>>k;
    bit=k-1;
    for(int i=0;i<buf.length();i++){
        ch=buf[i];
        if(ch=='1'||ch=='2'||ch=='6'||ch=='7')
            input.emplace_back(i,ch);
    }
    if(k>((unsigned long long)1<<input.size()) || k<1){
        printf("-1");
        return 0;
    }
    reverse(input.begin(),input.end());
    for(int i=0;i<input.size();i++){
        if(bit%2==0){   //1과 2로 채워야 한다. 0은 1과 2를 의미
            if(input[i].second=='6') input[i].second='1';
            else if(input[i].second=='7') input[i].second='2';
        }
        else{   //6과 7로 채워야 한다. 1은 6과 7을 의미
            if(input[i].second=='1') input[i].second='6';
            else if(input[i].second=='2') input[i].second='7';
        }
        bit/=2;
    }
    reverse(input.begin(),input.end());
//    for( auto a : input) {
//        printf("%c",a.second);
//    }
//    cout<<endl<<endl;
    //출력
    int idx=0;
    for(int i=0;i<buf.size();i++){
        if(input[idx].first==i){
//            printf("idx: %d \n",idx);
            printf("%c",input[idx].second);
            idx++;
        }
        else{
            printf("%c",buf[i]);
        }
    }
    return 0;
}


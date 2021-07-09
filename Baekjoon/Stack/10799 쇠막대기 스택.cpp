//
//  10799 쇠막대기 스택.cpp
//  Algorithm
//
//  Created by KyungYoung Heo on 2018. 3. 8..
//  Copyright © 2018년 KyungYoung Heo. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

stack <char> stk;
string input;

int countStick();

int main(void){
    
    cin>>input;
    cout<<countStick();
    return 0;
}

int countStick(){
    int cnt=0,res=0;
    
    for(int i=0; i<input.length();i++){
        char ch=input[i];
        
        if(ch=='(') {
            stk.push(ch);
            cnt++;
        }
        else{
            if(stk.top()=='('){ // 레이저 닫는 괄호일 때
                stk.push(ch);
//                stk.pop();
                cnt--;
                res+=cnt;
//                printf("i= %d cnt= %d res= %d\n",i,cnt,res);
            }
            else{   // 막대 닫는 괄호일 때
                cnt--;
                res++;
            }
        }
    }
    
    return res;
}

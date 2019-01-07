//
//  xPlusYCardProblem.cpp
//  Algorithm
//
//  Created by KyungYoung Heo on 2018. 7. 28..
//  Copyright © 2018년 KyungYoung Heo. All rights reserved.
//

#include <iostream>

using namespace std;

string process(string str);
bool isFinished(string str);
void flipCard(string& str, int index);

int main(void){
    string input,res;
    
    cin>>input;
    
    res = process(input);
    cout<<res<<endl;
    
    return 0;
}

string process(string str){
    int len = str.length();
    for(int i = 0; i<len; i++){
        for(int j=i; j<len-1; j++){
            if(str[j]=='0') continue;
            
            else{
                flipCard(str,j);
                flipCard(str,j+1);
            }
            cout<<str<<endl;
        }
    }
    if(str[len-1] == '1'){
        str[len-1] = '0';
        cout<<str<<endl;
    }
    return str;
}

bool isFinished(string str){
    for(int i=0; i<str.length() - 1; i++){
        if(str[i]=='1') return false;
    }
    return true;
}

void flipCard(string& strp, int index){
    if(strp[index] == '1') strp[index]='0';
    else strp[index]='1';
    
    return;
}

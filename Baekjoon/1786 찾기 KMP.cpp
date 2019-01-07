//
//  1786 찾기 KMP.cpp
//  Algorithm
//
//  Created by KyungYoung Heo on 2018. 3. 30..
//  Copyright © 2018년 KyungYoung Heo. All rights reserved.
//
#define MAX 1000000
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

void getPi(string);
void kmp(string,string);

vector<int> pi(MAX,0),res;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int ansSize;
    char buf[MAX],ch;
    string T,P;
//    scanf("%[^\n]\n",buf);
//    T=buf;
//
//    scanf("%[^\n]",buf);
//    P=buf;
    getline(cin,T);
    getline(cin,P);

//    cout<<T<<endl<<P<<endl;
    //getc gets 는 c++11이후 버전에서 deprecate되었다.
    kmp(T,P);
    
    ansSize=res.size();
    cout<<ansSize<<endl;
    for(int i=0;i<ansSize;i++) printf("%d ",res[i]+1);
    return 0;
}
void getPi(string s){
    int n=(int)s.size(),j=0;
    fill(pi.begin(),pi.end(),0);
    for(int i=1;i<n;i++){
        //substring
        while(j>0 && s[i]!=s[j]){
            j = pi[j-1];
        }
        if(s[i]==s[j]){
            j++;
            pi[i]=j;
        }
    }
    //ABC ABCDABD ABCDABCDABDE
    //ABCDABD
//    for(int i=0;i<s.size();i++){
//        cout<<pi[i]+1<<" ";
//    }
}
void kmp(string T,string P){
    getPi(P);
    int n=(int)T.size(),m=(int)P.size(),j=0;
    for(int i=0;i<n;i++){
        while (j>0 && T[i]!=P[j]) {
            j=pi[j-1];
        }
        if(T[i]==P[j]){
            if(j==m-1){
                res.push_back(i-j);
                j=pi[j];
            }
            else j++;
        }
    }
}

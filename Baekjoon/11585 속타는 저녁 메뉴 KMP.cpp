//
//  11585 속타는 저녁 메뉴 KMP.cpp
//  Algorithm
//
//  Created by KyungYoung Heo on 2018. 3. 31..
//  Copyright © 2018년 KyungYoung Heo. All rights reserved.
//
#define MAX_N 1000010
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <int> pi(MAX_N,0),ans;
int cnt=0;
void getPi(string);
void kmp(string,string);
int gcd(int,int);
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int N;
    char ch;
    string T,P;
    
    cin>>N;
    T.resize(N);
    P.resize(N);
    for(int j=0;j<2;j++){
        for(int i=0;i<N;i++){
            scanf(" %c",&ch);
            if(j==0)  T[i]=ch;
            else  P[i]=ch;
        }
    }
//    cout<<T<<endl<<P<<endl;
//    P+=P;
//    P.erase(N-1);
    getPi(T);
    kmp(P,T);
    if(cnt==0){
        P+=P;
        P.erase(N-1);
        kmp(P, T);
    }
    cout<<"1/"<<N/gcd(cnt,N)<<endl;
    return 0;
}

void getPi(string S){
    int n=(int)sizeof(S),j=0;
    for(int i=1;i<n;i++){
        while(j>0 && S[i]!=S[j])  j=pi[j-1];
        if(S[i]==S[j]){
            j++;
            pi[i]=j;
        }
    }
//    for(int i=0;i<n;i++) printf("%d ",pi[i]);
//    cout<<endl;
}
void kmp(string S,string P){
//    getPi(P);
    int n=(int)S.size(),m=(int)P.size(),j=0;
    for(int i=0;i<n;i++){
        while(j>0 && S[i]!=P[j])  j=pi[j-1];
        if(S[i]==P[j]){
            if(j==m-1){
                cnt++;
                j=pi[j];
            }
            else j++;
        }
    }
}
int gcd(int a,int b){
    int tmp;
    if(a<b){
        tmp=b;
        b=a;
        a=tmp;
    }
    while(b!=0){
        a%=b;
        tmp=b;
        b=a;
        a=tmp;
    }
    return a;
}

//
//  4195 친구 네트워크.cpp
//  Baekjoon
//
//  Created by KyungYoung Heo on 2017. 9. 29..
//  Copyright © 2017년 KyungYoung Heo. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <cstdio>
using namespace std;


int parent[2000001];
int counter[2000001];

int find(int k){
    if(k == parent[k]) return k;
    return parent[k] = find(parent[k]);
}

int merge(int p, int q){
    p = find(p);
    q = find(q);
    if(p != q){
        parent[q] = p;
        counter[p] += counter[q];
        counter[q] = 1;
    }
    return counter[p];
}

int main(){
    int T,N,num=1;
    char s[35],p[35];
    
    scanf("%d",&T);
    while(T--){
        
        scanf("%d",&N);
        for(int i=1; i<=2*N; ++i){
            parent[i] = i;
            counter[i] = 1;
        }
        
        map<string, int> index;
        
        for(int i=0; i<N; ++i){
            
            scanf("%s %s",s,p);
            if(index.count(s)==0) index[s] = num++;
            
            if(index.count(p)==0) index[p] = num++;
            
            printf("%d\n",merge(index[s],index[p]));
        }
    }
    return 0;
}

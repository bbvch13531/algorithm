#define ll long long
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>


using namespace std;
int log(ll);
int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    ll N,two=1,num=1,nth,order,expNum;
    vector <ll> twos,ans;
    cin>>N;
    // N+=1;
    
    while(two<N*4){
        twos.push_back(two);
        two*=2;
    }
    
    for(int i=0; i<twos.size(); i++){
        // cout<<twos[i]<<" ";
        if(twos[i] > N+1){
            if(N==1){
                num = 2;
                nth = 0;
                break;
            }
            else{
                num = twos[i-1];
                nth = i-1;
                break;
            }
        }
    }
    num-=1; //2^x - 1 꼴인 수
    order = N-num; // 기준에서 N이 몇번째인지
    expNum = log(order) ;
    if(order == 0)expNum = 0;
    // printf("num = %d, order  = %d, expNum = %d, nth = %d\n",num,order,expNum,nth);
    for(int i=0; i<nth-expNum; i++){
        cout<<"4";
    }
    if(N == 1)
        ans.push_back(4);
    else{
        while(1){
            if(order == 0) break;
            if(order%2 == 1){
                ans.push_back(7);
            }
            else{
                ans.push_back(4);
            }
            
            order /= 2;
            
        }
    }
    // cout<<"\n";
    for(auto rit = ans.rbegin(); rit!=ans.rend(); rit++){
        cout<<(*rit);
    }
    return 0;
}

int log(ll n){
    int cnt = 0;
    ll num = 1;

    while(1){
        
        if(num>n){
            return cnt;
        }
        num *= 2;
        cnt++;
    }
}
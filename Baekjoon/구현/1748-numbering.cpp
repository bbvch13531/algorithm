/*
https://www.acmicpc.net/problem/1748
N까지의 수를 이어서 썼을 떄 문자열의 길이를 출력하는 문제
*/

#include <iostream>
#include <cmath>

#define ll long long 
using namespace std;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // 1<= N <= 100'000'000
    int flag;
    ll start=1, end=10;
    ll len=1, ans=0;

    cin >> N;

    while(1){
        flag = 0;
        for(ll i=start; i<end; i++){
            if(i>N){
                flag = 1;
                break;
            }
            ans += len;
        }    
        if(flag==1)
            break;
        start *= 10;
        end *= 10;

        len++;
    }

    cout<<ans;

}
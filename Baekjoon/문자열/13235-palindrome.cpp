// https://www.acmicpc.net/problem/13235
// 주어진 문자열이 팰린드롬인지 판별하는 문제
#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string in;
    cin >> in;
    int len = in.length();
    int flag = 1;

    for(int i=0; i<len/2+1; i++){
        if(in[i] != in[len-i-1]){
            flag = 0;
            break;
        }
    }
    if(flag == 1){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}
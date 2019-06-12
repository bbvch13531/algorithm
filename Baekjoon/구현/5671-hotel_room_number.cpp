#include <iostream>
#include <string>

using namespace std;
int countNum(int num);
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    int cnt=0;
    string in;
    while(1){
        N = M = -1;
        cnt = 0;
        cin >> N >> M;
        if(N==-1 && M==-1)
            break;
        // cout<<N<<" "<<M<<"\n";
        for(int i=N; i<=M; i++){
            if(countNum(i)){
                cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}

int countNum(int num){
    char str[5];
    int cnt=0;

    // cout<<num<<" "<<str<<"\n";
    while(num > 0){
        str[cnt] = num % 10 + '0';
        num /= 10;
        cnt++;
    }
    // str.reserve();
    // reverse(str.begin(), str.end());
    // cout<<str<<"\n";
    // int len = str.length();
    for(int i=0; i<cnt; i++){
        for(int j=i+1; j<cnt; j++){
            // cout<<i<<" "<<j<<"\n";
            // cout<<str[i]<<" "<<str[j]<<"\n";
            if(str[i] == str[j])
                return 0;
        }
    }
    return 1;
}
#include <iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int coins[6] = {500, 100, 50, 10, 5, 1};
    int ans=0, num;

    cin>> N;
    N = 1000 - N;
    for(int i=0; i<6; i++){
        if(N>=coins[i]){
            num = N/coins[i];
            ans += num;
            N -= num*coins[i];
            // cout << num<< " " << ans<< " "<<N<<"\n";
        }
    }
    cout<< ans;
    return 0;
}
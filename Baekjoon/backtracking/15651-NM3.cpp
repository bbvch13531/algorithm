#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
bool check[10];
int arr[10];
int N,M;

void dfs(int cnt){
    if(cnt == M){
        for(int i=0; i<cnt; i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i=1; i<=N; i++){
        if(!check[i]){
            // check[i] = true;
            arr[cnt] = i;
            dfs(cnt+1);
            // check[i] = false;
            // dfs(i,cnt);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    dfs(0);

    return 0;
}
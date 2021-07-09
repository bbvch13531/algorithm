#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
bool check[10];
vector<int> arr;
int ans[10];
int N,M;

void dfs(int num,int cnt){
    if(cnt == M){
        for(int i=0; i<cnt; i++){
            cout << arr[ans[i]] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i=0; i<N; i++){
        if(!check[i]){
            // check[i] = true;
            ans[cnt] = i;
            dfs(i, cnt+1);
            // check[i] = false;
            // dfs(i,cnt);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tmp;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    dfs(0, 0);

    return 0;
}
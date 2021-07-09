#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> arr;
bool visit[30];
int ans[30];
int N, S;
int subset_cnt;

void dfs(int num, int cnt, int limit){

    if(cnt == limit){
        int sum=0;
        for(int i=0; i<cnt; i++){
            // cout << ans[i]<< ' ';
            sum += ans[i];
        }
        if(sum == S)
            subset_cnt++;
        // cout <<'\n';
        return;
    }

    for(int i=num; i<N; i++){
        if(!visit[i]){
            visit[i] = true;
            ans[cnt] = arr[i]; 
            dfs(i, cnt+1, limit);
            visit[i] = false;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tmp;
    
    cin >> N >> S;
    for(int i=0; i<N; i++){
        cin >> tmp;
        arr.push_back(tmp);
    }

    for(int i=1; i<=N; i++){
        dfs(0, 0, i);
    }
    // cout <<'\n';
    cout << subset_cnt;
    return 0;
}
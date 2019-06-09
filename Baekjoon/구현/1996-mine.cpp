#include <iostream>
#include <string>

using namespace std;
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0 ,-1 ,-1};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, ans[1010][1010] = {0,};
    string map[1010];
    cin>>N;

    for(int i=0; i<N; i++){
        cin>>map[i];
        
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            char ch = map[i][j];

            if(ch != '.'){
                int num = ch - '0';

                for(int m=0; m<8; m++){
                    int nx = i+dx[m];
                    int ny = j+dy[m];
                    
                    if(0 <= nx && nx < N && 0 <= ny && ny < N){
                        if(ans[nx][ny] + num > 9)
                            ans[nx][ny] = 11;
                        else
                            ans[nx][ny] += num;
                    }
                }
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j] != '.')
                cout<<"*";
            else if(ans[i][j] == 11)
                cout<<"M";
            else
                cout<<ans[i][j];
        }
        cout<<"\n";
    }
    return 0;
}
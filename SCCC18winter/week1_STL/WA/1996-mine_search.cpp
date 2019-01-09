#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

void aroundCnt(int,int);

int N;
string map[1100],ans[1100];

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;

    for(int i=0; i<N; i++){
        cin>>map[i];
    }
  
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j]=='.'){
                aroundCnt(i,j);
            }
            else{
                ans[i][j] = '*';
         ''   }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<ans[i][j];
        }
        cout<<"\n";
    }
    return 0;
}

void aroundCnt(int r,int c){
    int x,y,mineCnt=0;
    
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){

            x = r+i;
            y = c+j;

            if((0<=x && x<N) && (0<=y && y<N) && !(x==r && y==c)){
                // cout<<"x,y = "<<x<<" "<<y<<"\n";
                if(map[x][y] != '.'){                    
                    // cout<<"map[x][y] = "<<map[x][y]<<x<<" "<<y<<"\n";
                    mineCnt+= (map[x][y] - '0');
                }
            }
        }
    }
    // cout<<"mineCnt = "<<mineCnt<<"\n";
    if(mineCnt>=10) ans[r][c] = 'M';
    else ans[r][c] = mineCnt+'0';
}

/*
5
1...1
..3.2
....3
.4..4
2..9.


8
1...1.4.
..3.2..3
....3153
.4..4..1
2..9....
2..9....
....3153
.4..4..1
*/
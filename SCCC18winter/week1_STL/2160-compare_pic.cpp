#include <iostream>
#include <string>

using namespace std;

int comparePic(int,int);

int diffCnt[60][60];
string pics[60][5];

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int min=987654321,minA,minB;

    cin>>N;


    for(int i=0; i<N; i++){
        for(int j=0; j<5; j++){
            cin>>pics[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            diffCnt[i][j] = comparePic(i,j);
            // cout<<i<<" "<<j<<" "<<diffCnt[i][j]<<"\n";
            if(diffCnt[i][j]<min){
                // cout<<diffCnt[i][j]<<" "<<min<<"\n";
                minA = i;
                minB = j;
                min = diffCnt[i][j];
            }
        }
    }
    cout<<minA+1<<" "<<minB+1;
    return 0;
}
int comparePic(int a,int b){
    int cnt = 0;

    for(int i=0; i<5; i++){
        for(int j=0; j<7; j++){
            if(pics[a][i][j] != pics[b][i][j]){
                cnt++;
            }
        }
    }
    return cnt;
}
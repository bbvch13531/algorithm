#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
    int arr[350][350]={0,},sum[350][350]={0,};
    int N, M, K;
    int sx,sy,ex,ey;

    scanf("%d %d",&N, &M);

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d",&arr[i][j]);
            if(i==0){
                if(j==0){
                    sum[i][j] = arr[i][j];
                }
                else
                    sum[i][j] = sum[i][j-1] + arr[i][j];
            }
            else if(j == 0){
                if(i != 0)
                    sum[i][j] = sum[i-1][M-1] + arr[i][j];
            }
            else{
                sum[i][j] = sum[i-1][j] + arr[i][j];
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
    // scanf("%d",&K);
    
    // int ans=0;

    // for(int i=0; i<K; i++){
    //     scanf("%d %d %d %d",&sx,&sy,&ex,&ey);

    // }

}
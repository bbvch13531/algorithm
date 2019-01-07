#include <iostream>
#include <climits>

using namespace std;

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    int N,size[600]={0,},dp[510][510]={0,};
    int cost;
    cin>>N;

    for(int i=0; i<N; i++){
        cin>>size[i];
        cin>>size[i+1];
    }

    // for(int i=1; i<=N; i++){
    //     dp[i][i] = 0;
    //     for(int j=i; j<=N; j++){
    //             dp[i][j] = 987654321;
    //         for(int k=i; k<j-1; k++){ 
    //             cost = dp[i][k]+ dp[k+1][j] + size[i-1]*size[k]*size[j];
                
    //             if(cost<dp[i][j]) dp[i][j] = cost;

    //         }
    //     }
    // }
  
    for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(i==j) dp[i][i]=0;
			else dp[i][j] = INT_MAX;
		}
	}

    
    for(int diagonal = 1; diagonal<=N-1; diagonal++){
       for(int i=1; i<=N - diagonal; i++){
            int j=i+diagonal;
            
            for(int k=i; k<=j-1; k++){
                int cost = dp[i][k] + dp[k+1][j] + size[i-1] * size[k] * size[j];
                dp[i][j] = min(cost,dp[i][j]);
            }
       }       
    }

    cout<<dp[1][N];

    return 0;
}
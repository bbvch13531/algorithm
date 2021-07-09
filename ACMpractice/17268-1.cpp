#include<bits/stdc++.h>
using namespace std;
int n;
long long dp[10005];
int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   dp[0] = 0;
   dp[2] = 1;
   cin >> n;
   for(int i=4; i<=n; ++i)
   {
       for(int j=2; j<=i; j+=2)
       {
           long long sum = 1;
           if(dp[j-2] != 0){
               sum *= dp[j-2];
//							 cout<<"dp["<<j-2<<"] = "<<dp[j-2]<<"\n";
					 }
           if(dp[i-j] != 0){
               sum *= dp[i-j];
	//						 cout<<"dp["<<i-j<<"] = "<<dp[i-j]<<"\n";
					 }
           sum %= 987654321;
		//			cout <<"sum = " << sum <<"\n";
           dp[i] += sum;
           dp[i] %= 987654321;
       }
   }
   cout << dp[n];
   return 0;
}

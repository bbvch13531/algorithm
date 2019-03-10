#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

queue <int> que;

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M,jump,out;

    cin>>N>>M;
    for(int i=1; i<=N; i++){
        que.push(i);
    }
    printf("<");
    for(int i=0; i<N; i++){
       for(int j=0; j<M-1; j++){
           jump = que.front();
           if(!que.empty()) que.pop();
           que.push(jump);
       }
       out = que.front();
       if(i==0) printf("%d",out);
       else printf(", %d",out);
       que.pop();
    }
    printf(">");
    return 0;
}
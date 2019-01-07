#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main(int argc, char** argv){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    priority_queue <int, vector<int>, greater<int> > pque;
    int N,buf;

    // cin>>N;
    scanf("%d",&N);
    
    for(int i=0; i<N; i++){
        // cin>>buf;
        scanf("%d",&buf);
        if(buf == 0){
            if(pque.empty())
                // cout<<"0"<<endl;
                printf("0\n");
            else{
                // cout<<pque.top()<<endl;
                printf("%d\n",pque.top());
                pque.pop();
            }
        }
        else{
            pque.push(buf);
        }
    }
    return 0;
}
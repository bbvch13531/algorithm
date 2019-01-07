#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char** argv){
    int N,buf;
    priority_queue <int> pq;

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>buf;
        pq.push(buf);        
    }

    for(int i=0; i<N; i++){
        cout<<pq.top()<<"\n";
        pq.pop();
    }

    return 0;
}
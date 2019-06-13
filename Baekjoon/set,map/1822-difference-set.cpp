#include <iostream>
#include <set>
#include <map>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<int> s;
    int N, M;
    int buf;
    cin>> N >> M;

    for(int i=0; i<N; i++){
        cin>>buf;
        s.insert(buf);
    }
    for(int i=0; i<M; i++){
        cin>>buf;
        s.erase(buf);
    }
    cout<<s.size()<<"\n";
    if(s.size() != 0){
        for(auto it:s){
            cout<<it<<" ";
        }
    }
    return 0;
}
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main(int argc, char** argv){
    map <string,bool> neverHeard;
    set <string> neverHeardSeen;
    int N,M;
    string buf;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin>>buf;
        neverHeard[buf] = true;
    }
    for(int i=0; i<M; i++){
        cin>>buf;
        if(neverHeard[buf])
            neverHeardSeen.insert(buf);
    }
    cout<<neverHeardSeen.size()<<"\n";
    for(auto it= neverHeardSeen.begin(); it!=neverHeardSeen.end(); it++){
        cout<<*it<<"\n";
    }

    return 0;
}
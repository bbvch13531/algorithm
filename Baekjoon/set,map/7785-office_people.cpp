#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<string> s;
    int N;
    string name, cmd;
    cin>> N;

    for(int i=0; i<N; i++){
        cin >> name >> cmd;
        if(cmd == "enter"){
            s.insert(name);
        }
        else if(cmd == "leave"){
            s.erase(name);
        }
    }
    for(auto it = s.rbegin(); it != s.rend(); it++){
        cout<<*it<<"\n";
    }
    return 0;
}
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <tuple>

#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"

using namespace std;

list<int> l;
list<int>::iterator its[1000010];
list<int>::iterator cursor;
list<pair<int, int> > erased;

string solution(int n, int k, vector<string> cmd) {
    string ans = string(n, 'X');
    for(int i=0; i<=n; i++){
        l.push_back(i);
    }

    auto it = l.begin();
    for(int i=0; i<=n; i++){
        its[i] = it;
        it++;
    }
    cursor = its[k];
    for(auto c: cmd) {
        if(c[0]=='U') {
            int num = stoi(c.substr(2, 100));
            while(num--) cursor--;
        } else if(c[0]=='D') {
            int num = stoi(c.substr(2, 100));
            while(num--) cursor++;
        } else if(c[0]=='C') {
            erased.push_back({*cursor, *(next(cursor))});
            cursor = l.erase(cursor);
            if(*cursor == n) cursor--;
        } else { // Z
            int cur, next;
            tie(cur, next) = erased.back();
            erased.pop_back();

            its[cur] = l.insert(its[next], cur);
        }
    }

    for(auto i: l){
        if(i != n) ans[i] = 'O';
    }
    return ans;
}

int main(){
    int N, K, lines;
    string tmp;
    vector<string> cmd;

    cin >> N >> K >> lines;
    cin.ignore();

    for(int i=0; i<lines; i++){
        getline(cin, tmp);
        cmd.push_back(tmp);
    }

    string ans = solution(N, K, cmd);
    cout << ans <<"\n";
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <fstream>
#include <list>
#include <tuple>

#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"
#define INF 0x7f7f7f7f

using namespace std;

list <int> l;
list <int>::iterator its[1000005];
list <int>::iterator cursor;
vector<pair<int, int> > erased;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";

    for(int i=0; i<n; i++){
        l.push_back(i);
    }
    l.push_back(n);
    auto it = l.begin();
    for(int i=0; i<n+1; i++){
        its[i] = it;
        it++;
    }
    cursor = its[k];

    for(auto s: cmd){
        for(auto x: l){
            cout << x << " ";
        }
        cout<< "-------------------" << *cursor << "\n";
        if(s[0] == 'U'){
            int num = stoi(s.substr(2,100));
            while(num--) cursor--;

        } else if(s[0] == 'D'){
            int num = stoi(s.substr(2,100));
            while(num--) cursor++;

        } else if(s[0] == 'C'){
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
    string status(n, 'X');
    for(auto x: l){
        if(x!=n) status[x] = 'O';
    }
    return status;
}
int main(void){
    int N, K, cmdLen;
    string tmp;
    vector<string> cmd;
    freopen("input-editTable.txt", "r", stdin);
    cin >> N >> K >> cmdLen;
    cin.ignore();
    for(int i=0; i<cmdLen; i++){
        // cin >> tmp;
        getline(cin, tmp);
        cmd.push_back(tmp);
    }
    string ans = solution(N, K, cmd);
    cout << ans;
    return 0;
}
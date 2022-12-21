#include <bits/stdc++.h>
#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"
#define INF 0x33ffffff
#define ll long long
#define pii pair<int, int>
using namespace std;

list<char> llist;
int main(){
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    // freopen("1406input.txt", "r", stdin);
    vector <string> cmd;
    string initStr, tmp;
    int M;

    cin >> initStr;
    cin >> M;
    
    cin.ignore();
    for(int i=0; i<M; i++){
        getline(cin, tmp);
        cmd.push_back(tmp);
    }

    for(char ch: initStr){
        llist.push_back(ch);
    }
    auto cursor = llist.end();

    for(int i=0; i<cmd.size(); i++){
        string c = cmd[i];
        if(c[0] == 'L'){
            if(cursor != llist.begin())
                cursor--;
        } else if(c[0] == 'D'){
            if(cursor != llist.end())
                cursor++;
        } else if(c[0] == 'B'){
           if(cursor != llist.begin()){
               cursor--;
               cursor = llist.erase(cursor);
           }
        } else {    // 'P'
            char ch = c[2];
            llist.insert(cursor, ch);

        }
    }
    for(char ch: llist) cout << ch;
    return 0;
}
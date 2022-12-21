#include <bits/stdc++.h>
#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"

using namespace std;


int main(void){
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    set<string> s;
    vector<string> arr;
    string tmp;
    int N, stdLen, answer;
    bool flag;
    freopen("1235-input.txt", "r", stdin);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> tmp;
        arr.push_back(tmp);
    }
    stdLen = tmp.length();

    for(int i=1; i<=stdLen; i++){
        s.clear();
        flag = true;
        for(int j=0; j<N; j++){
            string num = arr[j];
            string stdNum = num.substr(num.length()-i, i);
            // debug2(num, stdNum);
            if(s.find(stdNum) == s.end()){  // not found in set
                s.insert(stdNum);
            } else {    // duplicated
                flag = false;
                break;
            }
        }
        if(flag){
            // debug1(i);
            answer = i;
            break;
        }
        // cout<<"\n";
    }
    cout << answer;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

string str;
vector<int> alpha (26, 0);

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> str;
    
    string left="", answer="";
    char mid;

    for(char ch: str){
        int idx = ch - 'A';
        alpha[idx]++;
    }
    int cnt=0;

    for(int i=0; i<26; i++){
        if(alpha[i] > 1) {
            for(int j=0; j<alpha[i] / 2; j++)
                left.push_back('A' + i);
        }
        if(alpha[i] % 2 == 1) {
            mid = 'A' + i;
            cnt++;
        }
    }
    string right (left.rbegin(), left.rend());

    if(cnt == 0) {    
        cout << left << right;
    } else if(cnt == 1){
        cout << left << mid << right;
    } else {
        cout << "I'm Sorry Hansoo";
    }
    return 0;
}

/*
AABB
ABBA

AAABB : ABABA < BAAAB

AAAAB
*/
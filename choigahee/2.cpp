#include <bits/stdc++.h>
#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"
const int INF = 0x0f7f7f7f;

using namespace std;
vector<string> blogs;
unordered_set<string> keywordSet;

void parseStr1(const string& str, vector<string>&vec, string& delimiter){
    string::size_type Fpos = str.find_first_not_of(delimiter, 0);
    string::size_type Lpos = str.find_first_of(delimiter, Fpos);

    while(string::npos != Fpos || string::npos != Lpos) {
        vec.push_back(str.substr(Fpos, Lpos - Fpos));
        Fpos = str.find_first_not_of(delimiter, Lpos);
        Lpos = str.find_first_of(delimiter, Fpos);
    }
}

vector<string> parseStr(string str){
    vector<string> vec;
    // parse string by ','
    int s=0;
    int e = str.find(',');
    string sub;
    while(e != -1){
        sub = str.substr(s,e-s);
        s = e+1;
        e = str.find(',', e+1);
        vec.push_back(sub);
    }
    sub = str.substr(s,str.length() - s);
    vec.push_back(sub);

    return vec;
}

int main(){
    // freopen("2input.txt","r",stdin);
    int N ,M;

    scanf("%d %d", &N, &M);
    getchar();
    char buf[50];
    for(int i=0; i<N; i++){
        cin.getline(buf, sizeof(buf));
        string tmp = string(buf);
        keywordSet.insert(string(buf));
    }
    
    for(int i=0; i<M; i++){
        cin.getline(buf, sizeof(buf));
        string tmp = string(buf);
        blogs.push_back(tmp);
    }

    for(string k: blogs){
        // vector<string> ss = parseStr(k);
        vector<string> ss;
        string del = ",";
        parseStr1(k, ss, del);
        for(string s: ss){
            keywordSet.erase(s);
        }
        printf("%d\n", keywordSet.size());
    }
    return 0;
}
#include <bits/stdc++.h>
#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"
const int INF = 0x0f7f7f7f;

using namespace std;
vector<string> filenames;
unordered_set<string> ss;

bool cmp(const string a, const string b){
    int dota = a.find('.');
    int dotb = b.find('.');
    string afile = a.substr(0,dota);
    string bfile = b.substr(0,dotb);
    string aext = a.substr(dota+1, a.length()-dota);
    string bext = b.substr(dotb+1, b.length()-dotb);

    if(afile != bfile){
        return afile < bfile;
    } else {
        auto aidx = ss.find(aext);
        auto bidx = ss.find(bext);

        // if(aidx == ss.end()){
        //     return false;
        // } else if(bidx == ss.end()){
        //     return true;
        // } else {
        //     return aext < bext;
        // }
        if(aidx != ss.end() && bidx != ss.end()){
            return aext < bext;
        } else if(aidx == ss.end() && bidx != ss.end()){ // b가 먼저
            return false;
        } else if(aidx != ss.end() && bidx == ss.end()){ // a가 먼저
            return true;
        } else {
            return aext < bext;
        }
    }
}


int main(){
    // cin.tie(NULL); ios_base::sync_with_stdio(false);
    freopen("1input.txt","r",stdin);
    int N, M;
    // cin >> N >> M;
    scanf("%d %d", &N, &M);
    char tmp[20];

    for(int i=0; i<N; i++){
        // cin >> tmp;
        scanf("%s", tmp);
        string s = string(tmp);
        filenames.push_back(s);
    }
    for(int i=0; i<M; i++){
        // cin >> tmp;
        scanf("%s", tmp);
        string s = string(tmp);
        ss.insert(s);
    }
    sort(filenames.begin(), filenames.end(), cmp);
    for(string s:filenames){
        printf("%s\n", s.c_str());
    }
    return 0;
}
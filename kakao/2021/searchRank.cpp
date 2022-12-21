#include <bits/stdc++.h>
#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"
const int INF = 0x033ff7f7f;
using namespace std;

vector<string> info, query;
vector<int> p[3][2][2][2];

int morethan(vector<int> vec, int score){
    auto lower = lower_bound(vec.begin(), vec.end(), score);
    // for(int i: vec)
    //     cout<< i << " ";
    // cout<<"\n" << score << " morethan is " << vec.end() - lower << "\n";
    return vec.end() - lower;
}

int retStr(string str){
    if(str == "java") return 0;
    else if(str == "python") return 1;
    else if(str == "cpp") return 2;

    else if(str == "backend") return 0;
    else if(str == "frontend") return 1;

    else if(str == "junior") return 0;
    else if(str == "senior") return 1;

    else if(str == "chicken") return 0;
    else if(str == "pizza") return 1;
    else if(str == "-") return 3;
}
vector<int> solution(){
    vector<int> answer;

    int dataIdx[4];
    
    for(string str: info){
        string tmp;
        int e;
        for(int i=0; i<4; i++){
            e = str.find(' ');
        
            tmp = str.substr(0,e);
            // debug1(tmp);
            int num = retStr(tmp);

            dataIdx[i] = num;

            str = str.substr(e+1, str.length()-e);
            // debug1(str);
        }
        int score = stoi(str);
        p[dataIdx[0]][dataIdx[1]][dataIdx[2]][dataIdx[3]].push_back(score);
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<2; k++){
                for(int l=0; l<2; l++){
                    sort(p[i][j][k][l].begin(), p[i][j][k][l].end());
                }
            }
        }
    }

    vector<int> qnum;
    int qIdx[4];
    for(string q: query){
        qnum.clear();
        int e=0;
        string tmp;
        for(int i=0; i<3; i++){
            e = q.find(" and ");
            tmp = q.substr(0, e);
            int num = retStr(tmp);
            qIdx[i] = num;
            q = q.substr(e + 5, q.length() - e);
            // debug1(q);
        }
        e = q.find(' ');
        tmp = q.substr(0, e);
        qIdx[3] = retStr(tmp);
        q = q.substr(e+1, q.length() - e);

        int score = stoi(q);
        // debug1(score);
        int as,ae,bs,be,cs,ce,ds,de;
        if(qIdx[0] != 3){
            as=ae=qIdx[0];
        }else {
            as=0,ae=2;
        }
        if(qIdx[1] != 3){
            bs=be=qIdx[1];
        }else {
            bs=0, be=1;
        }
        if(qIdx[2] != 3){
            cs=ce=qIdx[2];
        }else {
            cs=0, ce=1;
        }
        if(qIdx[3] != 3){
            ds=de=qIdx[3];
        }else {
            ds=0, de=1;
        }
        int qCnt=0;
        for(int i=as; i<=ae; i++){
            for(int j=bs; j<=be; j++){
                for(int k=cs; k<=ce; k++){
                    for(int l=ds; l<=de; l++){
                        // debug1(p[i][j][k][l]);
                        // cout << "p[i][j][k][l]" << " = " << p[i][j][k][l] << "\n"
                        // for(int nn:p[i][j][k][l])
                        //     cout<< nn <<" ";
                        int res = morethan(p[i][j][k][l], score);
                        qCnt+=res; 
                    }
                }
            }
        }
        debug1(qCnt);
    }
    return answer;
}

int main(){
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N, M;
    string line;
    freopen("input-searchRank.txt", "r", stdin);

    cin >> N >> M;
    cin.ignore();
    for(int i=0; i<N; i++){
        getline(cin, line);
        info.push_back(line);
    }
    for(int i=0; i<M; i++){
        getline(cin, line);
        query.push_back(line);
    }
    vector<int> ans = solution();
    return 0;
}
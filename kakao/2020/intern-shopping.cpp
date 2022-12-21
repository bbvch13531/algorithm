#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>

#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"
const int INF = 0x7f7f7f7f;
using namespace std;

unordered_map <string, int> m;
vector <int> numbers;

bool check(int l, int r){
    for(auto x: m){
        if(x.second == 0){
            return false;
        }
    }
    return true;
}

int minRange = INF;

vector<int> solution(vector<string> gems) {
    vector<int> answer (2,0);
    int l=0, r=0;
    int len = gems.size();
    int cnt=0;

    for(string gem: gems){
        if(m.find(gem) == m.end()){  
            m[gem] = 0;
        }
    }

    // m[gems[0]] = 1;
    while(r < len && l < len) {
        while(r < len && !check(l, r)){
            m[gems[r]]++;   // r번째 gem 개수를 증가시킴

            r++;
            if(r == len) break;
        }

        while(l < len && check(l, r)){
             // l을 오른쪽으로 이동하기 위해
            m[gems[l]]--;

            l++;
        }
        if(l == len) break;
        if(r-l < minRange){
            minRange = r-l;
            answer[0] = l;
            answer[1] = r;
        }
    }
    return answer;
}

int main(){
    int N;
    vector<string> gems;
    string tmp;

    freopen("input-shopping.txt", "r", stdin);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> tmp;
        gems.push_back(tmp);
    }

    vector<int> ans = solution(gems);
    
    return 0;
}
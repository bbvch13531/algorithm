#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <stack>

#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"

using namespace std;
string arr[10] = {"zero",
                    "one",
                    "two",
                    "three",
                    "four",
                    "five",
                    "six",
                    "seven",
                    "eight",
                    "nine"};

int solution(string s) {
    int answer = 0;
    int len = s.length();
    bool flag = true;

    while(flag){
        flag = false;
        for(int j=0; j<10; j++){
            int idx=0;
            char ch = '0';
            idx = s.find(arr[j]);
            if(idx != -1){
                flag = true;
                s.erase(idx, arr[j].length());
                string replaced = string(1, ch+j);
                s.insert(idx, replaced);
            }
        }
    }
    answer = stoi(s);
    return answer;
}

int main(){
    string s;
    cin >> s;
    int ans = solution(s);
    cout << ans << "\n";
}
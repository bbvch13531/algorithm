#include <bits/stdc++.h>
#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"
const int INF = 0x0f7f7f7f;
using namespace std;


int cntMatch(string line1, string line2){

    int len1 = line1.length();
    int len2 = line2.length();
    int transLen;
    int cnt=0;

    for(int idx=0; transLen <= len1; idx++){
        transLen = len2 + idx * (len2 - 1);
        debug2(idx, transLen);

        for(int i=0; i<len1 - transLen + 1; i++){
            bool flag = true;

            for(int j=0; j<len2; j++){
                if(i + j * (idx+1) > len1){
                    debug2(i,j);
                    debug2(idx, transLen);
                    cout <<"bug1\n";
                }

                char ch1 = line1[i + j * (idx+1)];
                char ch2 = line2[j];

                if(ch1 != ch2){
                    flag = false;
                }
            }
            if(flag){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    
    int ans;
    string line1 = "abcabcabc";
    string line2 = "abc";
    ans = cntMatch(line1, line2);
    cout << ans;
    return 0;
}

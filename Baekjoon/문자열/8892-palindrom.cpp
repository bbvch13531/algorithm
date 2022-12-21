#include <bits/stdc++.h>
#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"

using namespace std;

bool isPalindrom(string str) {
    string rev = string(str.rbegin(), str.rend());
    if(str==rev) return true;
    else return false;
}

int main(){
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int T, k;
    string str;
    vector<string> vec;
    cin >>T;
    bool flag = false;
    while(T--){
        
        cin >> k;
        for(int i=0; i<k; i++){
            cin >> str;
            vec.push_back(str);
        }
        flag = false;
        for(int i=0; i<k; i++){
            for(int j=0; j<k; j++){
                if(i!=j){
                    string newStr = vec[i] + vec[j];
                    if(isPalindrom(newStr)){
                        cout << newStr <<"\n";
                        flag = true;
                        break;
                    }
                }
            }
            if(flag){
                break;
            }
        }
        if(!flag){
            cout << 0 <<"\n";
        }
        vec.clear();
    }
    return 0;
}
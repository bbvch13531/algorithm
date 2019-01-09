#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string name;
    int len,alphaCnt[26]={0,};
    bool isAns = true, isOdd = false;
    cin >> name;
    len = name.size();

    for(int i=0; i<len; i++){
        alphaCnt[name[i]-'A']++;
    }

    if(len%2){
        for(int i=0; i<26; i++){
            if(alphaCnt[i]%2 != 0){
                isAns = false;
                break;
            }
        }
        for(int i=0; i<26; i++){
            for(int j=0; j<alphaCnt[i]; j++){
                cout<<(char)i+'A';
            }
        }
    }
    else{
        for(int i=0; i<26; i++){
            if(alphaCnt[i]%2 != 0){
                if(isOdd = true){
                    isAns = false;
                    break;
                }
                isOdd = true;
            }
        }
    }
    return 0;
}
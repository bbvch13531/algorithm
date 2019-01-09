#include <iostream>
#include <string>

using namespace std;

bool isVowel(string);
int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str,output;
    bool hasVowel;
    while(cin>>str){
        hasVowel = false;
        if(str == "#") break;
        for(int i=0; i<str.size(); i++){
            if(isVowel(str)){
                output = str+"ay";
                hasVowel = true;
                break;
            }
            else{
                char ch = str[0];
                str.erase(str.begin());
                str.push_back(ch);
            }
        }
        if(hasVowel) cout<<output<<"\n";
        else cout<<str<<"ay\n";
    }

    return 0;
}

bool isVowel(string str){
    char vowels[5] = {'a','e','i','o','u'};
    for(int i=0; i<5; i++){
        if(str[0]==vowels[i]) return true;
    }
    return false;
}
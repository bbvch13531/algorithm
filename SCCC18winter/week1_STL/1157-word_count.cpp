#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(int argc, char** argv){
    vector<int> cnt(26,0);
    string in;
    int max=-1;
    char alpha;

    cin>>in;

    for(int i=0; i<in.size(); i++){
        if(in[i]<='Z'){
            cnt[in[i]-'A']++;
        }
        else{
            cnt[in[i]-'a']++;
        }
    }
    for(int i=0; i<26; i++){
        if(cnt[i]>max){
            max = cnt[i];
            alpha = i+'A';
        }
    }

    sort(cnt.begin(),cnt.end(),cmp);
    if(cnt[0] == cnt[1]){
        cout<<"?";
    }
    else cout<<alpha;
    return 0;
}
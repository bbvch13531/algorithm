#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char** argv){
    string input;
    int found;
    vector<int> arr(26,0);

    cin>>input;

    for(int i=0; i<26; i++){
        found = input.find('a'+i);
        cout<<found<<" ";
    }
    return 0;
}
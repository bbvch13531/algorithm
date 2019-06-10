#include <iostream>
#include <string>

using namespace std;

int isVowel(char ch);

char vowels[] = {'a','e','o','u','i'};
int main(void){
    string input;
    int flag=0, len;

    while(1){
        cin >> input;
        if(input == "end")
            break;
        len = input.length();
        flag = 0;
        for(int i=0; i<len; i++){
            if(isVowel(input[i])){
                flag = 1;
            }
        }
        // Invalid
        if(flag == 0){
            cout << "<" << input << "> is not acceptable.\n";
            continue;
        }
        flag = 1;
        for(int i=0; i<len-2; i++){
            // cout<<isVowel(input[i])<<isVowel(input[i+1])<<isVowel(input[i+2])<<"\n";
            if(isVowel(input[i]) == 1 && isVowel(input[i+1]) == 1 && isVowel(input[i+2]) == 1){
                flag = 0;
                break;
            }
            if(isVowel(input[i]) == 0 && isVowel(input[i+1]) == 0 && isVowel(input[i+2]) == 0){
                flag = 0;
                break;
            }
        }
        if(flag == 0){
            cout << "<" << input << "> is not acceptable.\n";
            continue;
        }
        flag = 1;
        for(int i=0; i<len-1; i++){
            if(input[i] == input[i+1] && input[i] != 'e' && input[i] != 'o'){
                flag = 0;
                break;
            }
        }
        if(flag == 0)
            cout << "<" << input << "> is not acceptable.\n";
        else
            cout << "<" << input << "> is acceptable.\n";
    }
    return 0;
}

int isVowel(char ch){
    for(int i=0; i<5; i++){
        if(ch == vowels[i])
            return 1;
    }
    return 0;
}
/*
a
tv
ptoui
bontres
zoggax
wiinq
eep
houctuh
end


<a> is acceptable.
<tv> is not acceptable.
<ptoui> is not acceptable.
<bontres> is not acceptable.
<zoggax> is not acceptable.
<wiinq> is not acceptable.
<eep> is acceptable.
<houctuh> is acceptable.
*/

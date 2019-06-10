#include <iostream>
#include <string>

using namespace std;

int isVowel(char ch);

char vowels[] = {'a','e','o','u','i'};
int main(void){
    string input;
    int flag, len;

    while(1){
        cin >> input;
        if(input == "end")
            break;
        len = input.length();

        for(int i=0; i<len; i++){
            
        }
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
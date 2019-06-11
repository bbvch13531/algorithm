#include <iostream>
#include <string>

using namespace std;
int isSame(char a, char b);
int retTime(char a);
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int P, W;
    string s;
    int len, time=0;


    cin >> P >> W;
    cin.ignore();
    // getchar();
    getline(cin, s);

    // cout<<s<<"\n";
    len = s.length();

    // for(char a='A'; a<='Z'; a++){
    //     cout<<retTime(a)<<"\n";
    // }

    for(int i=0; i<len-1; i++){
        if(isSame(s[i], s[i+1]) == 1){
            time += W;
        }
    }
    for(int i=0; i<len; i++){
        time += P * retTime(s[i]);
    }

    cout<<time;
    
    return 0;
}

int retTime(char a){
    string text[] = {
        "ADGJMPTW", "BEHKNQUX", "CFILORVY", "SZ"
    };

    if(a == ' ')
        return 1;

    for(int i=0; i<4; i++){
        int len = text[i].length();
        for(int j=0; j<len; j++){
            if(a == text[i][j])
                return i+1;
        }
    }
}
int isSame(char a, char b){
    string msg[] = { "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
    
    for(int i=0; i<8; i++){
        int len = msg[i].length();

        for(int j=0; j<len; j++){
            for(int k=0; k<len; k++){
                if(msg[i][j] == a && msg[i][k] == b)
                    return 1;
            }
        }
    }
    return 0;
}
/*
2 10 22 10 22 10 2 2222 2 2222 2 222 2 2
10 * 3
2 * (10 + 11)
*/
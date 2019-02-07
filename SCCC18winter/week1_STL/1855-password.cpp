#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(int argc, char** argv){
    int K,len,row,col;
    string str;
    bool dir=true;
    char arr[30][20];
    cin>>K;
    cin>>str;

    len = str.size();
    col = K;
    row = len/K;

    for(int i=0; i<row; i++){
        if(dir){
            for(int j=0; j<col; j++){
                arr[i][j] = str[i*K+j];
            }
        }
        else{
            for(int j=0; j<col; j++){
                arr[i][col-1-j] = str[i*K+j];
            }
        }
        dir = !dir;
    }

    // for(int i=0; i<row; i++){        
    //     for(int j=0; j<col; j++){
    //         cout<<arr[i][j];
    //     }
    //     cout<<"\n";
    // }

    for(int i=0; i<col; i++){        
        for(int j=0; j<row; j++){
            cout<<arr[j][i];
        }
    }


    return 0;
}
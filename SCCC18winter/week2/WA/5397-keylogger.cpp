#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int moveCursor(int,char);
void eraseCursor(int);
void insertCursor(int,char);
string in,out;

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T,pos;

    cin>>T;

    for(int i=0; i<T; i++){
        cin>>in;
        pos = 0;
        out.clear();
        // pos : out의 head
        for(int j=0; j<in.size(); j++){
            
            char ch = in[j];
            // cout<<"pos = "<<pos<<" j = "<<j<<"\n";
            if(ch == '<' || ch == '>'){
                pos = moveCursor(pos,ch);
            }
            else if(ch == '-'){
                eraseCursor(pos);
                if(pos!=0) pos--;
            }
            else{
                // out의 pos 위치에 문자 삽입
                insertCursor(pos,ch);
                pos++;
                // cout<<j<<" "<<out<<"\n";
            }            
        }
        cout<<out<<"\n";
    }
    return 0;
}

int moveCursor(int pos,char ch){
    if(ch=='<'){
        if(pos == 0){
            return pos;
        }
        else{
            return pos - 1;
        }
    }
    else{
        if(pos == out.size() - 1){
            return pos;
        }
        else{
            return pos + 1;
        }
    }
}
void eraseCursor(int pos){

        for(int i=pos; i<out.size()-1; i++){
            out[i] = out[i+1];
        }
        out.pop_back();
    
}
void insertCursor(int pos,char ch){
    // Type casting char to string
    char * cstr = (char*) calloc(1,sizeof(char));
    cstr[0] = ch;
    cstr[1] = '\0';

    // Insert ch end of str
    if(pos != out.size()-1){
        out.insert(pos,cstr);
    }
    else{
        out.append(cstr);
    }
    // cout<<out<<"\n";
}

/*
2
<<BP<A>>Cd-
ThIsIsS3Cr3t

B
BP
BAP
BAPC
BAPCd
BAPC
*/


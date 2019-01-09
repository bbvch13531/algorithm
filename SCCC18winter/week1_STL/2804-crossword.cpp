#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a,b;
    int posa,posb;
    char puzzle[40][40];

    cin>>a>>b;

    for(int i=0; i<a.size(); i++){
        posb = b.find(a[i]);

        if(posb!=-1){
            posa = i;
            break;
        }
    }
    for(int i=0; i<b.size(); i++){
        for(int j=0; j<a.size(); j++){
            if(j == posa) puzzle[i][j] = b[i];
            else if(i == posb) puzzle[i][j] = a[j];
            else puzzle[i][j] = '.';
        }
    }
    for(int i=0; i<b.size(); i++){
        for(int j=0; j<a.size(); j++){
            cout<<puzzle[i][j];
        }
        cout<<"\n";
    }
    return 0;
}
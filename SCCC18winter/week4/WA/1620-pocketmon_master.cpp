#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <pair>
#include <string>
#include "myBinaryTree.h"
using namespace std;

vector <pair<string,int> > names;

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M,num;
    string buf;
    long long lo,hi,mid;
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>buf;
        names.
    }


    // for(int i=0; i<N; i++){
    //     cout<<names.top()<<endl;
    //     names.pop();
    // }

    for(int i=0; i<N; i++){
        cin>>buf;
        if('0'<=buf[0] && buf[0]<='9'){
            num = stoi(buf);


        }
    }
    return 0;
}
/*
26 5
Bulbasaur
Ivysaur
Venusaur
Charmander
Charmeleon
Charizard
Squirtle
Wartortle
Blastoise
Caterpie
Metapod
Butterfree
Weedle
Kakuna
Beedrill
Pidgey
Pidgeotto
Pidgeot
Rattata
Raticate
Spearow
Fearow
Ekans
Arbok
Pikachu
Raichu
25
Raichu
3
Pidgey
Kakuna
*/
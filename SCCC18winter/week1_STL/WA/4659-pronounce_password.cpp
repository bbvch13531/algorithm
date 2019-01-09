#include <iostream>
#include <string>

using namespace std;

bool isFirst(string);
bool isSecond(string);
bool isThird(string);
bool isTripleVowel(string,int);
bool isTripleConsonant(string,int);

char vowel[5] = {'a','e','i','o','u'};

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string in;

    while(1){
        cin>>in;
        if(in == "end") break;

        if(isFirst(in) && isSecond(in) && isThird(in)){
            cout<<"<"<<in<<">"<<" is acceptable.\n";
        }
        else{
            cout<<"<"<<in<<">"<<" is not acceptable.\n";
        }

    }
    


    return 0;
}

bool isFirst(string in){
    
    for(int i=0; i<in.size(); i++){
        for(int j=0; j<5; j++){
            if(in.find(vowel[j]) == 1){
                return true;
            }
        }
    }
    return false;
}
bool isSecond(string in){
    for(int i=0; i<in.size()-2; i++){
        if(isTripleConsonant(in,i) || isTripleConsonant(in,i)){
            return false;
        }
    }
    return true;
}
bool isThird(string in){
    for(int i=0; i<in.size()-1; i++){
        if(in[i] == in[i+1]){
            if(in[i] == 'e' || in[i] == 'o'){
                return true;
            }
            else
                return false;
        }        
    }
    return true;
}
bool isTripleVowel(string in,int pos){
    if(in[pos] == in[pos+1] && in[pos+1] == in[pos+2]){
        if()
    }
}
bool isTripleConsonant(string in,int pos){

}
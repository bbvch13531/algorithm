#include <iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string in;
    
    while(1){
        // cin>>in;
        getline(cin, in);
        if(in == "#")
            break;
        for(int i=0; i<in.length(); i++){
            if(in[i] == ' ')
                cout<<"%20";
            else if(in[i] == '!')
                cout<<"%21";
            else if(in[i] == '$')
                cout<<"%24";
            else if(in[i] == '%')
                cout<<"%25";
            else if(in[i] == '(')
                cout<<"%28";
            else if(in[i] == ')')
                cout<<"%29";
            else if(in[i] == '*')
                cout<<"%2a";
            else
                cout<<in[i];
        }
        cout<<"\n";
    }
    return 0;
}
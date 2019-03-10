#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    int begin,end,max=-1;
    bool isZero=false;
   
    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin>>begin>>end;
        M = M + begin - end;
        if(M>max){
            max=M;            
        }
        if(M<0) isZero = true;
    }
    if(isZero) cout<<"0";
    else cout<<max;

    return 0;
}
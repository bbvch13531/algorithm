#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
vector <int> arr1,arr2;
int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M,tmp;    
    bool ans;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>tmp;
        arr1.push_back(tmp);
    }
    sort(arr1.begin(),arr1.end());
    cin>>M;
    for(int i=0; i<M; i++){
        cin>>tmp;
        arr2.push_back(tmp);
    }

    for(int i=0; i<M;i++){
        ans = binary_search(arr1.begin(),arr1.end(),arr2[i]);
        
        if(ans){
            cout<<1<<"\n";
        }
        else{
            cout<<0<<"\n";
        }
    }
    return 0;
}

/*
5
4 1 5 2 3
5
1 3 7 9 5
*/
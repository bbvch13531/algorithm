#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool mycmp(int a,int b){
    return a < b;
}
int main(int argc, char**argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,buf;
    vector <int> arr;

    cin>>N;

    for(int i=0; i<N; i++){
        cin>>buf;
        arr.push_back(buf);        
    }
    sort(arr.begin(),arr.end(),mycmp);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<"\n";
    }
    return 0;
}
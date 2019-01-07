#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

bool compare(const pair<int,int> &a,const pair<int,int> &b){
    if(a.first < b.first ) return true;
    else if (a.first == b.first){
        return a.second < b.second;
    }
    else return false;
}

int main(int argc, char** argv){
    vector<pair<int,int> > co;
    int N,x,y;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++){
        cin>>x>>y;
        co.push_back(make_pair(x,y));
    }
    sort(co.begin(),co.end(),compare);

    for(int i=0; i<co.size(); i++){
        cout<<co[i].first<<" "<<co[i].second<<"\n";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(int argc, char ** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M,buf,cnt=0;
    vector <int> sang,sun;

    cin>>N>>M;

    for(int i=0; i<N; i++){
        cin>>buf;
        sang.push_back(buf);
    }
    for(int i=0; i<M; i++){
        cin>>buf;
        int res = binary_search(sang.begin(),sang.end(),buf);
        cout<<"res = "<<res<<"\n";
        if(res != 0){
            cnt++;
        }
    }
    cin>>buf>>buf;

    cout<<cnt;

    return 0;
}
/*
3 3
1
2
3
1
2
4
0 0
*/
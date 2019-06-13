#include <iostream>
#include <vector>

#define ll long long

using namespace std;

vector <ll> trees;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, t;
    ll lo, hi, mid;
    ll sum, maxHeight, maxInput=-1;

    cin>>N>>M;

    for(int i=0; i<N; i++){
        cin>>t;
        if(t>maxInput)
            maxInput = t;
        trees.push_back(t);
    }

    lo = 0;
    hi = maxInput;

    while(lo<hi){
        sum = 0;
        mid = (lo+hi)/2;

        for(int i=0; i<N; i++){
            if(trees[i] > mid)
                sum += trees[i] - mid;
        }
        // cout<<lo<<" "<<mid<<" "<<hi<<" "<<sum<<"\n";
        if(sum >= M){
            maxHeight = mid;
            lo = mid+1;
        }
        else{
            hi = mid;
        }

    }
    cout<<maxHeight;
    return 0;
}
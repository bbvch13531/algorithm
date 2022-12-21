#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> A, B, merged;
    int N, M, tmp;
    int l = 0, r = 0;
    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin >> tmp;
        A.push_back(tmp);
    }
    for(int i=0; i<M; i++){
        cin >> tmp;
        B.push_back(tmp);
    }

    while(l<A.size() && r<B.size()) {
        if(A[l] < B[r]) {
            // merged.push_back(A[l]);
            cout << A[l] <<" ";
            l++;
        } else {
            // merged.push_back(B[l]);
            cout << B[r] <<" ";
            r++;
        }
    }
    
    if(l < A.size()) {
        // push A [l, N] to merged
        // merged.insert(merged.end(), A.begin() + l, A.end());
        for(int i=l; i<N; i++){
            cout << A[i] <<" ";
        }
    }

    if(r < B.size()) {
        // push B [r, M] to merged
        // merged.insert(merged.end(), B.begin() + r, B.end());
        for(int i=r; i<M; i++){
            cout << B[i] << " ";
        }
    }

    return 0;
}
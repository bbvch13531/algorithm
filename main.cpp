#include <iostream>
#include <map>
#include <string>
using namespace std;

int root[2000001];
int counter[2000001];

int find(int k){
    if(k == root[k]) return k;
    return root[k] = find(root[k]);
}

int merge(int p, int q){
    p = find(p);
    q = find(q);
    if(p != q){
        root[q] = p;
        counter[p] += counter[q];
        counter[q] = 1;
    }
    return counter[p];
}

int main(){
    int T,N, idx1, idx2, num=1,ans;
    map<string, int> index;
    char s[21], p[21];
    
    cin>>T;

    while(T--){

        cin>>N;
        
        for(int i=1; i<=2*N; ++i){
            root[i] = i;
            counter[i] = 1;
        }
    
        for(int i=0; i<N; ++i){
            cin>>s>>p;
            
            if(index.count(s)==0) index[s] = num++;
            idx1 = index[s];
            if(index.count(p)==0) index[p] = num++;
            idx2 = index[p];
            ans=merge(idx1,idx2);
            cout<<ans<<endl;
        }
    }
    return 0;
}

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

set<ll> num; 
map<ll, ll> indegree;

int main(void){
    
    ll u=1, v=1;
    int edgeCnt=0;
    int testCase = 0;

    bool eofFlag = false, ans = true;

    while(1){
        edgeCnt=0;
        ans = true;
        num.clear();
        indegree.clear();
        testCase++;
        while(scanf("%lld %lld", &u, &v) && (u || v )) {
            if(u==-1 && v == -1){
                return 0;
            }

            edgeCnt++;
            
            if(num.find(u) == num.end()){
                num.insert(u);
            }

            if(num.find(v) == num.end()){
                num.insert(v);
            }

            if(indegree.find(v) == indegree.end()){
                indegree.insert({ v, 0});
            } else {
                ans = false;    // 어떤 노드로 가는 경로가 2개임
            }
        }
    
        if(edgeCnt+1 != num.size() && edgeCnt > 0) ans = false;
        
        if(ans) printf("Case %d is a tree.\n", testCase);
        else  printf("Case %d is not a tree.\n", testCase);
    }
    return 0;

}
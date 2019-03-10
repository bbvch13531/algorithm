#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
void visit(int,int);

int N,K;
int isVisit[100010];
queue <pair<int,int> > que;

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int des,desCnt=0;
    
    cin>>N>>K;

    que.push(make_pair(N,0));
    isVisit[N] = 1;
    while(1){
        des = que.front().first;
        desCnt = que.front().second;
        // cout<<"desCnt = "<<desCnt<<"des = "<<des<<"\n";
        if(des == K){
            break;
        }
        que.pop();
       
        visit(des+1,desCnt);
        visit(des-1,desCnt);
        visit(des*2,desCnt);

    }
    cout<<desCnt;
    return 0;
}
void visit(int x,int cnt){

    if(x>=0 && x<=100000 && isVisit[x] == 0){
        isVisit[x] = 1;
        que.push(make_pair(x,cnt+1));
        // cout<<x<<"\n";
    }
}
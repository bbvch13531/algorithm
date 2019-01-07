#include <iostream>

using namespace std;

void process(int);
bool isPromising(int);
int abs(int,int);
int N,cnt=0;
int map[20][20],col[20];

int main(void){
    cin>>N;

    col[1]=1;
    process(1);
    cout<<cnt;
    return 0;

}

void process(int row){
    if(row==N){
        cnt++;
        return;
    }

    for(int i=1; i<=N; i++){
        if(isPromising(i)){
            col[row+1] = i;
            cout<<"process i = "<<i<<endl;
            process(i);
        }
    }
}

bool isPromising(int n){
    for(int i=1; i<=N; i++){
        cout<<"isPromising i = "<<i;
        if(col[n]==col[i] || abs(n,i) == abs(col[n],col[i])){
            cout<<"\tfalse\n";
            return false;
        }
    }
    cout<<"\ttrue\n";
    return true;
}

int abs(int a,int b){
    if(a>b) return a-b;
    else return b-a;
}
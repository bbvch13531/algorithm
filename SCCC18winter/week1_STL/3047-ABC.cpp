#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int buf,alpha[3];
    char order[3];
    priority_queue <int> abc;

    for(int i=0; i<3; i++){
        cin>>buf;
        abc.push(buf);
    }

    for(int i=0; i<3; i++){
        cin>>order[i];
    }
    for(int i=0; i<3; i++){
        alpha[2-i] = abc.top();
        abc.pop();
    }

    for(int i=0; i<3; i++){
        if(order[i] == 'C') cout<<alpha[2]<<" ";
        else if (order[i] == 'B') cout<<alpha[1]<<" ";
        else cout<<alpha[0]<<" ";
    }

    return 0;
}

/*
1 5 3
ABC
*/
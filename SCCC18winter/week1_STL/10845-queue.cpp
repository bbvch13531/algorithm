#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    queue <int> que;
    int N,operand;
    string command;

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> command;
        // printf("%s\n",command.c_str());
        // cout<<command<<endl;
        if(command == "push"){
            cin >> operand;
            que.push(operand);
        }
        else if(command == "pop"){
            if(!que.empty()){
                printf("%d\n",que.front());
                que.pop();        
            }
            else
                printf("-1\n");
        }
        else if(command == "size"){
            printf("%d\n",que.size());
        }
        else if(command == "empty"){
            printf("%d\n",que.empty());
        }
        else if(command == "front"){
            if(!que.empty()){
                printf("%d\n",que.front());    
            }
            else
                printf("-1\n");
        }
        else if(command == "back"){
            if(!que.empty()){
                printf("%d\n",que.back());    
            }
            else
                printf("-1\n");
        }
    }

    return 0;
}
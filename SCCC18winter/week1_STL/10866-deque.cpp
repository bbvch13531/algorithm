#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    deque <int> deq;
    int N,operand;
    string command;

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> command;
        // printf("%s\n",command.c_str());
        // cout<<command<<endl;
        if(command == "push_front"){
            cin >> operand;
            deq.push_front(operand);
        }
        else if(command == "push_back"){
            cin >> operand;
            deq.push_back(operand);
        }
        else if(command == "pop_front"){
            if(!deq.empty()){
                printf("%d\n",deq.front());
                deq.pop_front();        
            }
            else
                printf("-1\n");
        }
        else if(command == "pop_back"){
            if(!deq.empty()){
                printf("%d\n",deq.back());
                deq.pop_back();        
            }
            else
                printf("-1\n");
        }
        else if(command == "size"){
            printf("%d\n",deq.size());
        }
        else if(command == "empty"){
            printf("%d\n",deq.empty());
        }
        else if(command == "front"){
            if(!deq.empty()){
                printf("%d\n",deq.front());    
            }
            else
                printf("-1\n");
        }
        else if(command == "back"){
            if(!deq.empty()){
                printf("%d\n",deq.back());    
            }
            else
                printf("-1\n");
        }
    }

    return 0;
}
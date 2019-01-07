#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    stack <int> stk;
    int N,operand;
    string command;


    cin >> N;

    for(int i=0; i<N; i++){
        cin >> command;
        // printf("%s\n",command.c_str());
        // cout<<command<<endl;
        if(command == "push"){
            cin >> operand;
            stk.push(operand);
        }
        else if(command == "pop"){
            if(!stk.empty()){
                printf("%d\n",stk.top());
                stk.pop();        
            }
            else
                printf("-1\n");
        }
        else if(command == "size"){
            printf("%d\n",stk.size());
        }
        else if(command == "empty"){
            printf("%d\n",stk.empty());
        }
        else if(command == "top"){
            if(!stk.empty()){
                printf("%d\n",stk.top());    
            }
            else
                printf("-1\n");
        }
        else{
            printf("not match\n");
        }
    }

    return 0;
}
/*
tc1
14
push 1
push 2
top
size
empty
pop
pop
pop
size
empty
pop
push 3
empty
top

2
2
0
2
1
-1
0
1
-1
0
3

tc2
7
pop
top
push 123
top
pop
top
pop

-1
-1
123
123
-1
-1
*/
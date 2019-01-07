#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void){
    int cnt=0, sum=0;
    string input;
    stack <int> stk;

    cin >> input;

    for(int i=0; i<input.size(); i++){
        if(input[i] == '('){
            cnt++;
            stk.push(1);
        }
        else{
            if(!stk.empty()){
                cnt--;
                stk.pop();

                // Laser
                if(input[i-1] == '('){
                    sum += cnt;    
                }
                // End of stick
                else{
                    sum++;
                }
            }
        }
    }
    cout << sum;
    return 0;
}

/*
()(((()())(())()))(())
17

(((()(()()))(())()))(()())
24
*/
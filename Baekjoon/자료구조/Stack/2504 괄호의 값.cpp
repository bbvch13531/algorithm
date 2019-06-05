#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    stack<char> stk;
    string input;
    char ch;
    int score = 1, sum = 0;
    int N = 0;

    cin >> input;
    // cout<<"input size = " << input.size()<< endl;
    for(int i=0; i<input.size(); i++){
        ch = input[i];
        // cout<<"ch = "<< ch <<endl;
        if(ch=='('){
            score *= 2;
            stk.push(ch);
        }
        else if(ch=='['){
            score *= 3;
            stk.push(ch);
        }
        else if(ch==')'){
            if(stk.empty()){
                sum = 0;
                break;
            }
            if(stk.top() == '['){
                sum = 0;
                break;
            }
            if(input[i-1] == '('){
                sum += score;
            }
            stk.pop();
            score /= 2;
        }
        else if(ch == ']'){
            if(stk.empty()){
                sum = 0;
                break;
            }
            if(stk.top() == '('){
                sum = 0;
                break;
            }
            if(input[i-1] == '['){
                sum += score;
            }
            stk.pop();
            score /= 3;
        }
        // cout<< i << " " << sum << " " << score << endl;
    }
    if(!stk.empty())
        sum = 0;
    cout << sum;

    return 0;
}
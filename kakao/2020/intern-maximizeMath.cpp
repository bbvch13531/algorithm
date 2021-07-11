#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <stack>

#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"

using namespace std;
int N=3;
bool visit[5];
string arr[3];
string op[3] = {"+", "*", "-"};
vector <string> mathExpression;
long long maxVal = -1;

void parse(string expression) {
   int s=0,len = expression.length();
   string num;
    for(int i=0; i<len; i++) {
        char ch = expression[i];
        if(ch == '+' || ch == '*' || ch == '-') {
            num = expression.substr(s,i-s);
            s = i+1;
            mathExpression.push_back(num);
            mathExpression.push_back(string(1, ch));
        }
    }
    num = expression.substr(s, len-s);
    mathExpression.push_back(num);

    // for(int i=0; i<mathExpression.size(); i++){
    //     debug1(mathExpression[i]);
    // }
}

string calculate(string op, string a, string b){
    long long lla = stoll(a);
    long long llb = stoll(b);
    long long num;
    if(op == "+") {
        num = lla + llb;
    } else if(op == "*") {
        num = lla * llb;
    } else {
        num = lla - llb;
    }
    return to_string(num);
} 

void process(string expression) {
    stack <int> stk;
    mathExpression.clear();
    parse(expression);
    vector <string> copyEx (mathExpression);
    int len = mathExpression.size();
    string res;


    for(int j=0; j<3; j++){
        int i=0;
        while(1){
            // vec에 arr[j]가 없을 때까지 반복
            // i는 arr[j]의 인덱스
            if(i== mathExpression.size())
                break;
            string str = mathExpression[i];
            if(str == arr[j]){
                res = calculate(str, mathExpression[i-1], mathExpression[i+1]);
                auto it = mathExpression.begin();
                // mathExpression insert at i-1 position
                mathExpression.erase(it+i-1);
                mathExpression.erase(it+i-1);
                mathExpression.erase(it+i-1);
                
                mathExpression.insert(it+i-1, res);
                // resArr.push_back(res);
                // mathExpression = copyEx;
                i=0;
            } else {
                i++;
            }
        }
    }
    long long val;
    if(mathExpression.size() == 1){
        val = stoll(mathExpression[0]);
    }
    if(abs(val) > maxVal){
        maxVal = abs(val);
    }
}

void dfs(int idx, string expression){
    if(idx==N) {
        // for(int i=0 ;i<3; i++)
        //     cout << arr[i] << " ";
        // cout << "\n";

        process(expression);
        return;
    }
   for(int i=0; i<N; i++){
        if(!visit[i]){
            visit[i]=true;
            arr[idx] = op[i];
            dfs(idx+1, expression);
            visit[i]=false;
        }
    }
}

long long solution(string expression) {
    long long answer = 0;
    dfs(0, expression);
    answer = maxVal;
    return answer;
}

int main(void){
    string expression;
    cin >> expression;
    
    long long ans = solution(expression);
    cout << ans<<"\n";

   
    return 0;
}
/*
100-200*300-500+20

50*6-3*2


*/
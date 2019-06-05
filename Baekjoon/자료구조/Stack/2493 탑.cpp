#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N, max = -1;
    vector <int> height;
    stack <int> stk;

    cin >> N;

    for(int i=0 i<N; i++){
        cin >> h;
        height.push_back(h);
    }
    
    max = height[0];
    stk.push(max);

    for(int i=1; i<height.size(); i++){
        if(height[i] > max)
            max = height[i];
        
        if(stk.top() )
    }
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>

#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"

using namespace std;

// 2: 0
// 5: 1
// 8: 2
// 0: 3

    // 1: 0
    // 4: 1
    // 7: 2
    // *: 3

    // 3: 0
    // 6: 1
    // 9: 2
    // #: 3

int distanceLeft(int key, int left) {
    if(left % 3 == 1) {
        return abs(key/3 - left/3) + 1;
    } else {
        return abs(key/3 - left/3);
    }
}

int distanceRight(int key, int right) {
    if(right % 3 == 0) {
        return abs(key/3 - (right/3-1)) + 1;
    } else {
        return abs(key/3 - right/3);
    }
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    int l=10, r=12;
    int num;
    bool useLeft = false;
    for(int i=0; i<numbers.size(); i++){
        num = numbers[i];
        
        if(num == 1 || num == 4 || num == 7){
            useLeft = true;
        }
        else if(num == 3 || num == 6 || num == 9){
            useLeft = false;
        } else {
            if(num == 0) num = 11;
            
            int dl = distanceLeft(num, l);
            int dr = distanceRight(num, r);
            debug2(l,r);
            debug3(num, dl, dr);
            if(dl < dr) {
                useLeft = true;
            }else if (dl > dr) {
                useLeft = false;
            } else {
                if(hand == "left"){
                    useLeft = true;
                } else {
                    useLeft = false;
                }
            }
        }
        if(useLeft) {
            answer.append("L");
            l = num;
            if(num == 0)   l = 11;
        } else {
            answer.append("R");
            r = num;
            if(num == 0)   r = 11;
        }
    }
    
    return answer;
}
int main(void){
    int N,tmp;
    vector<int> numbers;
    string hand;
    cin >> N >> hand;
    for(int i=0; i<N; i++){
        cin >> tmp;
        numbers.push_back(tmp);
    }
    string ans = solution(numbers, hand);
    cout << ans<<"\n";
    return 0;
}
/*
11 left
7 0 8 2 8 3 1 5 7 6 2

11 right
1 3 4 5 8 2 1 4 5 9 5

*/
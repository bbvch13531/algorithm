/*

https://programmers.co.kr/learn/courses/30/lessons/77484?language=cpp
로또 6/45(이하 '로또'로 표기)는 1부터 45까지의 숫자 중 6개를 찍어서 맞히는 대표적인 복권입니다. 아래는 로또의 순위를 정하는 방식입니다. 1
민우가 구매한 로또 번호를 담은 배열 lottos, 당첨 번호를 담은 배열 win_nums가 매개변수로 주어집니다. 이때, 당첨 가능한 최고 순위와 최저 순위를 차례대로 배열에 담아서 return 하도록 solution 함수를 완성해주세요.

*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"

using namespace std;

int main(void) {
    int T, num, zero_cnt;
    vector<int> lotto, win;
    cin >> T;

    for(int tc=0; tc<T; tc++) {
        lotto.clear();
        win.clear();
        zero_cnt=0;
        for(int i=0; i<6; i++){
            cin >> num;
            if(num == 0){
                zero_cnt++;
            }
            lotto.push_back(num);
        }

        for(int i=0; i<6; i++){
            cin >> num;
            win.push_back(num);
        }
    
        sort(lotto.begin(), lotto.end());
        sort(win.begin(), win.end());

        int match_num = 0, max_match_possible;

        for(int i=0; i<6; i++){
            for(int j=0; j<6; j++){
                if(lotto[i] == win[j]) {
                    match_num++;
                }
            }
        }
        cout <<"\n"<< 7-match_num << " " << zero_cnt<<"\n";
    }
    return 0;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int match_num=0, zero_cnt=0;
    
    for(int ele:lottos) {
        if(ele == 0) zero_cnt++;
    }
    
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            if(lottos[i] == win_nums[j]){
                match_num++;
            }
        }
    }
    int max_match = match_num+zero_cnt;
    int min_match = match_num;
    
    
    if(max_match < 2) {
        answer.push_back(6);
    } else {
        answer.push_back(7 - max_match);
    }
        
    if(min_match < 2) {
        answer.push_back(6);
    } else {
        answer.push_back(7 - min_match);
    }
    return answer;
}

/*


3
44 1 0 0 31 25
31 10 45 1 6 19

0 0 0 0 0 0
38 19 20 40 15 25

45 4 35 20 3 9
20 9 3 45 4 35


*/
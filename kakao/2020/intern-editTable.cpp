#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <fstream>

#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"

using namespace std;

class Table {
    public:
        int m_cur;
        int m_tail;
        stack <int> m_recents;

        vector<bool> data;

        Table(int N, int K){
            for(int i=0; i<N; i++){
                data.push_back(true);
            }
            m_cur = K;
            m_tail = N-1;
        }

        void down(int n){
            int cnt=0, i=0;
            while(cnt < n) {
                if(data[m_cur+i+1]){
                    cnt++;
                }
                i++;
            }
            m_cur += i;
        }
    
        void up(int n){
            int cnt=0, i=0;
            while(cnt < n) {
                if(data[m_cur-i-1]){
                    cnt++;
                }
                i++;
            }
            m_cur -= i;
        }

        void remove() {
            data[m_cur] = false;
            m_recents.push(m_cur);

            if(m_cur == m_tail){
                m_cur = m_tail = updateTail();
            } else {
                m_cur = next();
            }
        }

        void undo() {
            int num = m_recents.top();
            m_recents.pop();

            data[num] = true;          

            if(m_cur == -1)
                m_cur = next();
            m_tail = updateTail();
        }
        
        int next() {
            int start;
            if(m_cur == -1){
                start = 0;
            } else {
                start = m_cur;
            }
            
            for(int i=start; i<data.size(); i++){
                if(data[i]){
                    return i;
                }
            }
            return -1;
        }

        int updateTail(){
            for(int i=data.size()-1; i>=0; i--){
                if(data[i]){
                    return i;
                }
            }
            return -1;
        }

        void print() {
            for(int i=0; i<data.size(); i++){
                cout << i << ": ";
                if(data[i]){
                    cout << "T";
                } else {
                    cout << "F";
                }
                cout<<"\n";
            }
            debug2(m_cur, m_tail);

            cout << "\n";
        }
};

string solution(int n, int k, vector<string> cmd) {
    string answer = "";

    Table table = Table(n, k);
    
    for(int i=0; i<cmd.size(); i++){
        if(cmd[i][0] == 'U'){
            int num = cmd[i][2] - '0';
            table.up(num);
        } else if(cmd[i][0] == 'D'){
            int num = cmd[i][2] - '0';
            table.down(num);
        } else if(cmd[i][0] == 'C'){
            table.remove();
        } else if(cmd[i][0] == 'Z'){
            table.undo();
        }
        // cout << i << ": " << cmd[i] <<"\n";
        table.print();
    }
    for(int i=0; i<table.data.size(); i++){
        if(table.data[i]){
            answer += "O";
        } else {
            answer += "X";
        }
    }
    return answer;
}

int main(void){
    int N, K, cmdLen;
    string tmp;
    vector<string> cmd;
    freopen("input-editTable.txt", "r", stdin);
    cin >> N >> K >> cmdLen;
    cin.ignore();
    for(int i=0; i<cmdLen; i++){
        // cin >> tmp;
        getline(cin, tmp);
        cmd.push_back(tmp);
    }
    string ans = solution(N, K, cmd);
    cout << ans;
    return 0;
}
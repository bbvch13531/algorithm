#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <cstring>

using namespace std;

vector <pair< int, int > > logtime;

void toMilsec(vector<string> lines);

int solution(vector<string> lines) {
    int answer = 0;
    toMilsec(lines);
    int cnt=0;
    for(int i=0; i<logtime.size(); i++) {
        int start = logtime[i].first;
        int end = logtime[i].second;
    	cnt=0;
        for(int j=i; j<logtime.size(); j++) {
            if(i==j){
                continue;
            }
           	int ss=logtime[j].first, ee = logtime[j].second;
            
            // case1: start <= 다음 로그의 시작시간 < start + 1000
            // case2: end <= 다음 로그의 시작시간 < end + 1000
            
            if(start <= ss && ss <= start + 999){
                // cout << start << ' ' << ss << ' ' << start+999 << endl;
                cnt++;
            } else if(end <= ss && ss <= end + 999) {
                // cout << end << ' ' << ss << ' ' << end+999 << endl;
                cnt++;
            }
            if(cnt > answer){
                answer = cnt;
            }
        }
        	cout << "cnt = " << cnt << endl;
    }
    
//    for(int i=0; i<logtime.size(); i++) {    
  //          cout << logtime[i].first << ' ' << logtime[i].second << endl;
    //}
    return answer+1;
}

void toMilsec(vector<string> lines){
	int milsec=0;
    for(auto it: lines){ 
        string s1 = it.substr(11, 12);
        int i1 = it.find('s');
        string dur = it.substr(24, i1 - 24);
        //        cout << s1 << ' ' << dur << endl;
        
        milsec = 0;
        
        char s2[50]; 
        strcpy(s2,s1.c_str());
      	
        int hh, mm, ss, sss;
        sscanf(s2, "%d:%d:%d.%d", &hh, &mm, &ss, &sss);
        
        // hh
        milsec += hh * 60 * 60 * 1000;
        
        // mm
        milsec += mm * 60 * 1000;
        
        // ss
        milsec += ss * 1000;
        
        // sss
        milsec += sss;
        
        double dur1;
        sscanf(dur.c_str(), "%lf", &dur1);
 		       
        int dur2 = dur1 * 1000;
        logtime.emplace_back(milsec-dur2+1, milsec);
    }
}

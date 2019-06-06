#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define MIN 0x3fffffff
using namespace std;

struct Meeting{
    int start;
    int end;
};

bool operator < (Meeting a, Meeting b){
    if(a.end != b.end)
        return a.end < b.end;
    else
        return a.start < b.start;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector <Meeting> v;

    int N;
    int start_time = 0, end_time = 0, cnt=0;
    cin>> N;

    for(int i=0; i<N; i++){
        int s, e;
        cin>> s>> e;
        Meeting m;
        m.start = s;
        m.end = e;
        v.push_back(m);
    }

    sort(v.begin(), v.end());

    // Meeting m;
    // for(int i=0; i<v.size(); i++){
    //     m = v[i];
    //     printf("%d %d\n",m.start, m.end);
    // }

    for(int i=0; i<v.size(); i++){
        if(v[i].start >= end_time){
            end_time = v[i].end;
            cnt++;
        }
    }
    cout << cnt <<"\n";
    return 0;
}

/*
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14
*/
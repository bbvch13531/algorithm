#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <cstdio>
#include <iostream>

using namespace std;


vector<int> solution(vector<string> maps) {
    
bool visit[1010][1010];
bool count[1010][1010];
queue <pair<int, int> > q;

int dx[4] = {1, 0 ,-1, 0};
int dy[4] = {0 ,1, 0, -1};
    
    vector<int> answer;
     int N = maps.size();
     int M = maps[0].size();
   // int N = 11;
   // int M = 10;
    int ans = 0;
    // cout<< N <<" "<< M<<"\n";
    for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(maps[i][j] != '.'){
                pair<int, int> in = make_pair(i, j);
				q.push(in);
	//			printf("%d %d, map=%c\n", i, j, maps[i][j]);
			}
		}
	}
    
	while(!q.empty()){
		pair<int, int> fp = q.front();
		q.pop();

        int fx = fp.first;
        int fy = fp.second;
    		//printf("fx = %d, fy = %d\n", fx, fy);
        if(maps[fx][fy] == '.' || visit[fx][fy] == true) continue;

        visit[fx][fy] = true;
        char current = maps[fx][fy];
        for(int i=0; i<4; i++){
            int nx = fx + dx[i];
            int ny = fy + dy[i];
            cout << nx << ' ' << ny <<"\n";

            if(0<= nx && nx <N && 0 <= ny && ny < M){
            char near = maps[nx][ny];
                	printf("%d %d, near=%c, current=%c\n", nx, ny, near, current);
                if(near != '.' && near != current){
                    if(!count[current-'A'][near-'A'] && !count[near-'A'][current-'A']){
                    ans++;
                    count[current-'A'][near-'A'] = count[near-'A'][current-'A'] = true;
                    visit[nx][ny] = true;
                    }
                }
            }
            
        }
	}

	int max = -1, curcnt;
	for(int i=0; i<26; i++){
		curcnt = 0;
		for(int j=i; j<26; j++){
			if(count[i][j] == true)	curcnt++;
		}
		if(curcnt > max) max = curcnt;
	}
    answer[0] = ans;
    answer[1] = curcnt;
    return answer;
}

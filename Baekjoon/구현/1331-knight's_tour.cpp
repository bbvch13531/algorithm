/*
https://www.acmicpc.net/problem/1331
체스판에서 나이트의 이동을 구현하는 문제.
*/
#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
    int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int visit[10][10]={0,};

    char in;
    int mx[40], my[40], cury, curx;
    int flag;

    for(int i=0; i<36; i++){
        scanf("%c%d", &in, &my[i]);
        mx[i] = in-'A';
        getchar();
    }

    mx[36] = mx[0];
    my[36] = my[0];
    
    for(int i=0; i<36; i++){
        flag = 0;
        for(int j=0; j<8; j++){
            curx = mx[i] + dx[j];
            cury = my[i] + dy[j];

            if(curx == mx[i+1] && cury == my[i+1] && visit[curx][cury] == 0){
                flag = 1;
                visit[curx][cury] = 1;
                break;
            }
        }
        if(flag == 0){
            break;
        }
    }
    if(flag == 1)
        printf("Valid");
    else
        printf("Invalid");
    return 0;
}

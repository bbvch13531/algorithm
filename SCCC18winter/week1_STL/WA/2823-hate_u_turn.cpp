#include <cstdio>

using namespace std;

bool isEnd(int,int);
bool isSame(char,char,char);
int N,M;
char map[20][20];
int main(int argc, char** argv){
    
    bool isAns = false;

    scanf("%d %d",&N,&M);

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            scanf("%c ",&map[i][j]);
            map[0][j] = map[N+1][j] = map[i][0] = map[i][M+1] = 'X';
        }
        getchar();
    }
    for(int i=0; i<=N+1; i++){
        for(int j=0; j<=M+1; j++){
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(map[i][j] == '.'){
                if(isEnd(i,j)){
                    isAns = true;
                    break;
                }
            }
        }
        if(isAns) break;
    }
    if(isAns) printf("1");
    else printf("0");

    return 0;
}
bool isEnd(int x,int y){

    /*
    XXX
    X..
    XXX
    */
    if(isSame(map[x-1][y], map[x][y-1], map[x+1][y]) && map[x][y+1] == '.'){
        printf("1\n");
        return true;
    }
    
    /*
    XXX
    ..X
    XXX
    */
    else if(isSame(map[x-1][y], map[x][y+1], map[x+1][y]) && map[x][y-1] == '.'){
        printf("2\n");
        return true;
    }

    /*
    X.X
    X.X
    XXX
    */
    else if(isSame(map[x][y-1], map[x][y+1], map[x+1][y]) && map[x-1][y] == '.'){
        printf("3\n");
        return true;
    }
    /*
    XXX
    X.X
    X.X
    */
    else if(isSame(map[x-1][y], map[x][y-1], map[x][y+1]) && map[x+1][y] == '.'){
        printf("4\n");
        return true;
    }
    else    return false;
}

bool isSame(char a,char b ,char c){
    printf("isSame %c %c %c\n",a,b,c);
    if(a == b && b == c && c == 'X')
        return true;
    else 
        return false;
}
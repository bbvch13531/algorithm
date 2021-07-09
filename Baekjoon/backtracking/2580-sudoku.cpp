#include <iostream>
#include <vector>

using namespace std;

int map[10][10];

bool validate(void){
    //check rows
    int check[10]={0,}, flag;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++)  check[j] = 0;
        for(int j=0; j<9; j++){
            if(map[i][j]){
                if(check[j]==0){

                }
            }
        }
    }
}

void dfs(int x, int y){

    for(int i=0; i<9; i++){
        map[x][y] == i+1;

        if(validate()){
            for(int j=0; j<9; j++){
                for(int k=0; k<9; k++){
                    if(map[j][k] == 0){
                        dfs(j, k);
                    }
                }
            }    
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> map[i][j];
        }
    }


  
    
    return 0;
}
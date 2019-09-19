#include <iostream>

using namespace std;

int map[20][20];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0; i<19; i++){
        for(int j=0; j<19; j++){
            cin>>map[i][j];
        }
    }
    for(int i=0; i<19; i++){
        for(int j=0; j<19; j++){

            if(map[i][j] == 1 && map[i][j+1] == 1 && map[i][j+2] == 1 && map[i][j+3] == 1 && map[i][j+4] == 1){
                
            }
        }
    }
    return 0;
}
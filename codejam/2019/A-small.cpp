#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;
int doesNotContain4(int n);
int main(void){
    int T, num;
    scanf("%d", &T);
    
    for(int i=0; i<T; i++){
        scanf("%d", &num);
        
        for(int j=1; j<num; j++){   //  10^9
            // j가 4를 포함하는지   //  max 9
            if(doesNotContain4(j) && doesNotContain4(num - j)){
                printf("Case #%d: %d %d\n",i+1, j, num-j);
                break;
            }
            // printf("j = %d\t",j);
            // doesNotContain4(j);
            // num - j가 4를 포함하는지
        }
    }
    return 0;
}

int doesNotContain4(int n){
    int ten = 1;
    int cnt = 1, digit[20], flag = 1;
    char buf[20];
    sprintf(buf,"%d",n);
    cnt = strlen(buf);
    // while(ten*10 <= n){
    //     ten *= 10;
    //     cnt++;
    // }
    // printf("cnt = %d, ten = %lld\n",cnt, ten);
    // for(int i=0; i<cnt; i++){
    //     digit[i] = n / ten;
    //     n -= digit[i] * ten;

    //     ten /= 10;
    // }
    for(int i=0; i<cnt; i++){
        if(buf[i] == '4'){
            return false;
        }
    }
    return true;
    // for(int i=0; i<cnt; i++){
    //     // printf("%d ",digit[i]);
    //     if(digit[i] == 4){
    //         return false;
    //     }
    // }
    // printf("\n");

    return true;
}
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;
int doesNotContain4(int n);
void setupTable4(int n);
int tenEx(int n);
vector <int> table4;
int tenth;
int main(void){
    int T, num;
    int ten;
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    
    scanf("%d", &T);
    
    for(int i=0; i<T; i++){
        ten = 1, tenth = 0; 

        scanf("%d", &num);
        
        while(ten*10 <= num){
            ten *= 10;
            tenth++;    // 거듭제곱수 tenth
        }

        table4.emplace_back(4,14,24,34,54,64,74,84,94,41,42,43,44,45,46,47,48,49);

        for(int j=2; j<=tenth; j++){
            setupTable4(j);
        }
        
        auto it = find(table4.begin(), table4.end(), )
        printf("Case #%d: %d %d\n",i+1, j, num-j);
    }
    return 0;
}

int doesNotContain4(int n){
    int ten = 1;
    int cnt = 1, digit[20], flag = 1;
    
    while(ten*10 <= n){
        ten *= 10;
        cnt++;
    }
    // printf("cnt = %d, ten = %lld\n",cnt, ten);
    for(int i=0; i<cnt; i++){
        digit[i] = n / ten;
        n -= digit[i] * ten;

        ten /= 10;
    }

    for(int i=0; i<cnt; i++){
        // printf("%d ",digit[i]);
        if(digit[i] == 4){
            return false;
        }
    }
    // printf("\n");

    return true;
}
void setupTable4(int n){
    int num;
    int len = table4.size;

    // 거듭제곱 n
    for(int i=1; i<10; i++){
        for(int j=0; j<len; j++){
            int num = table4[j];
            num += tenEx(n) * i;    // num = num+ 10^n * i
            
            table4.push_back(num);
        }
    }
}
int tenEx(int n){
    int ten = 1;
    for(int i=0; i<n; i++){
        ten *= 10;
    }
    return ten;
}
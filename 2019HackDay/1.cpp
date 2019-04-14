// 주사위 굴려서 모두 같은 숫자 만드는 최소횟수

#include <iostream>
#include <vector>
using namespace std;

vector <int> A1;
vector <int> A2;
vector <int> A3;
int len;
int roll(int);
int main(void){
    int count[10]={0,}, min = 987654321;
    A1.push_back(1);
    A1.push_back(1);
    A1.push_back(6);
    // A1.push_back(3);
    len = A1.size();

    for(int i=1; i<=6; i++){
        count[i] = roll(i);
        if(count[i] < min)
            min = count[i];
        printf("%d ",count[i]);
    }
    printf("\nmin = %d",min);
    return 0;
}

int roll(int n){
    int sum = 0,num;
    for(int i=0; i<len; i++){
        num = A1[i];
        printf("%d ",num);
        if(num == 7 - n){
            sum += 2;
        }
        else if(num == n){
            continue;
        }
        else{
            sum += 1;
        }
    }
    printf("sum = %d\n",sum);
    return sum;
}
/*
Input
1 2 3

Output
2

Input
1 1 6
Output
2

Input
1 6 2 3

Output
3
*/
// winter와 summer로 쪼개는 문제
// winter의 모든 element는 summer의 element보다 작아야 함.
#include <iostream>
#include <vector>
using namespace std;

int B[] = {5, -2, 3, 8, 6};
int A[] = {-5, -5, -5, -42, 6, 12};
vector <int> A1(A, A + sizeof(A) / sizeof(int));

int main(void){
    int min, start = 0, end = 0;
    int len = A1.size();
    
    min = A1[len - 1];
    for(int i=len - 2; i>=0; i--){
        for(int j=i-1; j>=0; j--){
            
            if(A1[j] < min){
                min = A1[j];
                i = j;
                break;
            }
        }
    }
    return 0;
}
/*
Input
5 -2 3 8 6
Output
3

Input
-5 -5 -5 -42 6 12
Output
3
*/
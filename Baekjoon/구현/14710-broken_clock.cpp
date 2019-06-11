#include <iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int th1, th2;
    int flag;

    cin>> th1 >> th2;

    if(th2 % 12 == 0){
        if(th1%30 == th2 / 12)
            flag = 1;
        else
            flag = 0;
    }
    else
        flag = 0;

    if(flag)
        cout<<"O";
    else
        cout<<"X";
    return 0;
}
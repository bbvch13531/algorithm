#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

#define MAX 0x3f3f3f3f
#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"

using namespace std;

int main(void) {
    double C, F, X, prevAns=MAX;
    vector<double> vec, time_to_hire, acc_time_to_hire;
    acc_time_to_hire.push_back(0);

    cin >> C >> F >> X;

    vec.push_back(X / 2);

    int n = 0;
    while(1) {
        double cooking_time = X / (2+n*F);  // 사장+알바

        double chicken_pay = C / (2+n*F) ;
        // time_to_hire.push_back(chicken_pay);

        double next = acc_time_to_hire[n] + chicken_pay;
        acc_time_to_hire.push_back(next);

        if(n!=0){
            cout << cooking_time << " " << acc_time_to_hire[n] << "\n";
            double ans = cooking_time + acc_time_to_hire[n];
            if(ans > prevAns) {
                break;
            } else {
                prevAns = ans;
                vec.push_back(ans);
            }
        } else {
            prevAns = cooking_time;
            vec.push_back(cooking_time);
        }
        n++;
    }


    // for(double ele: vec) {
    //     printf("%.6lf\n", ele);
    // }
    printf("size = %d\n", vec.size());
    printf("%.6lf", vec.back());
    // for(double ele: acc_time_to_hire) {
    //     cout << ele << "\n";
    // }
    return 0;
}
/*

30.5 3.14159 1999.1999

*/
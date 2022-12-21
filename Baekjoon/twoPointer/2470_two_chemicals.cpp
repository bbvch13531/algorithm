#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> arr;
    int N, M, tmp;
    int l = 0, r;
    int minAbsVal = 0x7f7f7f7f;
    int minL, minR;
    cin >> N;
    r = N-1;

    for(int i=0; i<N; i++){
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());

    while(l<r) {
        int num = arr[l] + arr[r];
        if(abs(num) < minAbsVal) {
            minAbsVal = abs(num);

            minL = arr[l];
            minR = arr[r];
  
        }
        if(num < 0) {
            l++;
        } else {
            r--;
        }
    }

    cout << minL << " " << minR;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int arr[8010];

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector <int> vec, great;
    int N, tmp, mid;
    int sum=0, min = 5000, max = -1;
    double average=0;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> tmp;
        vec.push_back(tmp);
        sum += tmp;
        arr[tmp+4000]++;
    }
    int most=-1;
    
    for(int i=0; i<=8000; i++){
        if(arr[i] > most){
            most = arr[i];
        }
    }

    for(int i=0; i<=8000; i++){
        if(arr[i] == most){
                great.push_back(i-4000);
        }
    }

    average = (double) sum / N;
    average = round(average);
    
    sort(vec.begin(), vec.end());
    sort(great.begin(), great.end());

    max = vec[N-1];
    min = vec[0];
    mid = vec[N/2];

    if(great.size() == 1){
        most = great[0];
    } else {
        most = great[1];
    }
    cout << (int)average << " " << mid << " " << most << " " << max-min << endl;
    

    return 0;
}
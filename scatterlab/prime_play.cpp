#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

#define MAX_PRIME 3E6
#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"
#define ll long long
using namespace std;

int main(void) {
    int N, M, cnt=0;
    vector<ll> primes, acc_primes;
    cin >> N >> M;

    bool isPrime;
    for(ll n=2; n<=MAX_PRIME; n++) {
        isPrime = true;
        for(ll i=2; i*i<=n; i++){
            if(n%i == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime) primes.push_back(n);
    }
    acc_primes.push_back(0);
    for(int i=1; i<primes.size(); i++){
        acc_primes.push_back(acc_primes[i-1] + primes[i-1]);
    }
    // for(ll e:acc_primes) {
    //     cout << e <<"\n";
    // }
    cout << "----------------------\n";
    auto limit = lower_bound(primes.begin(), primes.end(), M);
    auto upper = lower_bound(acc_primes.begin(), acc_primes.end(), M);

    int s = 0;
    int e = upper - acc_primes.begin();
    cout << *limit << " " << *upper << "\n";
    cout << acc_primes[s] << " " << acc_primes[e] << "\n"; 


    while(1) {
        if(primes[e] > M) break;
        ll right = acc_primes[e];
        ll left = acc_primes[s];
        // cout << right << "( " << s << " ) - " << left << "( " << e << " )\n";
        if(right - left == M) {
            cnt++;
            e++;
        } else if(right - left < M) {
            e++;
        } else {
            s++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
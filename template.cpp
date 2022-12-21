#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <utility>
#include <tuple>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <limits>

#define debug1(x) cout << #x << " = " << x << "\n"
#define debug2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n"
#define debug3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n"
#define debug4(x,y,z,w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w <<"\n"
#define INF 0x33ffffff
#define ll long long
#define pii pair<int,int>

using namespace std;
// lower_bound
// set
struct comp {
    bool operator()(const int &lhs, const int &rhs){
        return lhs < rhs;
    }
};
//sort(vec.begin(), vec.end(), greater<int>());
void parseStr(string str, vector<string> &vec, string delimiter){
    int pos;
    string token;
    while((pos = str.find(delimiter)) != string::npos){
        token = str.substr(0, pos);
        vec.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    vec.push_back(str);
}

int main(){
    return 0;
}
// min
// max
// limit
// chaos
// even
// odd
// random big

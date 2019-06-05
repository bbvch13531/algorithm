#include <iostream>
#include <utility>
#include <queue>

using namespace std;

struct comp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

// bool operator < (struct node a, struct node b){
//     return a.val < b.val;
// }

pair<int, int> p1;
priority_queue<pair <int, int>, vector<pair<int, int> >, comp > pq;

// vector < pair <int, int>> ;

int V, E, K;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E >> K;

    for(int i=0; i<E; i++){

    }

    return 0;
}
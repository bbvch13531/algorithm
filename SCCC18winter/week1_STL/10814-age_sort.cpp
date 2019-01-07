#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef struct {
    int age;
    int idx;
    string name;
} AgeName;

bool compare(const AgeName &a, const AgeName &b){
    if(a.age < b.age) return true;
    else if(a.age == b.age) return a.idx < b.idx;
    else return false;
}
int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<AgeName> arr;
    int N;
    AgeName buf;

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>buf.age;
        cin>>buf.name;
        buf.idx = i;
        arr.push_back(buf);
    }
    sort(arr.begin(),arr.end(),compare);

    for(auto it=arr.begin(); it!=arr.end(); it++){
        AgeName output = *it;
        cout<<output.age<<" "<<output.name<<"\n";
    }
    return 0;
}
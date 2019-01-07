#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int N,M,buf;
    vector <int> arr,cmp;
    scanf("%d",&N);

    for(int i=0; i<N; i++){
        scanf("%d",&buf);
        arr.push_back(buf);
    }
    sort(arr.begin(),arr.end());
    scanf("%d",&M);
    for(int i=0; i<M; i++){
        scanf("%d",&buf);
        cmp.push_back(buf);
    }
    
    for(int i=0; i<cmp.size(); i++){
        // printf("cmp = %d, arr = %d\n",cmp[i],arr[i]);
        if( binary_search(arr.begin(), arr.end(), cmp[i]))
            printf("1\n");
        else
            printf("0\n");
    }

    return 0;
}

/*
5
4 1 5 2 3
5
1 3 7 9 5
*/
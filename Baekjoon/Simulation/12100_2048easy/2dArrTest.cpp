#include <cstdio>
#include <algorithm>
#include <iterator>
#include <cstring>

using namespace std;

void func1(int arr[][10]);
void printarr(int arr[][10]);
int main(void){
	int arr1[10][10]={0,};
	int arr2[10][10];
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			arr1[i][j] = 1;
		}
	}
//	copy(begin(arr1), end(arr1), begin(arr2));
	memcpy(arr2, arr1, sizeof(arr1));
	func1(arr1);

	printf("after func1\n");
	printarr(arr1);
	printarr(arr2);
	return 0;
}

void func1(int arr[][10]){
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			arr[i][j] = 2;
		}
	}
	printarr(arr);
}
void printarr(int arr[][10]){
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}

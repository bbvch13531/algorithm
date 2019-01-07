#include <cstdio>
using namespace std;
int main(){
	int row;
	for(int i=0; i<6; i++){
		for(int j=0; j<2; j++){
			row=i;
			if(i==5) row=1;
			for(int k=0; k<4-row; k++) printf(" ");
			for(int k=0; k<2*row+1; k++) printf("*");
			printf("\n");
		}
	}
	return 0;
}

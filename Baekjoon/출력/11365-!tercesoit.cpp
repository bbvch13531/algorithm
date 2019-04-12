#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string buf;
	int size;
	while(1){
		getline(cin,buf);
		if(buf.compare("END") == 0){
			break;
		}
		size = buf.size();
//		cout<<size<<" "<<buf<<"\n";
		for(int i=0; i<size; i++){
			cout<<buf[size-i-1];
		}
		cout<<"\n";
	}
//	cout<<buf<<"\n";
	return 0;
}

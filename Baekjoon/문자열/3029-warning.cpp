#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main(){
	string in1, in2;
	int t1[5], t2[5];
	int hh,mm,ss;

	cin >>in1 >> in2;
	sscanf(in1.c_str(), "%d:%d:%d", &t1[0],&t1[1],&t1[2]);
	sscanf(in2.c_str(), "%d:%d:%d", &t2[0],&t2[1],&t2[2]);

	if(t2[2] < t1[2]){ // 자리내림
		t2[1] -= 1;
		ss = t2[2] + 60 - t1[2];
	} else {
		ss = t2[2] - t1[2];
	}
	if(t2[1] < t1[1]){ // 자리내림
		t2[0] -= 1;
		mm = t2[1] + 60 - t1[1];
	} else {
		mm = t2[1] - t1[1];
	}
	if(t2[0] < t1[0]){ // 자리내림
		hh = t2[0] + 24 - t1[0];
	} else {
		hh = t2[0] - t1[0];
	}

	string h="",m="",s="";

	if(hh<10){
		h+="0";
		h.push_back('0'+hh);
	}else{
		h = to_string(hh);
	}
	if(mm<10){
		m+="0";
		m.push_back('0'+mm);
	} else {
		m = to_string(mm);
	}
	if(ss<10){
		s+="0";
		s.push_back('0'+ss);
	}else{
		s = to_string(ss);
	}

	if(hh+mm+ss == 0){
		cout<<"24:00:00";
	}else {
		cout << h << ":" << m <<":" <<s;
	}
	return 0;
}

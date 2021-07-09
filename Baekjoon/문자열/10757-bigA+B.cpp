// solved
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

pair<int,int> halfAdd(char a, char b, int c);
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string A, B, tmp, answer;

	cin >> A >> B;
	
	int lenA = A.length(), lenB = B.length();

	if(lenA > lenB){
		tmp = A;
		A = B;
		B = tmp;
	}

	// lenA < lenB always
	lenA = A.length(), lenB = B.length();
	
	// insert 0's to string A
	string zeros = string(lenB-lenA, '0');
	A = zeros + A;

//	cout << "string a = " << A << " string b = " << B <<endl;

	int res, carry=0;
	for(int i=0; i<lenB; i++){
		pair<int, int> p = halfAdd(A[lenB-1-i], B[lenB-1-i], carry);

		res = p.first;
		carry = p.second;

	//	cout << res << " " << carry << endl;
		answer.push_back('0'+res);
	}

	if(carry == 1)
		answer.push_back('1');
	string ans = string(answer.rbegin(), answer.rend());
	cout << ans;
	return 0;
}

pair<int, int> halfAdd(char a, char b, int c){

	int res=0, carry=0, sum;

	sum = ((a-'0') + (b-'0') + c);
	res = sum%10;
	carry = sum/10;

	return make_pair(res, carry);
	
	// return <res, carry>
}

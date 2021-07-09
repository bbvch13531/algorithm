#include <iostream>
#include <vector>

using namespace std;

void print_debug();

vector< vector<int> > vec;
int max_dp[4][100010], min_dp[4][100010];
int N;
int main(int argc, char** argv){
	cin >> N;

	for(int i=0; i<N; i++){
		vector <int> row;
		int score;
		for(int j=0; j<3; j++){
			cin >> score;
			row.push_back(score);
		}
		vec.push_back(row);
		
	}
	
	// init dp first row
	for(int i=0; i<3; i++)
		max_dp[0][i] = min_dp[0][i] = vec[0][i];

	// calc min_dp, max_dp
	for(int i=1; i<N; i++){
		max_dp[i][0] = max(max_dp[i-1][0], max_dp[i-1][1]) + vec[i][0];
		max_dp[i][1] = max(max(max_dp[i-1][0], max_dp[i-1][1]), max(max_dp[i-1][1], max_dp[i-1][2])) + vec[i][1];
		max_dp[i][2] = max(max_dp[i-1][1], max_dp[i-1][2]) + vec[i][2];

		min_dp[i][0] = min(min_dp[i-1][0], min_dp[i-1][1]) + vec[i][0];
		min_dp[i][1] = min(min(min_dp[i-1][0], min_dp[i-1][1]), min(min_dp[i-1][1], min_dp[i-1][2])) + vec[i][1];
		min_dp[i][2] = min(min_dp[i-1][1], min_dp[i-1][2]) + vec[i][2];
	}

//	print_debug();
	int max_ans = max(max(max_dp[N-1][0],max_dp[N-1][1]),  max(max_dp[N-1][1],max_dp[N-1][2]));
	int min_ans = min(min(min_dp[N-1][0],min_dp[N-1][1]),  min(min_dp[N-1][1],min_dp[N-1][2]));

	cout << max_ans << " " << min_ans;
	return 0;
}
void print_debug() {
	for(int i=0; i<N; i++){
		for(int j=0; j<3; j++){
			cout << max_dp[i][j] << " ";
		}
		cout <<"\n";
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<3; j++){
			cout << min_dp[i][j] << " ";
		}
		cout <<"\n";
	}

}

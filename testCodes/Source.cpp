#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int uniquePaths(int m, int n) {
	// we create a vector of mxn
	// we iterate through and add number of times we reach a node. 
	vector<vector<int>> visits(m, vector<int>(n, 0));
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			// we cannot go right past j's final value
			// we cannot go down in i's final value

			if (j == n - 1 && i == m - 1) {
				return visits[i][j];
			}
			else if (j == n - 1) {
				visits[i + 1][j] += visits[i][j] + 1;

			}
			else if (i == m - 1) {
				visits[i][j + 1] += visits[i][j] + 1;
			}
			else {
				visits[i + 1][j] += visits[i][j] + 1;
				visits[i][j + 1] += visits[i][j] + 1;
			}
		}
	}

	return visits[m - 1][n - 1];

}
int main() {

	int m = 0, n = 0;
	cin >> m >> n;
	cout << uniquePaths(m, n);

}
// Code to find the minimum edit distance
// cost of subbing, inserting and deleting are all 1
// Karthik Balaji Keshavamurthi

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// Function Declarations
int minEditDistance(const string& word1,const string& word2);
vector<vector<int>> create2Dvector(int m, int n);

// Main Function
int main() {

	string word1;
	string word2;

	cin >> word1 >> word2;
	cout << minEditDistance(word1, word2);
	
	return 0;
}

// Function Definitions
int minEditDistance(const string& word1,const string& word2) {
	int m = word1.length();
	int n = word2.length();
	// create a 2D array to hold the values
	vector<vector<int>> distance = create2Dvector(m, n);

	for (int i = 0; i <= m;i++) {
		for (int j = 0;j <= n;j++) {
			if (j == 0) {
				distance[i][j] = i;
			}
			else if (i == 0) {
				distance[i][j] = j;
			}
			else {
				// first subbing
				if (word1[i - 1] == word2[j - 1]){
						// we just use the diagonal element
					distance[i][j] = distance[i - 1][j - 1];
				}
				else {
					distance[i][j] = min(min(distance[i - 1][j], distance[i][j - 1]), distance[i - 1][j - 1]) + 1;
				}
			}
			
		}
	}
	
	
	return distance[m][n];
}

vector<vector<int>> create2Dvector(int m, int n) {
	vector<vector<int>> distance(m+1, vector<int>(n+1	, 0));

	return distance;
}
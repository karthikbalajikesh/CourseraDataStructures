// Code to find the minimum number or operations to arrive at number from 1
// Allowable operations are (x*3), (x*2) and (x+1)
// by Karthik Balaji Keshavamurthi

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// function declarations
vector<int> minWays(int);
void bestSequence(vector<int>&,vector<int>&, int n);
void display_vector(vector<int>&);

int main() {
	int n = 0;
	cin >> n;
	vector<int> bestways = minWays(n);
	cout << bestways.size() - 1<<endl;
	display_vector(bestways);
	return 0;
}

vector<int> minWays(int n) {
	vector<int> best(n + 1,2000000);
	vector<int> sequence;
	sequence.push_back(n);
	best[0] = 0;
	best[1] = 0;
	int temp = 2000000;
	for (int i = 2;i < n + 1;i++) {
		for (int j = 1;j <= 3;j++) {
			if (j == 1) {
			// this will be the division by 3 case
				if (i % 3 == 0) {
					temp = best[i / 3] + 1;
					
					best[i] = (temp < best[i]) ? temp:best[i];
				}
			}
			else if (j == 2) {
				if (i % 2 == 0) {
					temp = best[i / 2] + 1;
					best[i] = (temp < best[i]) ? temp : best[i];
				}
			}
			else {
				temp = best[i - 1] + 1;
				best[i] = (temp < best[i]) ? temp : best[i];
			}

		}
		
	}

	bestSequence(best, sequence, n);

	reverse(sequence.begin(), sequence.end());
	return sequence;

}

void bestSequence(vector<int>& best,vector<int>& sequence, int n) {
	int temp;

	if (n == 1) {
	
		return;
	}
	else {
		if ((n % 3 == 0) && (best[n] == (best[n / 3] + 1))) {
			sequence.push_back(n / 3);
			bestSequence(best, sequence, n / 3);
		}
		else if ((n % 2 == 0) && (best[n] == (best[n / 2] + 1))) {
			sequence.push_back(n / 2);
			bestSequence(best, sequence, n / 2);
		}
		else if (best[n] == best[n - 1] + 1) {
			sequence.push_back(n - 1);
			bestSequence(best, sequence, n - 1);
		}

		
	}

	return;

	

}

void display_vector(vector<int>& sequence) {
	for (auto x : sequence) {
		cout << x << " ";
	}
}
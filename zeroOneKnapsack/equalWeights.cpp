// The 0-1 Knapsack Problem with Equal Value Weight Ratio Solution
// Using Dynamic Programming
// we have to write the max weight that can fit this bag
// Karthik Balaji Keshavamurthi

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Function Declarations
vector<int> generateVector(int);
vector<vector<int>> generate2Dvector(int,int);
// This is the Recursive slow solution
int maxWeight(vector<int>&, int,int);
// This is the dynamic Programming Solution
int maxWeightDynamic(vector<int>&,int);


// Main Function
int main() {
	int capacity = 0, numElements = 0;
	cin >> capacity >> numElements;
	vector<int> weights = generateVector(numElements);
	cout << "\n"<<maxWeight(weights, capacity,numElements-1);
	cout << "\n" << maxWeightDynamic(weights, capacity);
	return 0;
}

// Function Definitions
vector<int> generateVector(int n) {
	vector<int> A;
	int temp;
	for (int i = 0; i < n;i++) {
		cin >> temp;
		A.push_back(temp);
	}
	return A;
}

vector<vector<int>> generate2Dvector(int numWeights, int capacity) {
	vector<vector<int>> data(numWeights , vector<int>(capacity + 1, 0));
	return data;
}

int maxWeight(vector<int>& weights, int capacity,int n) {

	if (capacity == 0) {
		return 0;
	}
	else {
		if (n == 0) {
			if (capacity == weights[n]) {
				return capacity;
			}
			else if (capacity < weights[n]) {
				return 0;
			}
			else {
				return weights[n];
			}


		}
		else {
			if (capacity == weights[n]) {
				return capacity;
			}
			else if (capacity < weights[n]) {
				return maxWeight(weights, capacity, n - 1);
			}
			else {

				return(max(maxWeight(weights, capacity, n - 1), weights[n] + maxWeight(weights, capacity - weights[n], n - 1)));
			}
		}
			
	}


	return 0;
}

int maxWeightDynamic(vector<int>& weights,int capacity) {
	vector<vector<int>> data = generate2Dvector(weights.size(), capacity);
	for (int i = 0;i < weights.size();i++) {
		for (int j = 0;j <= capacity;j++) {
			
			if (i == 0) {
				if (weights[i] <= j) {
					data[i][j] = weights[i];
				}
				
			}
			else {
				if (j < weights[i]) {
					if (j != 0) {
						data[i][j] = max(max(data[i - 1][j], data[i][j - 1]), data[i - 1][j - 1]);
					}
				}
				else {
					data[i][j] = max(weights[i] + data[i-1][j - weights[i]],data[i-1][j]);
				}
			}
		}
	}

	return data[weights.size() - 1][capacity];

}
// Code to calculate the minimum number of coins of 
// denomination 1,3 and 4
// max money(input) value is 1000
// Karthik Balaji Keshavamurthi

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// we declare functions here. 
// Recursive slow solution
int minCoinsRecursive(int money,vector<int>&);
// second is the dynamic programming approach
int minCoinsDynamic(int money,vector<int>&,vector<int>&);


int main() {

	int n; // total money
	cin >> n;
	vector <int> denominations = {1,3,4};
	// construct the money vector for Dynamic Solution
	vector<int> A(n + 1, 2000);
	A[0] = 0;
	cout << "\n" << minCoinsDynamic(n,A,denominations);
	return 0;

}

// Function Definitions
int minCoinsRecursive(int money,vector<int>& denominations) {
	
	// base case
	if (money == 0) {
		return 0;
	}
	else {
		int minCoins = 2000; // should be larger than the max input
		int temp = 0;
		for (int i = 0;i < denominations.size();i++) {
			if (denominations[i] <= money) {
 				temp = minCoinsRecursive(money - denominations[i],denominations);
				minCoins = (minCoins > (temp+1)) ? temp+1 : minCoins;
			}
		}
		return minCoins;
	}

	return 0;
}

int minCoinsDynamic(int money, vector<int>& A, vector<int>& denominations) {
	int temp;
	for (int i = 1; i < A.size();i++) {
		for (int j = 0;j < denominations.size();j++) {
			if (i >= denominations[j]) {
				temp = A[i - denominations[j]] + 1;
				A[i] = (A[i] > (temp)) ? temp : A[i];
			}
		}
		
	}

	return A[A.size()-1];
}
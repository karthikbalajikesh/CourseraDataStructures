//  Program to check for exact partitioning for 3 people
// Karthik Balaji Keshavamurthi

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Function Declarations
vector<int> constructVector(int);
// First the recursive solution
bool checksplit(vector<int>&, vector<int>, int n, int sum,int k);
bool checkSplit(vector<int>&, int k, int sum);

// main function
int main() {
	int numElements = 0;
	cin >> numElements;
	vector<int> objects = constructVector(numElements);
	
	return 0;
}

// Function Definitions
vector<int> constructVector(int n) {
	vector<int> A;
	int temp;
	for (int i = 0;i < n;i++) {
		cin >> temp;
		A.push_back(temp);
	}

	return A;
}

bool checkSplit(vector<int>& objects,int k,int sum) {
	// first create the 3 subset vector
	vector<int> slots(k, 0);
	return checksplit(objects, slots, objects.size(),sum,k);
	
}

bool checksplit(vector<int>& objects, vector<int> slots,int n, int sum,int k) {
	// check if the sum is splittable into others  
	// base case 1 : return false if sum is not separable into k subsets
	int overall_sum = 0,total = 0, sumslots = 0;
	for (int i = 0;i < objects.size();i++) {
		overall_sum += objects[i];
		if (i < k) {
			sumslots += slots[i];
		}
		if (i >= n) {
			total += objects[i];
		}
	}
	// base case 1: at start of recursion, check for remainder
	if (n == 0 && total == 0) {
		if (overall_sum% k != 0) {
			return false;
		}
	}
	if (n == objects.size()) {
		for (auto x : slots) {
			if (x)
		}
	}
	

}
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int binary_search(const vector<int>& a, int x) {
	// We will try an iterative algorithm for binary search
	int low = 0, high = a.size();
	int index = 0;
	int mid = a.size();
	int previous = a.size();
	while (high>low) {
		// check the median
		mid = (high + low) / 2;
		if (a[mid] == x) {
			return mid;
		}
		else if (a[mid] > x) {
			high = mid ;

		}
		else {
			low = mid+1;
		}
		

	}

	
	return -1;
}

int linear_search(const vector<int>& a, int x) {
	for (size_t i = 0; i < a.size(); ++i) {
		if (a[i] == x) return i;
	}
	return -1;
}

int main() {
	// Constructing the problem
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); i++) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i < m; ++i) {
		//replace with the call to binary_search when implemented
		std::cout << binary_search(a, b[i]) << ' ';
	}
}

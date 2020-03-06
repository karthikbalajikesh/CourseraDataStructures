// Code to return the nth value of a Fibonacci Series
#include<iostream>
#include<vector>

using namespace std;

long long fibo_naive(int n);

int main() {
	int num = 0;
	cin >> num;
	long long series = fibo_naive(num);
	// Display the number 
	cout << "\nF[" << num << "] = " << series << endl;

	return 0;
}

long long fibo_naive(int n) {
	vector<long long> fib;
	for (int i = 0;i <= n;i++) {

		if (i == 0) {
			fib.push_back(0);
		}
		else if (i == 1) {
			fib.push_back(1);
		}
		else {
			fib.push_back(fib[i - 1] + fib[i - 2]);
		}


	}
	return fib[n];
}





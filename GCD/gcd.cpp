#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

long long gcd_naive(long long n1, long long n2);
int main() {
	long long n1 = 1, n2 = 1;
	cout << "Enter the two Numbers: \t";
	cin >> n1 >> n2;
	cout << gcd_naive(n1, n2);

	return 0;
}

long long gcd_naive(long long n1, long long n2) {
	long long gcd = 0;
	// Algorithm, we are going to compare the two numbers and find the factors of the smaller number.
	// Before that, we check if the number itself is a factor. then it will be the gcd
	if (n1 < 1 || n2 < 1) {
		cout << "Invalid number";
		return 0;
	}
	if (n1 % n2 == 0 || n2 % n1 == 0) {
		gcd = (n1 < n2) ? n1 : n2;
		return gcd;
	}
	// Now we will iterate through the larger number
	long long temp = (n1> n2) ? n1 : n2;
	long long temp2 = (n1 < n2) ? n1 : n2;

	
	// we will iterate and store the factors of the larger value
	for (long long i =sqrt(temp2); i > 0; i--) {
		if ((temp % i == 0 )&&(temp2%i==0)) {
			gcd = i;
			return i;
		}
	}


	return gcd;
}
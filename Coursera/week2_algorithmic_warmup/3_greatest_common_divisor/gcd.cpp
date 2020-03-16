#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

long long int gcd_euclidian(long long int n1, long long int n2) {

	if (n2 == 0){
		return n1;

	}
	else {
		return gcd_euclidian(n2, n1 % n2);

	}

}

int main() {
  long long int a, b;
  std::cin >> a >> b;
  std::cout << gcd_euclidian(a, b) << std::endl;
  return 0;
}

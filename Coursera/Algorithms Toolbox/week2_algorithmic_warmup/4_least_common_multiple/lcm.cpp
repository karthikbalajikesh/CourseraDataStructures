#include <iostream>

 long long gcd_euclidian(long long n1, long long n2) {

	if (n2 == 0){
		return n1;

	}
	else {
		return gcd_euclidian(n2, n1 % n2);

	}

}

long long lcm_naive(long long a, long long b) {
  
  long long gcd = gcd_euclidian(a,b);
  return ((a*b)/gcd);
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}

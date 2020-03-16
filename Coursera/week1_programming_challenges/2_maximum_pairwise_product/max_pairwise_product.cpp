#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(std::vector<long long> numbers) {
    long long max_product = 0;
    long long n = numbers.size();

    sort(numbers.begin(),numbers.end());
	max_product = numbers[n-1]*numbers[n-2];

    return max_product;
}

int main() {
    long long n;
    std::cin >> n;
    std::vector<long long> numbers(n);
    for (long long i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}

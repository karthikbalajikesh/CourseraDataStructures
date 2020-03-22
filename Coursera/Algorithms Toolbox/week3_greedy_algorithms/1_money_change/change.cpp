#include <iostream>

int get_change(int m) {
	int num_coins=0;
	
  //First we find the number of coins of value 10
  num_coins = m/10;
  // now we reduce the problem 
  m=m%10;
  // Now we find the number of coins of value 5;
  num_coins = num_coins + (m/5);
  // Again we reduce the size of the problem
  // Final denomination left is num of value 1 coins
  num_coins = num_coins + (m%5);
  return num_coins;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

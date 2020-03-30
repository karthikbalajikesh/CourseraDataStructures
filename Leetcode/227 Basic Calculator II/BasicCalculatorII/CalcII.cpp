// Leetcode Problem number 227
// Basic Calculator 2
// Difficulty : Medium
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>

using namespace std;

long getResult(string input);

int main() {
	// setting up the problem
	string input;
	getline(cin, input);
	long result = getResult(input);
	cout << "\n" << getResult(input);
	return 0;
}

long getResult(string input) {
	long result = 0, temp = 0;
	long number = 0;
	char operation = '+';
	for (long i = 0; i < input.length();i++) {
		if (isdigit(input[i])) {
			// First step is extracting the complete number
			number = 0;
			while ((i < input.length()) && (isdigit(input[i]))) {
				number = (number * 10) + (input[i] - '0');
				i++;
			}
			// Now we have extracted a number
			if (operation == '+') {
				result = result + temp;
				temp = number;
			}
			else if (operation == '-') {
				result = result + temp;
				temp = number*(-1);
			}else if (operation == '*') {
				temp *= number;
			}
			else {
				temp /= number;
			}
		}
		else {
			if (input[i] != ' ') {
				operation = input[i];
			}
		}
	}
	result += temp;

	return result;
}
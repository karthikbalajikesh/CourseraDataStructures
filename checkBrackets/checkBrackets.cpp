// We are going to be using the STL object stack to implement 
// the check balanced paranthesis problem

#include<iostream>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;

// Function Declaration
void checkBrackets(string& input);
void printoutput(string& input, int index, stack<int>);
// Main function
int main() {
	string input;
	cin >> input;
	checkBrackets(input);
	
}

void checkBrackets(string& input) {
	int index = 1;
	stack<int> brackets;
	for (int i = 0; i < input.length(); i++) {
		if (((input[i] == '{') || (input[i] == '[')) || (input[i] == '(')) {
			brackets.push(i);
		}
		if (((input[i] == '}') || (input[i] == ']')) || (input[i] == ')')) {
			if (brackets.empty()) {
				printoutput(input, index, brackets);
				return;
			}
			if ((input[i] == '}') && (input[brackets.top()] != '{')) {
				printoutput(input, index,brackets);
				return;
			}
			if ((input[i] == '}') && (input[brackets.top()] == '{')) {
				brackets.pop();
				
			}
			if ((input[i] == ']') && (input[brackets.top()] != '[')) {
				printoutput(input, index,brackets);
				return;
			}
			if ((input[i] == ']') && (input[brackets.top()] == '[')) {
				brackets.pop();
				
			}
			if ((input[i] == ')') && (input[brackets.top()] != '(')) {
				printoutput(input, index,brackets);
				return;
			}
			if ((input[i] == ')') && (input[brackets.top()] == '(')) {
				brackets.pop();
				
			}

		}

		index++;
	}
	printoutput(input, index,brackets);
	return;
}


	void printoutput(string & input, int index,stack<int> brackets) {
		if (index > input.length()) {
			if (brackets.empty()) {
				cout << "Success";
			}
			else {
				cout << brackets.top()+1;
			}
		}
		else {
			cout << index;
		}

	}
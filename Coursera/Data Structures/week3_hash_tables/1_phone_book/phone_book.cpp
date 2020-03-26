// Karthik Balaji Keshavamurthi - 3/25/2019
// PhoneBook API that performs the following operation:
// Add a number to the phone book
// Delete a number from the phonebook
// Find the name associated with the number

// We will use Hash map to perform this operation

#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;


// construct a class for the Phonebook
class Phonebook {
private:
	map<int, string> PhoneBook;
public:
	Phonebook() {
		// Empty constructor
	}
	void AddtoPhonebook(int n,string s1) {
		PhoneBook[n] = s1;
	}
	void DeletefromPhonebook(int n) {
		auto it = PhoneBook.find(n);
		if (it != PhoneBook.end()) {
			PhoneBook.erase(n);
		}
	}
	string findEntry(int n) {
		auto it = PhoneBook.find(n);
		if (it != PhoneBook.end()) {
			return PhoneBook[n];
		}
		else {
			return "not found";
		}
	}

	void SolveQueries() {
		vector<string> results;
		int numQueries = 0;
		int number = 0;
		string operation;
		string name;
		cin >> numQueries;
		for (int query = 0; query < numQueries;query++) {
			cin >> operation;
			if (operation == "find") {
				cin >> number;
				results.push_back(findEntry(number));
			}
			else if (operation == "add") {
				cin >> number >> name;
				AddtoPhonebook(number, name);

			}
			else if (operation == "del") {
				cin >> number;
				DeletefromPhonebook(number);
			}
		}
		publishResult(results);

	}

	void publishResult(vector<string> results) {
		for (int i = 0; i < results.size();i++) {
			cout << results[i] << endl;
		}
	}
};

int main() {
	Phonebook book1;
	book1.SolveQueries();
	return 0;
}

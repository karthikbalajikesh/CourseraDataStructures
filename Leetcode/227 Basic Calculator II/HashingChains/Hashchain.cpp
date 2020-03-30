#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;


class ChainedHash {
private:
	unsigned int p;
	int x;
	int m;
public:
	// attributes
	vector<vector<string>> Hash;
	// methods;
	// default constructor
	/*ChainedHash(int n);
	int getHashValue(string&);
	void addString(string&);
	void delString(string&);
	void findString(string&);
	void checkString(int&);
	void SolveQueries();
	void displayVector(vector<string>);*/

	// definitions

	// Default Constructor
	ChainedHash(int n) :p{ 1000000007 }, x{ 263 }, m{n} {
		vector<vector<string>> temp(m);
		Hash = temp;
	}

	// Function to display vector
	void displayVector(vector<string> A) {
		reverse(A.begin(), A.end());
		for (auto x : A) {
			cout << x<<" ";
		}
		cout << endl;
	}

	// Hashing function
	unsigned int getHashValue(string& data) {
		int letter;
		
		unsigned int result=0;
		size_t temp;
		for (int i = data.length()-1;i >=0;i--) {
			letter = int(data[i]);
			temp = ((result * x) + letter) % p;
			result = temp;
		}
		result = result % m;
		return result;
	}

	// Adding string
	void addString(string& data) {
		// step 1: compute hash value
		unsigned int hashIndex = getHashValue(data);
		// now we check if the string is already present in the array
		vector<string> bucket = Hash[hashIndex];
		auto it = find(bucket.begin(), bucket.end(), data);
		if (it == bucket.end()) {
			// if string is not present, add
			Hash[hashIndex].push_back(data);
		}
		// else do nothing. Hence no code
	}
	
	// deleting string
	void delString(string& data) {
		// step 1: Compute Hash value
		unsigned int hashIndex = getHashValue(data);
		// now we check if the string is already present in the array
		vector<string> bucket = Hash[hashIndex];
		auto it = find(bucket.begin(), bucket.end(), data);
		if (it != bucket.end()) {
			bucket.erase(it);
		}
		Hash[hashIndex] = bucket;
	}

	// finding is a string is present or not
	void findString(string& data) {
		// step 1: Compute Hash Value
		unsigned int hashIndex = getHashValue(data);
		// Now we check if the string is present
		vector<string> bucket = Hash[hashIndex];
		auto it = find(bucket.begin(), bucket.end(), data);
		if (it != bucket.end()) {
			cout << "yes"<<endl;

		}
		else {
			cout << "no" << endl;
		}
	}

	// checking for the values at a bucket
	void checkString(int& n) {
		vector<string> bucket = Hash[n];
		displayVector(bucket);
	}

	void SolveQueries() {
		int numQueries = 0;
		int n;
		cin >> numQueries;
		string temp;
		for (int i = 0; i < numQueries;i++) {
			cin >> temp;
			if (temp == "add") {
				cin >> temp;
				addString(temp);
			}
			else if (temp == "del") {
				cin >> temp;
				delString(temp);
			}
			else if (temp == "find") {
				cin >> temp;
				findString(temp);
			}
			else if (temp == "check") {
				cin >> n;
				checkString(n);
			}
			else {
				cout << "error" << endl;
			}
		}
	}


};

// Main Function
int main() {
	int numBuckets;
	
	cin >> numBuckets;
	ChainedHash Hash1(numBuckets);
	Hash1.SolveQueries();
	return 0;
}


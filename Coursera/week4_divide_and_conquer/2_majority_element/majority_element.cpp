#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
// the fastest solution can be obtained using maps

int findMajority(vector<int>& votes) {
	int majority_value = votes.size() / 2;
	map<int, int> entries;
	for (int i = 0;i<votes.size();i++) {
		// initialize all the entries of the map
		entries[votes[i]] = 0;
	}
	for (int i = 0;i<votes.size();i++) {
		// initialize all the entries of the map
		entries[votes[i]]++;
		if (entries[votes[i]] >(votes.size()/2)) {
			return 1;
		}
	}

	return 0;
}

int main() {
	// we construct the problem here
	int n=0;
	cin >> n;
	int temp;
	vector<int> votes;
	for (int i = 0; i < n;i++) {
		cin >> temp;
		votes.push_back(temp);
	}

	cout << findMajority(votes);// we should only print whether majority occurs or not
}
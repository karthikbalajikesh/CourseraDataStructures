#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
	double value = 0.0;
	// for greedy algorithm, we need to reduce the problems at every step
	// First we compute the value to weight ratio.
	vector <double> ratio;
	map <double, int> index;
	double temp = 0.0;
	for (int i = 0; i < weights.size();i++) {
		temp = (((double)(values[i]))/((double) weights[i]));
		ratio.push_back(temp);
		index[temp] = i;

	}
	sort(ratio.begin(), ratio.end());
	reverse(ratio.begin(), ratio.end());

	for (int i = 0; i < ratio.size();i++) {
		if (capacity == 0) {
			return value;
		}
		if ((capacity - weights[index[ratio[i]]]) >= 0) {
			// This is the case when whole item can be used
			value = value + ((double)(values[index[ratio[i]]]));
			capacity = capacity - weights[index[ratio[i]]];
		}
		else {
			// This is when we need a fraction of the item
			temp = ((double)(capacity)) / ((double)(weights[index[ratio[i]]]));
			value = value + ((double)(values[index[ratio[i]]] * temp));
			capacity = 0.0;
		}

	}


	return value;
}

int main() {
	int n;
	double capacity;
	cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++) {
		cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	cout.precision(10);
	cout << optimal_value << std::endl;
	return 0;
}

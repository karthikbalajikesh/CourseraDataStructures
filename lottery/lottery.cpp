#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
	vector<int> cnt(points.size());
	// lets create a map object to hold values.
	int n = starts.size();
	int m = points.size();
	int temp = (n > m) ? n : m;
	map<int, string> entries;
	for (int i = 0;i < temp;i++) {
		if (i < n) {
			entries[starts[i]] = "start";
			entries[ends[i]] = "end";
		}
		if (i < m) {
			entries[points[i]] = "point";
		}
	}
	//write your code here
	for (auto x : entries) {
		cout << x.second<<endl;
	}
	return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
	vector<int> cnt(points.size());
	for (size_t i = 0; i < points.size(); i++) {
		for (size_t j = 0; j < starts.size(); j++) {
			cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
		}
	}
	return cnt;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	vector<int> starts(n), ends(n);
	for (size_t i = 0; i < starts.size(); i++) {
		std::cin >> starts[i] >> ends[i];
	}
	vector<int> points(m);
	for (size_t i = 0; i < points.size(); i++) {
		std::cin >> points[i];
	}
	//use fast_count_segments
	vector<int> cnt = fast_count_segments(starts, ends, points);
	//for (size_t i = 0; i < cnt.size(); i++) {
		//std::cout << cnt[i] << ' ';
	//}
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class HeapBuilder {
private:
	vector<int> data_;
	vector< pair<int, int> > swaps_;

	void WriteResponse() const {
		cout << swaps_.size() << "\n";
		for (int i = 0; i < swaps_.size(); ++i) {
			cout << swaps_[i].first << " " << swaps_[i].second << "\n";
		}
	}

	void ReadData() {
		int n;
		cin >> n;
		data_.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> data_[i];
	}

	void GenerateSwaps() {
		swaps_.clear();
		// The following naive implementation just sorts 
		// the given sequence using selection sort algorithm
		// and saves the resulting sequence of swaps.
		// This turns the given array into a heap, 
		// but in the worst case gives a quadratic number of swaps.
		//
		// TODO: replace by a more efficient implementation
		for (int i = 0; i < data_.size(); ++i)
			for (int j = i + 1; j < data_.size(); ++j) {
				if (data_[i] > data_[j]) {
					swap(data_[i], data_[j]);
					swaps_.push_back(make_pair(i, j));
				}
			}
	}

	void siftDown(int index) {
		// if the size does not exceed the end of the array
		while ((2 * index) + 2 <= data_.size()) {
			// There are two conditions here. When the last parent has only one child and when it has two children

			// case 1: two children
			if ((2 * index) + 2 < data_.size()) {

				if ((data_[index] >= data_[(2 * index) + 1]) && (data_[index] >= data_[(2 * index) + 2])) {
					// when both the children are smaller values, swap with the smaller of the two..
					if (data_[(2 * index) + 1] >= data_[(2 * index) + 2]) {
						// if the right node is smaller,
						swap(data_[(2 * index) + 2], data_[index]);
						swaps_.push_back(make_pair(index, (2 * index) + 2));
						index = (2 * index) + 2;
					}
					else {
						// if the left node is smaller,
						swap(data_[(2 * index) + 1], data_[index]);
						swaps_.push_back(make_pair(index, (2 * index) + 1));
						index = (2 * index) + 1;
					}
				}
				else if ((data_[index] >= data_[(2 * index) + 1])) {
					// only left node is smaller
					swap(data_[(2 * index) + 1], data_[index]);
					swaps_.push_back(make_pair(index, (2 * index) + 1));
					index = (2 * index) + 1;
				}
				else if ((data_[index] >= data_[(2 * index) + 2])) {
					// only right node is smaller
					swap(data_[(2 * index) + 2], data_[index]);
					swaps_.push_back(make_pair(index, (2 * index) + 2));
					index = (2 * index) + 2;
				}
				else {
					// if it satisfies, keep moving forward
					index = (2 * index) + 2;
				}
			}
			else {
				// case 2: Only 1 Child
				// This occurs only when 2*index + 2 == data_.size()
				if (data_[index] >= data_[(2 * index) + 1]){
					swap(data_[(2 * index) + 1], data_[index]);
					swaps_.push_back(make_pair(index, (2 * index) + 1));
					index = (2 * index) + 1;
					}
				else {
					index = (2 * index) + 1;
				}
			}

			
		}
	}

	void GenerateSwapsFast() {
		swaps_.clear();
		for (int i = (data_.size() - 1) / 2; i >= 0; i--) {
			siftDown(i);
		}




	}

public:
	void Solve() {
		ReadData();
		GenerateSwapsFast();
		WriteResponse();
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	HeapBuilder heap_builder;
	heap_builder.Solve();
	return 0;
}

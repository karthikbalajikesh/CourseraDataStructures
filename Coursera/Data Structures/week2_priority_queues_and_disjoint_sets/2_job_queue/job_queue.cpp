#include <iostream>
#include <vector>
#include<queue>
#include <algorithm>

using namespace std;

class Thread {
public:
	int id;
	long long timeofCompletion;

	Thread(int n) :id{ n }, timeofCompletion{ 0 } {
		// constructor
	}
};

// we need a class for the priority queue compare.
class CompareThreads {
public:
	bool operator()(const Thread& A, const Thread& B) const{
		// first we have to check their time of completion
		if (A.timeofCompletion == B.timeofCompletion) {
			// if same, return the smaller id number
			return A.id > B.id;
		}
		else {
				return A.timeofCompletion>B.timeofCompletion;
		}
		
		
	}

};

class JobQueue {
private:
	int num_workers_;
	vector<int> jobs_;

	vector<int> assigned_workers_;
	vector<long long> start_times_;

	void WriteResponse() const {
		for (int i = 0; i < jobs_.size(); ++i) {
			cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
		}
	}

	void ReadData() {
		int m;
		cin >> num_workers_ >> m;
		jobs_.resize(m);
		for (int i = 0; i < m; ++i)
			cin >> jobs_[i];
	}

	void AssignJobs() {
		// TODO: replace this code with a faster algorithm.
		assigned_workers_.resize(jobs_.size());
		start_times_.resize(jobs_.size());
		vector<long long> next_free_time(num_workers_, 0);
		for (int i = 0; i < jobs_.size(); ++i) {
			int duration = jobs_[i];
			int next_worker = 0;
			for (int j = 0; j < num_workers_; ++j) {
				if (next_free_time[j] < next_free_time[next_worker])
					next_worker = j;
			}
			assigned_workers_[i] = next_worker;
			start_times_[i] = next_free_time[next_worker];
			next_free_time[next_worker] += duration;
		}
	}

	void AssignJobsFast() {
		// using a min heap will be beneficial. 
		// first we build the heap from the vector
		// Next we extract the root and we employ changePriority() method to push it back
		// based on the time of completion. 
		// If the time of completion is the same, then we check the thread number and use the smaller. 

		// The process can be done faster using the std::priority_queue.
		// We can create a compare function to do the required tasks. 
		assigned_workers_.resize(jobs_.size());
		start_times_.resize(jobs_.size());
		Thread temp(0);
		priority_queue <Thread, vector<Thread>, CompareThreads> queue;
		for (int i = 0; i < num_workers_; i++) {
			queue.push(Thread(i));
		}
		for (int i = 0;i < jobs_.size();i++) {
			// first we extract the top thread.
			temp = queue.top();
			// assign values in the result vectors, i.e the id and toc
			assigned_workers_[i] = temp.id;
			start_times_[i] = temp.timeofCompletion;
			// then we pop the values
			queue.pop();
			// we add the time taken to finish current task
			temp.timeofCompletion += jobs_[i];
			// we push the Thread back into queue.
			queue.push(temp);

		}
		
	}

public:
	void Solve() {
		ReadData();
		AssignJobsFast();
		WriteResponse();
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	JobQueue job_queue;
	job_queue.Solve();
	return 0;
}
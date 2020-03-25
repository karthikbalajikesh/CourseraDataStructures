#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

// Function Declarations
vector<vector<int>> construct2Dvector(int);
bool checkQueue(queue<int>&, int,int);
bool checkQueue(vector<vector<int>>& Inputs, vector<int>& result, int& currentTime, int& index, queue<int>& Queue, int BufferSize);
vector<int> getProcessResult(vector<vector<int>>, int, int);
void clearQueue(vector<vector<int>> Input, queue<int>& Queue, vector<int>& result, int& currentTime, int& index);
void clearQueueEnd(vector<vector<int>> Input, queue<int>& Queue, vector<int>& result, int& currentTime);
void displayVector(vector<int>);

int main() {
	int BufferSize = 0;
	int numInputs = 0;
	cin >> BufferSize >> numInputs;
	vector<vector<int>> Inputs = construct2Dvector(numInputs);
	displayVector(getProcessResult(Inputs, BufferSize, numInputs));
	return 0;
}

vector<vector<int>> construct2Dvector(int N) {
	// Create an nx2 2d Vector of values 0
	vector<vector<int>> Inputs(N, vector<int>(2, 0));
	for (int i = 0; i < N; i++) {
		cin >> Inputs[i][0] >> Inputs[i][1];
	}
	return Inputs;
}

bool checkQueue(queue<int>& Queue, int BufferSize, int inputIndex) {
	// Function will discard inputs if Queue is full. 
	// If not it will be added to the queue

	if (Queue.size() == BufferSize) {
		return false;
	}
	else {
		Queue.push(inputIndex);
		return true;
	}

}

vector<int> getProcessResult(vector<vector<int>> Input, int BufferSize, int numInputs) {
	if (BufferSize == 0) {
		vector<int> dummy;
		return dummy;
	}
	vector<int> result(numInputs, -1);
	if (numInputs == 0) {
		return result;
	}
	bool temp = true;
	int currentTime = 0;
	queue<int> Queue;
	int index = 0;
	for (int i = 0; i < numInputs;i++) {
		if (i == 0) {
			currentTime = Input[i][0];
			temp = checkQueue(Queue, BufferSize, i);
			if (!temp) {
				continue;
			}
			else {
				result[i] = currentTime;
			}
		}
		else {
			if(Queue.empty()){
				currentTime = max(currentTime,Input[i][0]);
				result[i] = currentTime;
				temp = checkQueue(Queue, BufferSize, i);
			}else {

				// if the Queue is not empty
				if (Input[i][0] < (currentTime + Input[Queue.front()][1])) {
					// This is when an element is entering when the current element is being processed
					temp = checkQueue(Queue, BufferSize, i);
					if (!temp) {
						continue;
					}
				}
				else if ((Input[i][0] >= (currentTime + Input[Queue.front()][1]))) {
					// if the element is entering just when the current element has completed processing
					clearQueue(Input, Queue, result, currentTime, i);
					temp = checkQueue(Input, result, currentTime, i, Queue, BufferSize);

				}
			}

		}
	}

	clearQueueEnd(Input, Queue, result, currentTime);
	return result;
}
bool checkQueue(vector<vector<int>>& Inputs,vector<int>& result, int& currentTime, int& index, queue<int>& Queue, int BufferSize) {
	if (index != 0) {
		if (Queue.empty()) {
			currentTime = max(currentTime, Inputs[index][0]);
			Queue.push(index);
			result[index] = currentTime;
			return true;
		}
		else {
			return checkQueue(Queue, BufferSize, index);
		}
	}
}

void clearQueue(vector<vector<int>> Input, queue<int>& Queue, vector<int>& result, int& currentTime, int& index) {
	while ((!Queue.empty()) && (Input[index][0] >= currentTime + Input[Queue.front()][1])) {
		currentTime += Input[Queue.front()][1];
		Queue.pop();
		if (Queue.empty()) {
			
			break;
		}
		result[Queue.front()] = currentTime;

	}
}

void clearQueueEnd(vector<vector<int>> Input, queue<int>& Queue, vector<int>& result, int& currentTime) {
	while (!Queue.empty()) {
		currentTime += Input[Queue.front()][1];
		Queue.pop();
		if (Queue.empty()) {
			break;
		}
		result[Queue.front()] = currentTime;
	}
}

void displayVector(vector<int> result) {
	for (auto x : result) {
		cout << x<<endl;
	}
}
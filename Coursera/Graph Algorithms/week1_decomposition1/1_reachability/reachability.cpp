#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Graph {
	vector<vector<int>> Adjacency_list;

public:
	void formGraph() {
		int numVertices = 0;
		int numEdges = 0;
		int temp1 = 0;
		int temp2 = 0;
		cin >> numVertices >> numEdges;
		vector<vector<int>> temp(numVertices);
		Adjacency_list = temp;
		// now we form the edges
		for (int i = 0;i < numEdges;i++) {
			cin >> temp1 >> temp2;
			Adjacency_list[temp1 - 1].push_back(temp2 - 1);
			Adjacency_list[temp2 - 1].push_back(temp1 - 1);
		}
		return;
	}

	int checkExit(int origin, int destination) {
		vector<bool> visited(Adjacency_list.size(), false);
		visited[origin - 1] = true;
		int numPaths = 0;

		checkExit(origin, destination, visited, numPaths);
		return numPaths;
		
	}

	void checkExit(int origin, int destination, vector<bool>& visited, int& numPaths) {
		if (origin == destination) {
			return;
		}
		for (auto x : Adjacency_list[origin]) {
			if (x==destination-1){
				numPaths++;
				visited[destination - 1] = true;
			}
			else {
				if (visited[x] == false) {
					visited[x] = true;
					checkExit(x, destination, visited, numPaths);
				}
			}
		}
	}


};

int main() {
	Graph A1;
	A1.formGraph();
	int source = 0, destination = 0;
	cin >> source >> destination;
	cout<<A1.checkExit(source, destination);
	return 0;
}
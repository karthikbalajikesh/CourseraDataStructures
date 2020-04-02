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
		int x;
		if (origin == destination) {
			return;
		}
		for (int i = 0;i < Adjacency_list[origin - 1].size();i++) {
			x = Adjacency_list[origin - 1][i];
			if (x == destination - 1) {
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

	int connectedComponents() {
		vector<bool> visited(Adjacency_list.size(), false);
		int CC = 0;
		for (int i = 0;i < Adjacency_list.size();i++) {
			if (visited[i] == false) {
				CC++;
				connectedComponents(visited,i);
			}

		}
		return CC;
	}

	void connectedComponents(vector<bool>& visited, int index) {
		visited[index] = true;
		for (int i = 0;i < Adjacency_list[index].size();i++) {
			if (visited[Adjacency_list[index][i]] == false) {
				connectedComponents(visited, Adjacency_list[index][i]);
			}
			
		}

	}


};

int main() {
	Graph A1;
	A1.formGraph();
	
	cout << A1.connectedComponents();
	return 0;
}
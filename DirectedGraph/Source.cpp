// Implementation of all Directed Graph Problems
// Karthik Balaji Keshavamurthi

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>


using namespace std;

class DirectedGraph {
	vector<vector<int>> Adjacency_list;
	vector<vector<int>> Reverse_list;

public:
	void formGraph() {
		int numVertices = 0, numEdges = 0;
		cin >> numVertices >> numEdges;
		int temp1 = 0, temp2 = 0;
		vector<vector<int>> temp(numVertices);
		Adjacency_list = temp;
		Reverse_list = temp;
		for (int i = 0; i < numEdges; i++) {
			cin >> temp1 >> temp2;
			Adjacency_list[temp1 - 1].push_back(temp2 - 1);
			Reverse_list[temp2 - 1].push_back(temp1 - 1);
		}
	}

	void checkCycle(set<int>& white, set<int>& gray, set<int>& black,
		bool& has_cycle, int index) {
		// If cycle is already true, do not execute
		if (has_cycle) {
			return;
		}
		// check if the current element is being explored for the first time
		auto it = find(white.begin(), white.end(), index);
		if (it == white.end()) {
			// if not for the first time, check if it is gray
			// if gray, change cycle to 1
			auto iterator = find(gray.begin(), gray.end(), index);
			if (iterator != gray.end()) {
				has_cycle = true;
			}
		}
		else {
			// if it is in the white list, remove it and add it gray
			white.erase(index);
			gray.insert(index);
			for (int i = 0;i < Adjacency_list[index].size();i++) {
				// check for the vertices connected to the given edge.
				// then remove it from gray and add to black.
				checkCycle(white, gray, black, has_cycle, Adjacency_list[index][i]);
				gray.erase(Adjacency_list[index][i]);
				black.insert(Adjacency_list[index][i]);
			}
			
		}
	}
	
	bool checkCycle() {
		bool has_cycle = false;
		set<int> white; // Yet to be visited
		set<int> gray; // currently being visited
		set<int> black; // completed elements
		// we first insert the elements into the set.
		for (int i = 0;i < Adjacency_list.size();i++) {
			white.insert(i);
		}

		for (int i = 0; i < Adjacency_list.size();i++) {
			checkCycle(white, gray, black,has_cycle, i);
		}

		return has_cycle;
		
	}

	// Linear Ordering
	vector<int> LinearOrder() {
		vector<int> order;
		vector<bool> visited(Adjacency_list.size(), false);

		for (int i = 0;i < Adjacency_list.size();i++) {
			LinearOrder(order, visited, i);
		}

		reverse(order.begin(),order.end());
		displayGraph(order);

		return order;
	}

	void LinearOrder(vector<int>& order, vector<bool>& visited, int index) {
		if (visited[index]) {
			return;
		}
		else {
			//keep iterating till you find the sink. 
			visited[index] = true;
			for (int i = 0;i < Adjacency_list[index].size();i++) {
				LinearOrder(order, visited, Adjacency_list[index][i]);
			}
			order.push_back(index + 1);
			
		}
	}


	void displayGraph(vector<int> order) {
		cout << endl;
		for (int i = 0;i < order.size();i++) {
			cout << order[i] << " ";
		}
	}

	vector<vector<int>> StronglyConnectedComponents() {
		// we need to pass and add things to the stack. 
		vector<vector<int>> Connect;
		stack<int> meta;
		vector<bool> visited(Adjacency_list.size(), false);
		
		// first pass
		for (int i = 0;i < Adjacency_list.size();i++) {
			DFS(visited, meta, i);
		}
		// reset visited to false
		for (auto x : visited) {
			x = false;
		}
		int index;
		
		while (!meta.empty()){
			index = meta.top();
			meta.pop();
			if (!visited[index]) {
				Connect.push_back({});
			}
			ConnectedComponents(Connect,visited,index);
		}
		

		return Connect;
		
	}

	void ConnectedComponents(vector<vector<int>>& Connect, vector<bool>& visited, int index) {
		if (visited[index]) {
			return;
		}
		else {
			visited[index] = true;
			// DFS
			for (int i = 0;i < Reverse_list[index].size();i++) {
				ConnectedComponents(Connect, visited, Reverse_list[index][i]);
			}
			Connect[(Connect.size() - 1)].push_back(index);

		}
	}

	void DFS(vector<bool>& visited,stack<int>& meta,int index) {
		if (visited[index]) {
			return;
		}
		else {
			visited[index] = true;
			for (int i = 0;i < Adjacency_list[index].size();i++) {
				DFS(visited, meta, Adjacency_list[index][i]);
			}
			meta.push(index);
		}
	}

	
};


int main() {
	DirectedGraph D1;
	D1.formGraph();
	vector<vector<int>> components = D1.StronglyConnectedComponents();
	cout << components.size();

	return 0;
}
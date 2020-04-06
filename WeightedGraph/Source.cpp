// Code to implement Shortest Path on Directed Weighted Graphs
// using Dijkstra's Algorithm

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;
// Define all Aliases
typedef pair<int, int> pi;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef priority_queue<pi, vector<pi>, greater<pi>> Queue;
#define mp make_pair


class WeightedGraph {
	vector<vector<pi>> Adjacency_list;
	vector<vector<pi>> Reverse_list; // Needed for Bidirectional Algorithms
	int numVertices, numEdges;
public:
	WeightedGraph() {
		cin >> numVertices >> numEdges;
		vector<vector<pi>> temp(numVertices);
		Adjacency_list = temp;
		Reverse_list = temp;
		int temp1, temp2, weight;
		for (int i = 0;i < numEdges;i++) {
			cin >> temp1 >> temp2 >> weight;
			Adjacency_list[temp1 - 1].push_back(mp(temp2-1,weight));
			Reverse_list[temp2 - 1].push_back(mp(temp1 - 1, weight));

		}
		
		return;

	}
	// Using normal Dijkstras to get shortest path
	int shortestDistance(int node1, int node2) {
		vector<int> previous(numVertices, 0);
		vector<int> distance(numVertices, INT_MAX);
		int source = node1 - 1, dest = node2 - 1;
		int length = 0;
		int index = 0;
		
		priority_queue<pi, vector<pi>, greater<pi>> Heap;
		// Add source to the Heap with length 0
		Heap.push(mp(0, source));
		distance[source] = 0;
		previous[source] = -1;

		while (!Heap.empty()) {
			index = Heap.top().second;
			length = Heap.top().first;
			Heap.pop();
			for (int i = 0;i < Adjacency_list[index].size();i++) {
				// iterate over the edges.
				// Add element to queue
				// check if distance is more than in the array
				if ((length + Adjacency_list[index][i].second) < distance[Adjacency_list[index][i].first]) {
					Heap.push(mp(length + Adjacency_list[index][i].second, Adjacency_list[index][i].first));
					distance[Adjacency_list[index][i].first] = length + Adjacency_list[index][i].second;
					previous[Adjacency_list[index][i].first] = index;
				}
			}

			
		}
		length = (distance[dest]==INT_MAX) ? -1 : distance[dest];
		// you will have to revert the path using a new function that backtracks until 
		// previous[index] is -1.
		return length;
	}

	bool checkNegativeCycle() {
		vector<int> previous(numVertices, 0);
		vector<int> distance(numVertices, INT_MAX);
		vector<bool> visited(numVertices, false);
		bool change = false;
		queue<int> Nodes;
		int n = 0;		
		int index = 0, length = 0;
		while (n < numVertices) {
			// first we go through all the nodes
			for (int i = 0; i < numVertices; i++) {
				if (!visited[i]) {
					if (n == 0) {
						distance[i] = 0;
						previous[i] = -1;
					}
					Nodes.push(i);
					while (!Nodes.empty()) {
						index = Nodes.front();
						length = distance[index];
						visited[index] = true;
						Nodes.pop();
						for (int j = 0; j < Adjacency_list[index].size();j++) {
							if (!visited[Adjacency_list[index][j].first]) {
								// if its not visited, add to the queue
								Nodes.push(Adjacency_list[index][j].first);
							}
							if (distance[Adjacency_list[index][j].first] > (length + Adjacency_list[index][j].second)) {
								distance[Adjacency_list[index][j].first] = length + Adjacency_list[index][j].second;
								change = true;
							}
						}
					}

				}
			}
			// if there was no change throughout the iteration, return false
			if (change == false) {
				return false;
			}
			// We check in the Nth iteration if change is true
			if (n == (numVertices - 1)) {
				if (change) {
					return true;
				}
			}
			// We increment n and revert change to false
			n++;
			change = false;
			
			for (auto x : visited) {
				x = false;
			}

		}

		return false;
	}

	int bidirectionalDijkstra(int index1, int index2) {
		int source = index1 - 1, dest = index2 - 1;
		int index = 0, distance = 0;
		vi fdistance(numVertices, INT_MAX);
		vi bdistance(numVertices, INT_MAX);
		vb fvisited(numVertices, false);
		vb bvisited(numVertices, false);
		vi fprevious(numVertices, INT_MAX);
		vi bprevious(numVertices, INT_MAX);
		Queue FHeap;
		Queue BHeap;
		// set the source and destination to distance 0 in the
		// forward and reverse heap respectively and push into heap
		fdistance[source] = 0;
		bdistance[dest] = 0;
		fprevious[source] = -1;
		bprevious[dest] = -1;
		FHeap.push(mp(0, source));
		BHeap.push(mp(0, dest));
		while ((!FHeap.empty()) || (!BHeap.empty())) {
			// first we perform Forward iteration one step
			// before that we check if the node is already visited
			
			index = FHeap.top().second;
			distance = FHeap.top().first;
			if (!fvisited[index]) {
				fvisited[index] = true;
				FHeap.pop();
				if (fvisited[index] && bvisited[index]) {
					// do the necessary checks.
					int result = fdistance[index] + bdistance[index];
					// This algorithm would be faster with a set rather than a vector
					for (int i = 0; i < numVertices;i++) {
						if (fvisited[i]) {
							if (bdistance[i] != INT_MAX) {
								if ((fdistance[i] + bdistance[i]) < result) {
									index = i;
									result = fdistance[i] + bdistance[i];
								}
							}
						}
					}
					
					retrievePath(index, fprevious, bprevious);
					return result;
				}
				else {
					relaxVertexForward(index, distance, FHeap, fdistance, fvisited, fprevious);
				}
			}
			// This is the end of the forward run
			
			// next is the backward run
			index = BHeap.top().second;
			distance = BHeap.top().first;
			if (!bvisited[index]) {
				bvisited[index] = true;
				BHeap.pop();
				if (fvisited[index] && bvisited[index]) {
					// do the check algorithm
					int result = fdistance[index] + bdistance[index];
					// This algorithm would be faster with a set rather than a vector
					for (int i = 0; i < numVertices;i++) {
						if (fvisited[i]) {
							if (bdistance[i] != INT_MAX) {
								if ((fdistance[i] + bdistance[i]) < result) {
									index = i;
									result = fdistance[i] + bdistance[i];
								}
							}
						}
					}

					retrievePath(index, fprevious, bprevious);
					return result;
				}
				else {
					relaxVertexBackward(index, distance, BHeap, bdistance, bvisited, bprevious);
				}
			}
		}
		cout << "\nError no Path" << endl;
		return 0;
	}

	void relaxVertexForward(int index, int distance, Queue& Heap, vi& distanceVector, vb& fvisited, vi& fprevious) {
		int weight = 0;
		int vertex = 0;
		for (int i = 0; i < Adjacency_list[index].size(); i++) {
			vertex = Adjacency_list[index][i].first;
			weight = Adjacency_list[index][i].second;
			if (!fvisited[vertex]) {
				distanceVector[vertex] = distance + weight;
				Heap.push(mp(distanceVector[vertex], vertex));
				fprevious[vertex] = index;
			}
		}
	}

	void relaxVertexBackward(int index, int distance, Queue& Heap, vi& distanceVector, vb& bvisited, vi& bprevious) {
		int weight = 0;
		int vertex = 0;
		for (int i = 0; i < Reverse_list[index].size(); i++) {
			vertex = Reverse_list[index][i].first;
			weight = Reverse_list[index][i].second;
			if (!bvisited[vertex]) {
				distanceVector[vertex] = distance + weight;
				Heap.push(mp(distanceVector[vertex], vertex));
				bprevious[vertex] = index;
			}
		}
	}

	void retrievePath(int index, vi& fprevious, vi& bprevious) {
		vi path;

		pathFront(fprevious, path, index);
		pathBack(bprevious, path, index);
		displayVector(path);
	}

	void pathFront(vi& fprevious, vi& path, int index) {
		if (index == -1) {
			return;
		}
		else {
			pathFront(fprevious, path, fprevious[index]);
		}
		path.push_back(index + 1);
	}

	void pathBack(vi& bprevious, vi& path, int index) {
		index = bprevious[index]; // skip current index as it is included in forward path
		while (index > -1) {
			path.push_back(index + 1);
			index = bprevious[index];
		}
	}

	void displayVector(vi& path) {
		cout << endl;
		for (auto x : path) {
			cout << x << "    ";
		}
		cout << endl;
	}
	

};

int main() {
	WeightedGraph G1;
	
	int source = 0, dest = 0;
	cin >> source >> dest;
	cout << G1.bidirectionalDijkstra(source, dest);
	return 0;

}
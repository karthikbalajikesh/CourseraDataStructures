#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class UndirectedGraph {
private:
	vector<vector<int>> Adjacency_list;

public:
	UndirectedGraph() {
		int numVertices = 0, numEdges = 0;
		cin >> numVertices >> numEdges;
		vector<vector<int>> temp(numVertices);
		Adjacency_list = temp;
		int temp1 = 0, temp2 = 0;
		for (int i = 0;i < numEdges;i++) {
			cin >> temp1 >> temp2;
			Adjacency_list[temp1 - 1].push_back(temp2 - 1);
			Adjacency_list[temp2 - 1].push_back(temp1 - 1);
		}

		return;
	}

	int ShortestLength(int node1, int node2) {
		queue<int> Nodes;
		int index = 0;
		vector<int> length(Adjacency_list.size(), -1);
		Nodes.push(node1 - 1);
		length[node1 - 1] = 0;
		while (!Nodes.empty()) {
			index = Nodes.front();
			Nodes.pop();
			for (int i = 0;i < Adjacency_list[index].size();i++) {
				if (length[Adjacency_list[index][i]] == -1) {
					length[Adjacency_list[index][i]] = length[index] + 1;
					Nodes.push(Adjacency_list[index][i]);
				}
			}
		}



		return length[node2-1];
	}

	bool checkBipartite() {
		bool result = true;
		vector<bool> visited(Adjacency_list.size(), false);
		vector<bool> white(Adjacency_list.size(), false);
		bool temp = false;
		queue<int> Nodes;
		int index = 0;
		for (int i = 0; i < Adjacency_list.size();i++) {
			if (!visited[i]) {
				Nodes.push(i);
				while (!Nodes.empty()) {
					index = Nodes.front();
					Nodes.pop();
					visited[index] = true;
					temp = white[index];
					for (int j = 0;j < Adjacency_list[index].size();j++) {
						if (visited[Adjacency_list[index][j]]) {
							if (white[Adjacency_list[index][j]] == temp) {
								result = false;
								return result;
							}
						}
						else {
							visited[Adjacency_list[index][j]] = true;
							white[Adjacency_list[index][j]] = !temp;
							Nodes.push(Adjacency_list[index][j]);
						}
					}
				}
			}
		}
		


		return result;
		
	}
};

int main() {
	UndirectedGraph A1;
	
	cout<<A1.checkBipartite();

	return 0;

}
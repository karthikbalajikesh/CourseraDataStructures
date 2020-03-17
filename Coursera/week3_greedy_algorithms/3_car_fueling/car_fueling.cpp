// Coursera Week 3
// Car Refuelling Problem
// Solved using Greedy Algorithm

#include <iostream>
#include <vector>

using namespace std;

int compute_min_refills(int dist, int tank, vector<int>& stops) {
	// we need a greedy algorithm here. we need to keep subtracting the distance 
	// at every step and keep solving a smaller problem
	int num_stops = 0;
	int last_refuel = 0;
	int last_stop = 0;
	int fuel_distance = 0;
	for (int i = 1; i < stops.size(); i++) {
		//first keep checking if current stop is higher
		fuel_distance = stops[i] - stops[last_refuel];


		if (fuel_distance > tank) {
			if (last_stop == last_refuel) {
				return -1;
			}
			else {
				num_stops++;
				last_refuel = last_stop;
				fuel_distance = stops[i] - stops[last_refuel];
				if (fuel_distance > tank) {
					return -1;
				}
				else if (fuel_distance == tank) {
					num_stops++;
					last_refuel = i;
					last_stop = i;
				}
				else {
					last_stop = i;
				}
				
			}
		}
		else if (fuel_distance == tank) {
			num_stops++;
			last_refuel = i;
			last_stop = i;
		}
		else {
			last_stop = i;
		}
	
	}
	fuel_distance = dist - stops[last_refuel];
	
	if (fuel_distance > tank) {
		if (last_stop == last_refuel) {
			return -1;
		}
		else {
			num_stops++;
			return num_stops;
		}
	}
	else if (fuel_distance == tank) {
		return num_stops;
	}
	else {
		return num_stops;
	}

	


	return num_stops;
}


int main() {
	int d = 0;
	cin >> d;
	int m = 0;
	cin >> m;
	int n = 0;
	cin >> n;

	vector<int> stops(n);
	stops.push_back(0);
	for (size_t i = 1; i <= n; ++i) {
	cin >> stops.at(i);
	}
	cout << compute_min_refills(d, m, stops) << "\n";

	return 0;
}

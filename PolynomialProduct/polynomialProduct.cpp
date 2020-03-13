// Code for the multiplication of Polynomials
// Karthik Balaji Keshavamurthi - date: 3/12/2020

/* We will use three approaces
1. Naive O(n2) approach
2. Naive Divide and Conquer Approach
3. Optimum Divide and Conquer Approach*/

// Include the header files
#include<iostream>
#include<math.h>
#include<vector>

using namespace std;
// Function Definitions
//1. Function to print Vector
void display_vector(vector<int>);
//2. Function to build Vector
vector<int> build_vector(int);
//3. Naive Multiplication Function
vector<int> naive_poly_mult(vector<int>, vector<int>);
//4. Karatsuba algorithm
vector<int> fast_poly_mult(vector<int>, vector<int>);

int main() {
	int order = 0;
	cout << "\nEnter the order of the polynomials : \t";
	cin >> order;
	// we need to build the array of polynomial A coefficients
	vector<int> A_coefficients= build_vector(order);
	vector<int> B_coefficients = build_vector(order);
	
	display_vector(A_coefficients);
	display_vector(B_coefficients);
	display_vector(naive_poly_mult(A_coefficients, B_coefficients));
	

	return 0;
}

void display_vector(vector<int> hello) {
	// Function to print the contents of a vector
	// Input parameter is the vector to be printed
	int order = hello.size();
	cout << "\n The contents of the vector are: ";
	for (int i = 0;i < order;i++) {
		cout << "\n" << hello[i];

	}

}

vector<int> build_vector(int order) {
	// Function to print the contents of a vector
	// Input parameter is the vector to be printed
	static int A = 0;
	A++;
	vector<int> poly;
	cout << "\n Enter the coefficients of Polynomial "<<A<< "\t";
	int temp;
	for (int i = 0;i < order;i++) {
		cin>> temp;
		poly.push_back(temp);

	}
	return poly;
}

vector<int> naive_poly_mult(vector<int> A1, vector<int> A2) {
	int n = A1.size(); // n-1
	vector<int> result((2 * n) - 1, 0);
	for (int i = 0;i < n;i++) {
		for (int j = 0; j < n;j++) {
			result[i + j] = result[i + j] + (A1[i] * A2[j]);
		}
	}

	return result;

}

vector<int> fast_poly_mult(vector<int> A1, vector<int> A2) {
	// We will use the Karatsuba Algorithm. 
	/* We will convert polynomial into D1, D0, E1, E0
		and find D0E0 and D1E1 and (D1+D0)(E1+E0) */
	int n = A1.size();
	vector<int> D1;
	vector<int> D0;
	vector<int> E1;
	vector<int> E0;
}
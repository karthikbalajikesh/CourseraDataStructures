// this is the quicksort algorithm file
// we will do 2 way and three way partitioning
// Karthik Balaji Keshavamurthi
#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

/* Functions used are:
	1. 2 way partition Algorithm
	2. Randomized Quicksort
	3. 3 way partition Algorithm
	4. construct vector
	5. display vector
	6. Stress test*/
int partition2Way(vector<int>&, int, int);
void randomizedQuickSort(vector<int>&, int, int,int);
vector<int> partition3Way(vector<int>&, int, int);
vector<int> construct_vector(int);
vector<int> construct_random_vector(int);
void display_vector(vector<int>);
int check_vectors(vector<int>&, vector<int>&);
void stresstest();


int main(){
	int n = 0; // num of elements
	cin >> n;
	vector<int> unsorted = construct_vector(n);
	randomizedQuickSort(unsorted,0,n-1,3);
	display_vector(unsorted);

	//stresstest();



	return 0;
}

void randomizedQuickSort(vector<int>& Asort, int l, int r, int numPartition=2) {
	// First case is when the number of partitions is 2
	
	if (numPartition == 2) {
		// base case
		if (l >= r) {
			return;
		}
		// choose pivot element
		int pivot = l + (rand() % (r - l + 1));
		// swap  the random element to the first element
		swap(Asort[l], Asort[pivot]);
		int m = partition2Way(Asort, l, r);

		randomizedQuickSort(Asort, l, m - 1,2);
		randomizedQuickSort(Asort, m + 1, r,2 );
	}
	else if (numPartition == 3) {
		// base case
		if (l >= r) {
			return;
		}
		// choose pivot element
		int pivot = l + (rand() % (r - l + 1));
		// swap to the first element
		swap(Asort[l], Asort[pivot]);
		vector<int> m = partition3Way(Asort, l, r);

		randomizedQuickSort(Asort, l, m[0] - 1,3);
		randomizedQuickSort(Asort, m[1] + 1, r,3);
	}
	else {
		cout << "\nError: numPartition can only be 2 or 3 way";
	}

}

int partition2Way(vector<int>& A, int l, int r) {
	// we need one variable to get the end of lower  values zone.
	// this index will be returned from the function.
	// we will iterate from l+1 to r
	int j = l;
	for (int i = l + 1; i <= r;i++) {
		// if an element is smaller than pivot,
		// add it in the lower subsection and increment j;

		if (A[i] <= A[l]) {
			j++;
			swap(A[i], A[j]);
		}
		

	}
	swap(A[l], A[j]);
	return j;
}

vector<int> partition3Way(vector<int>& ref, int l, int r) {
	// Let us create the vector that will hold the two indices.
	// m[0] will hold the first occurrance of an element
	// m[1] will hold the second occurrance of the element. 
	// if there is only one entry of the element m[0] = m[1]
	vector<int> m;
	int j = l;
	int k = l;

	for (int i = l + 1;i <= r;i++) {
		if (ref[i] < ref[l]) {
			j++;
			k++;
			if (j == k) {
				swap(ref[i], ref[j]);
			}
			else {
				swap(ref[j], ref[i]);
				swap(ref[i], ref[k]);
			}
		}
		else if (ref[i] == ref[l]) {
			k++;
			swap(ref[k], ref[i]);
		} 
	}
	swap(ref[l], ref[j]);
	m.push_back(j);
	m.push_back(k);

	return m;
}

vector<int> construct_vector(int n) {
	vector<int> A;
	int temp = 0;
	for (int i = 0;i < n;i++) {
		cin >> temp;
		A.push_back(temp);
	}
	return A;
}

void display_vector(vector<int> Adisp) {
	//cout << "\nThe elements in the vector are : ";
	
	for (auto x : Adisp) {
	
		cout << x << " ";
	}
}

void stresstest() {
	int testnum = 0;
	int i = 1;
	while (i==1) {
		testnum++;
		int n = rand() % 10 + 2;
		vector<int>alpha = construct_random_vector(n);
		vector<int>beta = alpha;
		vector<int>gamma = alpha;
		sort(beta.begin(), beta.end());
		randomizedQuickSort(gamma, 0, n - 1, 3);
		i = check_vectors(beta, gamma);
		if (i == 0) {
			cout << "\nError at test number:   "<<testnum;
			cout << "\nInput:";
			display_vector(alpha);
			cout << "\nExpected output:";
			display_vector(beta);
			cout << "\nActual Output:";
			display_vector(gamma);
		}
		

	}


	

}

vector<int> construct_random_vector(int n) {
	vector<int> A;
	int temp = 0;
	for (int i = 0;i < n;i++) {
		temp = rand() % 10 + 1;
		A.push_back(temp);
	}
	return A;
}

int check_vectors(vector<int>& B,vector<int>& C){
	for (int index = 0; index < B.size();index++) {
		if (B[index] != C[index]) {
			return 0;
		}
	}

	return 1;
}

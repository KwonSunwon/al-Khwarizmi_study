//백준 1026번 보물 문제

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int, int);

int main() {
	vector<int> A;
	vector<int> B;
	int nodelen{ 0 };
	int node{ 0 };
	int result{ 0 };
	
	cin >> nodelen;

	for (int i = 0; i < nodelen; i++) {
		cin >> node;
		A.push_back(node);
	}

	for (int i = 0; i < nodelen; i++) {
		cin >> node;
		B.push_back(node);
	}

	sort(A.begin(), A.end(), comp);
	sort(B.begin(), B.end());

	for (int i = 0; i < nodelen; i++) {
		int a = A.front(); A.erase(A.begin());
		int b = B.front(); B.erase(B.begin());
	
		result += a * b;
	}

	cout << result;
}

bool comp(int a, int b) {
	return a > b;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(int, int);

int main() {
	int EA;
	vector<int> weights;
	int result{ 0 };

	//get inputs
	cin >> EA;

	for (int i = 0; i < EA; i++) {
		int temp;
		cin >> temp;
		weights.emplace_back(temp);
	}

	//sort for greedy
	sort(weights.begin(), weights.end(), compare);

	//if (result + 2) <= weights[i] => result + 1 is answer
	for (int i = 0; i < EA; i++) {
		if ((result + 2) <= weights[i]) {
			break;
		}

		result += weights[i];
	}

	cout << (result + 1);
}

bool compare(int a, int b) {
	return a < b;
}
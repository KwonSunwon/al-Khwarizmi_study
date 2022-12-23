#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int, int);

int main() {
	int len{ 0 };
	int result{ 0 };
	vector<int> t;

	cin >> len;

	for (int i = 0; i < len; i++) {
		int time;

		cin >> time;

		t.emplace_back(time);
	}

	sort(t.begin(), t.end(),compare);

	for (int i = 0; i < len; i++) {
		result += (t.back()*(len - i)); t.pop_back();
	}

	cout << result;
}

bool compare(int i, int j) {
	return i > j;
}
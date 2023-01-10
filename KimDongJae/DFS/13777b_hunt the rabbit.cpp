#include <iostream>
#include <vector>

using namespace std;

void solve(int, int, int);

int main() {
	vector<int> r_pos;

	while (true) {
		int temp;

		cin >> temp;
		if (temp != 0) r_pos.emplace_back(temp);

		else break;
	}

	for (int i = 0; i < r_pos.size(); ++i) {
		int target = r_pos[i];
		
		solve(1, 50, target);
		cout << endl;
	}
}

void solve(int start, int end, int target) {
	int select = (start + end) / 2;

	cout << select << ' ';

	if (target > select) {
		solve(select + 1, end, target);
	}

	else if (target < select) {
		solve(start, select - 1, target);
	}

}
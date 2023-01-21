#include <iostream>
#include <cmath>

using namespace std;

int mushroom[10];
int res{ 0 };

void solve(int);

int main() {
	for (int i = 0; i < 10; ++i) {
		cin >> mushroom[i];
	}

	solve(0);

	cout << res;
}

void solve(int idx) {
	if (abs(100 - res) < abs(100 - (res + mushroom[idx]))) {
		return;
	}

	res += mushroom[idx];

	if (idx < 9) solve(idx + 1);
}

#include <iostream>

using namespace std;

int main() {
	int numbers[5];
	int res{ 1 };

	for (int i = 0; i < 5; ++i) {
		cin >> numbers[i];
	}

	while (true) {
		int counter{ 0 };

		for (int i = 0; i < 5; ++i) {
			if (res % numbers[i] == 0) {
				++counter;
			}
		}

		if (counter >= 3) break;

		++res;
	}

	cout << res;
}
#include <iostream>

using namespace std;

int main() {
	int num[3];
	char temp;
	int res{ 0 };

	cin >> num[0]; getchar();
	cin >> num[1]; getchar();
	cin >> num[2];

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				if (i != j && j != k && k != i) {
					if (num[i] >= 1 && num[i] <= 12 && num[j] >= 0 && num[j] <= 59 && num[k] >= 0 && num[k] <= 59) {
						++res;
					}
				}
			}
		}
	}

	cout << res;
}
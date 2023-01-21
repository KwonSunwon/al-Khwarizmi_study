#include <iostream>
#include <limits.h>

using namespace std;

int days, num;
int res{ INT_MIN };

int main() {
	int tem[100];

	cin >> days >> num;

	for (int i = 0; i < days; ++i) {
		cin >> tem[i];
	}

	for (int i = days - 1; i >= (num - 1); --i) {
		int temp_res{ 0 };
		for (int j = 0; j < num; ++j) {
			temp_res += tem[i - j];
		}

		if (res < temp_res) res = temp_res;
	}

	cout << res;
}
#include <iostream>

using namespace std;

void swap(int*, int*);

int main() {
	int player_EA{ 0 };
	int a{ 0 }, b{ 0 };
	int round{ 1 };

	cin >> player_EA;
	cin >> a;
	cin >> b;

	if (a > b) swap(&a, &b);

	while (true) {
		if (a > b) {
			round = -1;
			break;
		}

		if ((a + 1) == b && (a % 2 != 0)) break;

		if (a % 2 == 0) { //Â¦¼ö
			a /= 2;
		}

		else {
			a = (a - 1) / 2 + 1;
		}

		if (b % 2 == 0) { //Â¦¼ö
			b /= 2;
		}

		else {
			b = (b - 1) / 2 + 1;
		}

		round++;
	}

	cout << round;
}

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
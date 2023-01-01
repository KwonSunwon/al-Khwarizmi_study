#include <iostream>

using namespace std;

void painter(char*, char, int*);
int get_case(char color[8][8]);
void copy(char temp[8][8], char color[50][50], int a, int b);


int main() {
	int n{ 0 }, m{ 0 };
	char color[50][50];
	char temp[8][8];
	int res{ 250 };

	cin >> n;
	cin >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> color[i][j];
		}
	}

	for (int i = 0; i <= (n - 8); ++i) {
		for (int j = 0; j <= (m - 8); ++j) {
			copy(temp, color, i, j);

			int sub_res = get_case(temp);

			if (res > sub_res) res = sub_res;
		}
	}
	
	cout << res;
}

void painter(char* board, char c, int* n) {
	if (*board != c) {
		*board = c;
		++*n;
	}
}

int get_case(char color[8][8]) {
	int case1{ 0 };
	int case2{ 0 };
	char color2[8][8];

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			color2[i][j] = color[i][j];
		}
	}

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (i == 0 && j == 0) {
				painter(&color[i][j], 'W', &case1);
				continue;
			}
			if (j == 0) {
				if (color[i - 1][j] == 'W') {
					painter(&color[i][j], 'B', &case1);
					continue;
				}

				painter(&color[i][j], 'W', &case1);
				continue;
			}

			if (color[i][j - 1] == 'W') {
				painter(&color[i][j], 'B', &case1);
				continue;
			}

			painter(&color[i][j], 'W', &case1);
			continue;

		}
	}

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (i == 0 && j == 0) {
				painter(&color2[i][j], 'B', &case2);
				continue;
			}
			if (j == 0) {
				if (color2[i - 1][j] == 'W') {
					painter(&color2[i][j], 'B', &case2);
					continue;
				}

				painter(&color2[i][j], 'W', &case2);
				continue;
			}

			if (color2[i][j - 1] == 'W') {
				painter(&color2[i][j], 'B', &case2);
				continue;
			}

			painter(&color2[i][j], 'W', &case2);
			continue;

		}
	}

	if (case1 > case2) return case2;
	return case1;
}

void copy(char temp[8][8], char color[50][50], int a, int b) {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			temp[i][j] = color[a + i][b + j];
		}
	}
}
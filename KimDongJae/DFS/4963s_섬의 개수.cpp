#include <iostream>
#include <vector>

using namespace std;

int solve(int, int, int map[50][50]);

void fill(int, int,int, int map[50][50]);

int main() {
	vector<int> res;
	int row{ 0 }, col{ 0 };

	while (true) {
		int map[50][50]{ 0, };

		cin >> row >> col;

		if (row == 0 && col == 0) break;

		for (int i = 0; i < col; ++i) {
			for (int j = 0; j < row; ++j) {
				cin >> map[i][j];
			}
		}

		int temp = solve(row, col, map);

		res.emplace_back(temp);
	}

	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}
}

int solve(int row, int col, int map[50][50]) {
	int num{ 2 };

	while (true) {
		
		bool end{ true };
		for (int i = 0; i < col; ++i) {
			for (int j = 0; j < row; ++j) {
				if (map[i][j] == 1) {
					fill(j, i, num, map);
					end = false;
					break;
				}
			}

			if (end == false) break;
		}

		if (end) break;
		++num;
	}

	return (num - 2);
}

void fill(int row, int col, int num, int map[50][50]) {
	map[col][row] = num;

	if ((row - 1) >= 0 && map[col][row - 1] == 1) {
		fill(row - 1, col, num, map);
	}

	if ((row - 1) >= 0 && (col - 1) >= 0 && map[col - 1][row - 1] == 1) {
		fill(row - 1, col - 1, num, map);
	}

	if ((col - 1) >= 0 && map[col - 1][row] == 1) {
		fill(row , col - 1, num, map);
	}

	if ((col - 1) >= 0 && (row + 1) < 50 && map[col - 1][row + 1] == 1) {
		fill(row + 1, col - 1, num, map);
	}

	if ((row + 1) < 50 && map[col][row + 1] == 1) {
		fill(row + 1, col, num, map);
	}

	if ((row + 1) < 50 && (col + 1) < 50 && map[col + 1][row + 1] == 1) {
		fill(row + 1, col + 1, num, map);
	}

	if ((col + 1) < 50 && map[col + 1][row] == 1) {
		fill(row, col + 1, num, map);
	}

	if ((col + 1) < 50 && (row - 1) >= 0 && map[col + 1][row - 1] == 1) {
		fill(row - 1, col + 1, num, map);
	}
}
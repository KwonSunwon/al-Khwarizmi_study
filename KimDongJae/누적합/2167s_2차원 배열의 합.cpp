#include <iostream>
#include <vector>

using namespace std;

int map[301][301];
int N, M, I, J, X, Y;
int _case;
vector<int> res;

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i + 1][j + 1];
		}
	}

	cin >> _case;

	for (int C = 0; C < _case; ++C) {
		cin >> I >> J >> X >> Y;
		int temp{ 0 };

		for (int i = I; i <= X; ++i) {
			for (int j = J; j <= Y; ++j) {
				temp += map[i][j];
			}
		}

		res.emplace_back(temp);
	}

	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}
}
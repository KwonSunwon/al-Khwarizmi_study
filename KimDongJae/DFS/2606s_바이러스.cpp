#include <iostream>

using namespace std;

bool conta[100]{ false, };
int res{ 0 };
bool edge[100][100]{ false, };

void solve(int);

int main() {
	int vertex{ 0 };
	int e_EA{ 0 };
	

	cin >> vertex;
	cin >> e_EA;

	for (int i = 0; i < e_EA; ++i) {
		int start, end;
		cin >> start >> end;
		edge[start - 1][end - 1] = true;
		edge[end - 1][start - 1] = true;
	}

	conta[0] = true;

	solve(vertex);

	cout << res;
}

void solve(int vertex) {
	bool con{ false };

	for (int i = 0; i < vertex; ++i) {
		if (conta[i] == true) {
			for (int j = 0; j < vertex; ++j) {
				if (edge[i][j] && !conta[j]) {
					conta[j] = true;
					con = true;
					++res;
				}
			}
		}
	}

	if(con)	solve(vertex);
}
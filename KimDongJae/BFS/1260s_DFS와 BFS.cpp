#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int vertex;
int edge;
int start;
bool visited[1001];
bool map[1001][1001];
queue<int> q;

void DFS(int);
void BFS(int);

int main() {
	cin >> vertex >> edge >> start;

	for (int i = 0; i < edge; ++i) {
		int s, e;
		cin >> s >> e;
		map[s][e] = true;
		map[e][s] = true;
	}

	DFS(start);
	cout << endl;
	memset(visited, false, sizeof(visited));

	BFS(start);

	return 0;
}

void DFS(int num) {
	visited[num] = true;
	cout << num << ' ';

	for (int i = 1; i <= vertex; ++i) {
		if (map[num][i] && !visited[i]) {
			DFS(i);
		}
	}
}

void BFS(int num) {
	q.push(num);
	visited[num] = true;

	cout << num << ' ';

	while (!q.empty()) {
		num = q.front(); q.pop();

		for (int i = 1; i <= vertex; ++i) {
			if (map[num][i] && !visited[i]) {
				q.push(i);

				visited[i] = true;
				cout << i << ' ';
			}
		}
	}
}
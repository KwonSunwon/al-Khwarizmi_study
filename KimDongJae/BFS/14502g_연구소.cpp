/*
���ٹ� 1: Ž�� �� ��ĭ �߰��ϸ� ���� ����� ���� 2���� ���� �ѹ��� �׽�Ʈ �غ� ��, ���Ʈ ����

���� �߻� : �׷����� bfs ���� ���� ����� �� �� �ѼյǴ� �� �߻� <== ���� ����� �׽�Ʈ �ϴ°� ����� ������ ����

���ٹ� 1 ���� : �ð��ʰ� << ���ʿ� ������� ������ �߾���. �ٸ� ����� �ʿ�

���ٹ� 2: ��ĭ�� ���� ����Ʈ�� ����

���� �߻� : ��ĭ�� �湮�ߴ��� �˱� ���ؼ� 2���� �迭�� ����ߴµ�, ��ĭ �ε����� ���߱Ⱑ �ʹ� �����
           >> ��ĭ�� ����ϴ� 1���� �迭�� �����Ͽ� �ذ�

*/
#include <iostream>
#include <vector>
#include <queue>

#define MAX 8

using namespace std;

int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
int n, m, map[MAX][MAX];
int tmp[MAX][MAX];
int res = 0;
bool visited[MAX * MAX];
vector<pair<int, int>> blank;

void copy(int tmp[MAX][MAX], int a[MAX][MAX]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = a[i][j];
		}
	}
}

void bfs() {

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 2) {
				q.push({ i, j });
			}
		}
	}

	while (q.size()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) 
				continue;

			if (tmp[nx][ny] == 0) {
				tmp[nx][ny] = 2;
				q.push({ nx, ny });
			}
		}
	}

	int safe_area = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 0) {
				safe_area++;
			}
		}
	}

	res = max(res, safe_area);
}

void test(int cur, int idx) {

	if (cur == 3) {
		copy(tmp, map);
		int cnt = 0;
		for (int i = 0; i < blank.size(); i++) {
			if (cnt == 3) break;
			if (visited[i]) {
				int x = blank[i].first;
				int y = blank[i].second;
				tmp[x][y] = 1;
				cnt++;
			}
		}
		bfs();
		return;
	}

	for (int i = idx; i < blank.size(); i++) {
		if (visited[i]) continue;
		visited[i] = true;
		test(cur + 1, i);
		visited[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				blank.push_back({ i, j });
			}
		}
	}

	test(0, 0);

	cout << res;
}
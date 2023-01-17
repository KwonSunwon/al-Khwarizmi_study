/*
접근법 1: 탐색 중 빈칸 발견하면 벽을 새우고 남은 2개의 벽을 한번씩 테스트 해봄 즉, 브루트 포스

문제 발생 : 그래프가 bfs 도중 벽을 세우고 할 때 훼손되는 일 발생 <== 벽을 세우고 테스트 하는건 복사된 맵으로 하자

접근법 1 실패 : 시간초과 << 애초에 어느정도 예상은 했었음. 다른 방식이 필요

접근법 2: 빈칸은 따로 리스트로 관리

문제 발생 : 빈칸을 방문했는지 알기 위해서 2차원 배열을 사용했는데, 빈칸 인덱스랑 맞추기가 너무 힘들다
           >> 빈칸만 사용하는 1차원 배열로 변경하여 해결

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
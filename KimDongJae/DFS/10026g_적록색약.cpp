/*
1�� ���� : DFS�� �ϸ� ���� ������ �ִ� ĭ�� ���� �湮�� ������ �Ѵ�. ��ȸ�� �湮���� ���� ������ ������ ���ο� ĭ�� ���°��̶� �Ǵ��Ѵ�.
          ���ϻ����� ����� ������ ���� �ʷ����� �ٲ۵� �Ȱ��� �����Ѵ�.

	Ʋ�� : ���� Ʋ���ž� ����ü.. ==> ���� �Խ��� ���ٰ� ���������� �ٲٴ� �Ǿ��ٴ� ��⸦ ��� res�� ���������� �ٲ� ==> ���� �̿���
*/
#include <iostream>
#include <set>

using namespace std;

int n, res;
char map[100][100];
set<pair<int,int>> visited;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void dfs(int x, int y) {
	visited.insert(make_pair(x,y));

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (visited.find(make_pair(nx,ny)) == visited.end() && map[x][y] == map[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited.find(make_pair(i,j)) == visited.end()) {
				dfs(i, j);
				res++;
			}
		}
	}

	cout << res << ' ';

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'R') map[i][j] = 'G';
			else map[i][j] = map[i][j];
		}
	}

	visited.clear();

	res = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited.find(make_pair(i, j)) == visited.end()) {
				dfs(i, j);
				res++;
			}
		}
	}
	cout << res;

	return 0;
}
/*
1번 접근 : DFS를 하며 같은 조각에 있는 칸을 전부 방문한 것으로 한다. 순회중 방문하지 않은 조각이 있으면 새로운 칸이 나온것이라 판단한다.
          적록색약인 사람은 빨강을 전부 초록으로 바꾼뒤 똑같이 시행한다.

	틀림 : 뭐가 틀린거야 도데체.. ==> 질문 게시판 보다가 전역변수로 바꾸니 되었다는 얘기를 듣고 res를 전역변수로 바꿈 ==> 성공 이외진
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
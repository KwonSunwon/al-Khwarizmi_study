/*
존나 귀찮다
접근법 1 : 집, 편의점, 페스티벌의 거리를 저장해서 각 점에서 1000m 내에 이동할 수 있는 점으로 이동하며 탐색한다. 
            페스티벌에 도착하면 헤피한다.

문제 발생 : happy 해야 하는데 sad하다 왜지? << 결과를 넣기 전에 초기화를 하는 실수를 했다.
문제 발생2 : 예제를 넣고 실행했는데 결과가 잘못됨 << 각자 테스트 하니 잘 된다???
            << spot vector를 초기화 안함 ㅄ
문제 발생3 : 시간 초과

해결 : 거리를 미리 계산해두지 말고 순회 중 현재 위치에서 페스티벌 위치까지 거리를 계산하자.

동재는 이제야 happy 해졌다.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <memory.h>

using namespace std;

pair<int, int> start, festival;
vector<pair<int, int>> spot;
vector<bool> res;
int store_EA;
bool visited[100];

void input();
void clear();
bool solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int c{ 0 };
	cin >> c;

	for (int k = 0; k < c; ++k) {
		input();

		res.emplace_back(solve());

		clear();
	}

	for (int i = 0; i < res.size(); ++i) {
		if (res[i]) cout << "happy" << endl;
		else cout << "sad" << endl;
	}
}

void input() {
	cin >> store_EA;
	int tem_x, tem_y;
	cin >> tem_x >> tem_y;
	start.first = tem_x;
	start.second = tem_y;

	for (int i = 0; i < store_EA; ++i) {
		cin >> tem_x >> tem_y;
		spot.push_back({ tem_x,tem_y });
	}

	cin >> tem_x >> tem_y;

	festival.first = tem_x;
	festival.second = tem_y;
}

void clear() {
	memset(visited, false, sizeof(visited));

	spot.clear();
}

bool solve() {
	queue <pair<int, int>> q;
	q.push({ start.first, start.second });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (abs(x - festival.first) + abs(y - festival.second) <= 1000) return true;

		for (int i = 0; i < store_EA; i++) {
			if (visited[i] == true)continue;
			int d = (abs(x - spot[i].first) + abs(y - spot[i].second));
			if (d <= 1000) {
				visited[i] = true;
				q.push({ spot[i].first, spot[i].second });
			}
		}
	}
	return false;
}
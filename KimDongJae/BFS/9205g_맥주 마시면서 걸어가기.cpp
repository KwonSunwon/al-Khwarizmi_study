/*
���� ������
���ٹ� 1 : ��, ������, �佺Ƽ���� �Ÿ��� �����ؼ� �� ������ 1000m ���� �̵��� �� �ִ� ������ �̵��ϸ� Ž���Ѵ�. 
            �佺Ƽ���� �����ϸ� �����Ѵ�.

���� �߻� : happy �ؾ� �ϴµ� sad�ϴ� ����? << ����� �ֱ� ���� �ʱ�ȭ�� �ϴ� �Ǽ��� �ߴ�.
���� �߻�2 : ������ �ְ� �����ߴµ� ����� �߸��� << ���� �׽�Ʈ �ϴ� �� �ȴ�???
            << spot vector�� �ʱ�ȭ ���� ��
���� �߻�3 : �ð� �ʰ�

�ذ� : �Ÿ��� �̸� ����ص��� ���� ��ȸ �� ���� ��ġ���� �佺Ƽ�� ��ġ���� �Ÿ��� �������.

����� ������ happy ������.
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
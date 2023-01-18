/*
https://www.acmicpc.net/problem/16236
����: �Ʊ� ���
�з�: �ʺ�켱Ž��
���̵�: ��� 3

���� ���� Ǯ��:
���� ���¿��� �ʺ�켱 Ž���� �س�����.
������ �ִ� ������ �ĺ��� �־�ΰ�, Ž�������� �ĺ�����
��� �´� ����⸦ �԰� �Ʊ� ����� ���¸� �����Ѵ�.
�̸� �ݺ�
*/

#include<iostream>
#include<string>
#include<queue>

#define INF 2000000000
using namespace std;

int dx[4] = { 0,-1,1,0 };
int dy[4] = { -1,0,0,1 };

bool visited[20][20];
int cnt[20][20];
int map[20][20];
int mapSize;
int ans = 0;
bool running = true;

class Shark {
public:
	int exp = 0;
	int lv = 2;
	int x, y;
};

void update();
void searchTarget();
void mapSet();
Shark shark;

int main()
{
	cin >> mapSize;

	for (int i = 0; i < mapSize; ++i)
		for (int j = 0; j < mapSize; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				shark.y = i;
				shark.x = j;
			}
		}

	while (running)
		update();

	cout << ans;
}

void update()
{
	searchTarget();
	mapSet();
}

void mapSet()
{
	for (int i = 0; i < mapSize; ++i)
		for (int j = 0; j < mapSize; ++j)
		{
			visited[i][j] = false;
			cnt[i][j] = 0;
		}
}

void searchTarget()
{
	queue<pair<int, int>> q;
	vector<pair<pair<int, int>,int>> candidate;
	int depth=INF;
	q.push(make_pair(shark.y, shark.x));
	map[shark.y][shark.x] = 0;
	visited[shark.y][shark.x] = true;

	while (!q.empty())
	{
		pair<int, int> nowPos = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = nowPos.first + dy[i];
			int nx = nowPos.second + dx[i];

			//���� �ѱ���
			if (ny < 0 || nx < 0 || ny >= mapSize || nx >= mapSize)
				continue;
			//�̹� �湮�� ���
			if (visited[ny][nx])
				continue;
			//������ ū ������� ���
			if (map[ny][nx] > shark.lv)
				continue;
			//�� �� �Ǵ� ���� ũ���� ������� ���
			if (map[ny][nx] == shark.lv || map[ny][nx]==0)
			{
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
				cnt[ny][nx] = cnt[nowPos.first][nowPos.second] + 1;
			}

			//���� �� �ִ� ������� ���
			if (map[ny][nx] < shark.lv && map[ny][nx]!=0)
			{
				cnt[ny][nx] = cnt[nowPos.first][nowPos.second] + 1;
				candidate.push_back(make_pair(make_pair(ny, nx), cnt[ny][nx]));
			}
		}
	}
	//���� �ĺ��� �ִٸ� ���� ������, ���� ���� ������, ���� ���ʿ� �ִ� ����⸦ �Դ´�.
	if (!candidate.empty())
	{
		int targetY=INF;
		int targetX=INF;
		int depth = INF;
		for (int i = 0; i < candidate.size(); ++i)
		{
			depth = min(depth, candidate[i].second);
		}
		for (int i = 0; i < candidate.size(); ++i)
		{
			if(candidate[i].second==depth)
				targetY = min(targetY, candidate[i].first.first);
		}

		for (int i = 0; i < candidate.size(); ++i)
		{
			if (candidate[i].second == depth && candidate[i].first.first==targetY)
				targetX = min(targetX, candidate[i].first.second);
		}
		//����� ���¸� �������ش�.
		ans += depth;
		shark.y = targetY;
		shark.x = targetX;
		shark.exp++;
		map[targetY][targetX] = 9;

		if (shark.exp == shark.lv)
		{
			shark.lv++;
			shark.exp = 0;
		}
	}
	//���� �ĺ��� ���ٸ� �����Ѵ�.
	else
		running = false;
}
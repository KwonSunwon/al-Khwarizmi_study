/*
https://www.acmicpc.net/problem/16236
제목: 아기 상어
분류: 너비우선탐색
난이도: 골드 3

최초 접근 풀이:
현재 상태에서 너비우선 탐색을 해나간다.
먹을수 있는 물고기는 후보에 넣어두고, 탐색종료후 후보들중
대상에 맞는 물고기를 먹고 아기 상어의 상태를 갱신한다.
이를 반복
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

			//맵을 넘긴경우
			if (ny < 0 || nx < 0 || ny >= mapSize || nx >= mapSize)
				continue;
			//이미 방문한 경우
			if (visited[ny][nx])
				continue;
			//나보다 큰 물고기인 경우
			if (map[ny][nx] > shark.lv)
				continue;
			//빈 곳 또는 같은 크기의 물고기인 경우
			if (map[ny][nx] == shark.lv || map[ny][nx]==0)
			{
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
				cnt[ny][nx] = cnt[nowPos.first][nowPos.second] + 1;
			}

			//먹을 수 있는 물고기인 경우
			if (map[ny][nx] < shark.lv && map[ny][nx]!=0)
			{
				cnt[ny][nx] = cnt[nowPos.first][nowPos.second] + 1;
				candidate.push_back(make_pair(make_pair(ny, nx), cnt[ny][nx]));
			}
		}
	}
	//만약 후보가 있다면 가장 가깝고, 가장 위에 있으며, 가장 왼쪽에 있는 물고기를 먹는다.
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
		//상어의 상태를 갱신해준다.
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
	//만약 후보가 없다면 종료한다.
	else
		running = false;
}
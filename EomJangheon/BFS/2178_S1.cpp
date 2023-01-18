/*
https://www.acmicpc.net/problem/2178
제목: 미로 탐색
분류: 너비우선탐색
난이도: 실버1

최초 접근 풀이:
너비우선탐색
목표 좌표 도달시 함수 리턴
*/

#include<iostream>
#include<string>
#include<queue>
using namespace std;

#define MAX 100

int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

bool visited[MAX][MAX] = { false };
int cnt[MAX][MAX] = { 0 };
string map[MAX];

int height, width;


void BFS();

int main()
{
	cin >> height >> width;

	for (int i = 0; i < height; ++i)
		cin >> map[i];

	BFS();

	cout << cnt[height - 1][width - 1];
}

void BFS()
{
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	visited[0][0] = true;
	cnt[0][0] = 1;

	while (!q.empty())
	{
		pair<int, int> nowPos = q.front(); q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int ny = nowPos.first + dy[i];
			int nx = nowPos.second + dx[i];
			if (ny < 0 || nx < 0 || ny >= height || nx >= width)
				continue;

			if (map[ny][nx] == '0')
				continue;

			if (!visited[ny][nx])
			{
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
				cnt[ny][nx] = cnt[nowPos.first][nowPos.second] + 1;
			}
			if (ny == height - 1 && nx == width - 1)
				return;
		}
	}


}
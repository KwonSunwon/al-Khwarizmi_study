/*
https://www.acmicpc.net/problem/7562
제목: 나이트의 이동
분류: 너비우선탐색
난이도: 실버1

최초 접근 풀이:
너비우선탐색
목표 좌표 도달시 함수 리턴
*/

#include<iostream>
#include<queue>
using namespace std;

#define MAX 300

int dx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[8] = {-1,1,-2,2,-2,2,-1,1};

bool visited[MAX][MAX] = {false};
int cnt[MAX][MAX] = { 0 };


pair<int, int> startPos;
pair<int, int>targetPos;

void BFS(int size);

int main()
{
	int testCase;
	int size = 0;
	cin >> testCase;

	for (int i = 0; i < testCase; ++i)
	{
		cin >> size;
		cin >> startPos.first >> startPos.second;
		cin >> targetPos.first >> targetPos.second;

		BFS(size);
		cout << cnt[targetPos.first][targetPos.second] << endl;;

		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				visited[i][j] = false;
				cnt[i][j] = 0;
			}
		}
	}

}

void BFS(int size)
{
	queue<pair<int,int>> q;
	q.push(startPos);
	visited[startPos.first][startPos.second] = true;

	while (!q.empty())
	{
		pair<int, int> nowPos=q.front(); q.pop();
		for (int i = 0; i < 8; ++i)
		{
			int ny = nowPos.first + dy[i];
			int nx = nowPos.second + dx[i];
			if (ny < 0 || nx < 0 || ny >= size || nx >= size)
				continue;

			if (!visited[ny][nx])
			{
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
				cnt[ny][nx] = cnt[nowPos.first][nowPos.second] + 1;
			}
			if (ny == targetPos.first && nx == targetPos.second)
				return;
		}
	}


}
/*
https://www.acmicpc.net/problem/15730
제목: 수영장 사장님
분류: 너비우선탐색
난이도: 플레 5

최초 접근 풀이:
최소 높이부터 시작해서 최대높이까지 높이를 하나씩 늘려가며 bfs한다.
현재 위치부터 자기보다 낮은 곳으로 흘러나가며 갯수를 센다.
테두리에서 높이가 함수 인자 높이와 같거나 낮을경우 fail처리한다.

3시간동안 오타도 고치고 오류도 고치고 어떻게든 풀었는데 시간초과가 난다.
bfs를 돌리기위한 순회가 너무많다. 이것저것 해봤는데 못 하겠다.

https://hellogaon.tistory.com/60
이 블로그에 자세히 나왔다.
읽고 이해하는데 시간이 좀 걸렸는데 엄청 좋은것같다.
*/

#include<iostream>
#include<string>
#include<queue>

using namespace std;
int height;
int width;

int ans = 0;
int map[100][100];
bool visited[100][100];

int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

void BFS(int y,int x, int h);

int main()
{
	int hMax = -1;
	int hMin = 10001;
	cin >> height >> width;
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			cin >> map[i][j];
			hMax = max(map[i][j], hMax);
			hMin = min(map[i][j], hMin);
		}
	}

	//최소 높이부터 최대 높이까지 BFS를 모두 돌려본다.
	for (int h = hMin; h < hMax; ++h)
	{
		for (int i = 1; i < height - 1; ++i)
		{
			for (int j = 1; j < width - 1; ++j)
			{
				if (map[i][j] <= h && visited[i][j] == false)
					BFS(i, j, h);
			}
		}

		for (int i = 0; i < height ; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				visited[i][j] = false;
			}
		}
	}
	cout << ans;
}

void BFS(int y, int x, int h)
{
	bool fail = false;
	visited[y][x] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	int ret = 1;

	while (!q.empty())
	{
		pair<int, int> nowPos = q.front();
		q.pop();
		
		for (int i = 0; i < 4; ++i)
		{
			int ny = nowPos.first + dy[i];
			int nx = nowPos.second + dx[i];

			if (visited[ny][nx])
				continue;

			//내부이며, 높이가 낮은 곳들로 흘러나간다.
			if (ny >= 1 && nx >= 1 && ny < height - 1 && nx < width - 1)
			{
				if (h >= map[ny][nx])
				{
					q.push(make_pair(ny, nx));
					visited[ny][nx] = true;
					ret++;
				}
			}
			//만약 외부로 물이 새 나가면 fail처리한다.
			else if(ny==0 || nx==0 || ny==height-1 || nx==width-1)
			{
				if(map[ny][nx]<=h)
				{
					fail = true;
				}
			}
		}
	}
	//밖으로 물이 흐르지 않았다면 더해준다
	if (!fail)
	{
		ans += ret;
	}
	
}
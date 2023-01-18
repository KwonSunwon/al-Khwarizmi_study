/*
https://www.acmicpc.net/problem/15730
����: ������ �����
�з�: �ʺ�켱Ž��
���̵�: �÷� 5

���� ���� Ǯ��:
�ּ� ���̺��� �����ؼ� �ִ���̱��� ���̸� �ϳ��� �÷����� bfs�Ѵ�.
���� ��ġ���� �ڱ⺸�� ���� ������ �귯������ ������ ����.
�׵θ����� ���̰� �Լ� ���� ���̿� ���ų� ������� failó���Ѵ�.

3�ð����� ��Ÿ�� ��ġ�� ������ ��ġ�� ��Ե� Ǯ���µ� �ð��ʰ��� ����.
bfs�� ���������� ��ȸ�� �ʹ�����. �̰����� �غôµ� �� �ϰڴ�.

https://hellogaon.tistory.com/60
�� ��α׿� �ڼ��� ���Դ�.
�а� �����ϴµ� �ð��� �� �ɷȴµ� ��û �����Ͱ���.
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

	//�ּ� ���̺��� �ִ� ���̱��� BFS�� ��� ��������.
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

			//�����̸�, ���̰� ���� ����� �귯������.
			if (ny >= 1 && nx >= 1 && ny < height - 1 && nx < width - 1)
			{
				if (h >= map[ny][nx])
				{
					q.push(make_pair(ny, nx));
					visited[ny][nx] = true;
					ret++;
				}
			}
			//���� �ܺη� ���� �� ������ failó���Ѵ�.
			else if(ny==0 || nx==0 || ny==height-1 || nx==width-1)
			{
				if(map[ny][nx]<=h)
				{
					fail = true;
				}
			}
		}
	}
	//������ ���� �帣�� �ʾҴٸ� �����ش�
	if (!fail)
	{
		ans += ret;
	}
	
}
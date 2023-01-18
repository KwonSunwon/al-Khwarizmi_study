/*
https://www.acmicpc.net/problem/2206
����: �� �μ��� �̵��ϱ�
�з�: �ʺ�켱Ž��
���̵�: ���3

���� ���� Ǯ��:
�ʺ�켱Ž��
��纮�� �ѹ��� �����غ��鼭 Ž��
�ð��ʰ�

�ι�° ����Ǯ��:
�������� �ʱ�ȭ�ϴ� ��� memset�� �����
�ð��ʰ�

����°:
�����Խ��ǿ��� �ð��ʰ��� ���� ���� ����
��纮�� n^2���� ã�°�� ���� �� ã�´� �ϰ�,
���� �������� �������� ���� 3�����迭�̶�� ��Ʈ�� ����
->�ذ� �� 100%���� Ʋ�Ƚ��ϴ� ��

�׹�°: 1,1 ũ��� ��������� ���� ����-> ���� Ư�������̽��� ó��

*/

#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAX 1001

int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0};

//visited�� �湮��, level�� ��� üũ
int visited[MAX][MAX][2] = {0};
string map[MAX];

int height, width;

int BFS();

int main()
{
	cin >> height >> width;

	for (int i = 0; i < height; ++i)
		cin >> map[i];

	if (height == 1 && width == 1)
		cout << 1;
	else
		cout << BFS();

}


int BFS()
{
	//((y,x),isbreak) ������ ���� ����
	//isBreak�� 0 �̶�� ���� ���� ���� ���� ����
	//1�̶�� ���� �� �� ���� ����
	queue<pair<pair<int, int>,int>> q;
	q.push(make_pair(make_pair(0,0),false));
	visited[0][0][0] = 1;
	

	while (!q.empty())
	{
		pair<int, int> nowPos = q.front().first;
		bool isBrake = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = nowPos.first + dy[i];
			int nx = nowPos.second + dx[i];
			if (ny < 0 || nx < 0 || ny >= height || nx >= width)
				continue;

			//���� �ִµ� ���� ���� �������� ���ٸ� ���� ���� �迭�� �Ѿ
			if (map[ny][nx] == '1' && isBrake==0)
			{
				q.push(make_pair(make_pair(ny, nx),isBrake + 1));
				visited[ny][nx][1] = visited[nowPos.first][nowPos.second][0] + 1;
			}

			//�� �� �ִ� ���̶�� ���� ���� �迭�� �Ѿ
			if (map[ny][nx]=='0' && visited[ny][nx][isBrake] == 0)
			{
				q.push(make_pair(make_pair(ny, nx), isBrake));
				visited[ny][nx][isBrake] = visited[nowPos.first][nowPos.second][isBrake] + 1;
			}

			//�����ϸ� �� ����
			if (ny == height - 1 && nx == width - 1)
				return visited[ny][nx][isBrake];
		}
	}

	return -1;
}
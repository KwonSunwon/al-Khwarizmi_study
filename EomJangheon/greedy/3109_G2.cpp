/*
https://www.acmicpc.net/problem/3109
����: ����
�з�: �׸��� �˰���
���̵�: ��� 2

���� ���� Ǯ��:
1. �ִ��� �������� ���� ������ �Ѵ�.
2. ���� �켱���� ��, ���, �Ʒ� ������
3. ���� �켱 Ž���� �����Ѵ�.(�Ұ����� ��ġ�� ����ġ��)
���� �������� ����
*/

#include<iostream>
using namespace std;

void dfs(int y,int x);
bool checkPossible(int y, int x);
bool isComplite = false;

int dy[3] = { -1,0,1 };
int width = 0;
int height = 0;
int ans = 0;
string map[10001];
int main()
{
	cin >> height >> width;
	
	for (int i = 0; i < height; ++i)
		cin >> map[i];

	//�� ��� �ѹ��� ���̿켱 Ž���� �����Ѵ�.
	for (int i = 0; i < height; ++i)
	{
		isComplite = false;
		dfs(i, 0);
	}

	cout << ans;
}

//���� �켱 Ž��
void dfs(int y,int x)
{
	//������� ������ Ž���Ѱ�� ����
	//���ǹ��� ������ ���ֱ� ���� �÷��� ����
	if (x == width)
	{
		isComplite = true;
		ans++;
		return;
	}

	for (int i = 0; i < 3; ++i)
	{
		//��, ���, �Ʒ� ������ �켱���� �ְ�
		//�˻��� �����ϸ� ���� ���̷� ����.
		//���� ������ �����ٸ� �Լ��� �������ش�.
		if (checkPossible(y+dy[i],x+1))
		{
			map[y + dy[i]][x + 1] = 'x';
			dfs(y + dy[i], x + 1);
			if (isComplite)
				return;
		}
	}
}

//���� ��ǥ�� ���� �� �� �ִ��� �˻�
bool checkPossible(int y, int x)
{
	if (y < 0)
		return false;

	if (y >= height)
		return false;

	if (map[y][x] == 'x')
		return false;

	return true;
}
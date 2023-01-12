/*
https://www.acmicpc.net/problem/14268
����: ȸ�� ��ȭ 2
�з�: ���� �켱 Ž��
���̵�: �÷� 3

���� ���� Ǯ��:
������ 1�϶� ��� Ʈ���� �������ְ�, ������ 2�϶� �ٷ� ����Ѵ�.
�ð��ʰ�

�ι�° ����:
������ 1�϶��� �ش� �������� �������ְ�, ������ 2�϶� �ѹ��� ������, ����Ѵ�
�ð��ʰ�

����° ����:
�˰��� �з��� ���Ϸ���� ��ũ���� Ȯ���߰� �˻��ؼ� �����ߴ�.
https://garrrruii.tistory.com/57 ������ ��α�
�ð��ʰ��� ���Դ�. �������� ������ ������ ���� �ð��� ��ƸԴ´�

����Ʈ�� ���� ����Ʈ
https://www.acmicpc.net/blog/view/21
����Ʈ���� �̿��ϸ� ���� �������� ���� ������ ó�� �����ϴ�.

*/
#pragma warning(disable:4996)
#include<iostream>
#include<vector>
using namespace std;

vector<int> graph[100001];
int fen[100001];
int in[100001];
int out[100001];
int cnt = 0;

void dfs(int cur);

void upd_(int i, int j, int x) {
	while (i < cnt)
	{
		fen[i] += x;
		i += (i & -i);
	}
	while (j < cnt)
	{
		fen[j] -= x;
		j += (j & -j);
	}
}

int sum_(int i) {
	int ret = 0;
	while (i)
	{
		ret += fen[i];
		i -= (i & -i);
	}
	return ret;
}

int main()
{
	int nodeNum,queryNum;
	int tempInput;
	cin >> nodeNum >> queryNum;
	for (int i = 1; i <= nodeNum; ++i)
	{
		scanf("%d", &tempInput);
		graph[tempInput].emplace_back(i);
	}

	dfs(1); ++cnt;

	int query, employee, score;
	for (int i = 0; i < queryNum; ++i)
	{
		scanf("%d", &query);
		if (query == 1)
		{
			scanf("%d %d", &employee, &score);
			upd_(in[employee], out[employee] + 1, score);

			/*for (int i = 1; i <= nodeNum; ++i)
				printf("%d ", fen[i]);
			cout << endl;*/
		}
		else
		{
			scanf("%d", &employee);
			printf("%d\n", sum_(in[employee]));
		}
	}
	
}

void dfs(int nowNode)
{
	cnt++;
	in[nowNode] = cnt;
	for (int i = 0; i < graph[nowNode].size(); ++i)
	{
		dfs(graph[nowNode][i]);
	}
	out[nowNode] = cnt;
}

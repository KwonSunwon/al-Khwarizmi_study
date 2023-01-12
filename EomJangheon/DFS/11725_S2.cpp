/*
https://www.acmicpc.net/problem/11725
����: Ʈ���� �θ� ã��
�з�: ���� �켱 Ž��
���̵�: �ǹ� 2

���� ���� Ǯ��:
�켱 �׷����� �����
1������ ���̿켱 Ž������ ���� ����� �θ� ���ٸ�
���� ��尡 �θ� �ǰ�, �θ� �ִٸ� �ٽ� �ٸ� ���� �Ѿ��.
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> tree[100001];
int answer[100001];

void dfs(int nowNode);


int main()
{
	int nodeNum;
	answer[1] = 1;
	cin >> nodeNum;

	int tempFirst, tempSecond;
	for (int i = 0; i < nodeNum - 1; ++i)
	{
		cin >> tempFirst >> tempSecond;
		tree[tempFirst].push_back(tempSecond);
		tree[tempSecond].push_back(tempFirst);
	}
	dfs(1);
	for (int i = 2; i <= nodeNum; ++i)
	{
		printf("%d\n", answer[i]);
	}

}

void dfs(int nowNode)
{

	for (int i = 0; i < tree[nowNode].size(); ++i)
	{
		int nextNode = tree[nowNode][i];
		if (answer[nextNode] == 0)
		{
			answer[nextNode] = nowNode;
			dfs(nextNode);
		}
	}
}

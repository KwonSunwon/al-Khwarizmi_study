/*
https://www.acmicpc.net/problem/1967
����: Ʈ���� ����
�з�: ���� �켱 Ž��
���̵�: ��� 4

���� ���� Ǯ��:
�� ��帶�� edge�� ���� ������ ��������� �־��ش�(node, edge)��
�׸��� ��� ��带 Ž���ϸ� ���� �� �Ÿ��� ã�´�.
*/
#pragma warning(disable:4996)
#include<iostream>
#include<vector>
using namespace std;

int nowWeight = 0;
int answer = 0;
vector<pair<int,int>> graph[10001];
bool visited[10001] = { false };

void dfs(int nowNode);


int main()
{
	int nodeNum;

	cin >> nodeNum;

	//�Է�
	int tempFirst, tempSecond, weight;
	for (int i = 0; i < nodeNum-1; ++i)
	{
		scanf("%d %d %d", &tempFirst, &tempSecond, &weight);
		graph[tempFirst].push_back(make_pair(tempSecond, weight));
		graph[tempSecond].push_back(make_pair(tempFirst, weight));
	}

	//��� ��忡 ���ؼ� dfs
	for (int i = 1; i <= nodeNum; ++i)
	{
		nowWeight = 0;
		for (int i = 0; i <= nodeNum; ++i)
			visited[i] = false;

		dfs(i);
	}

	cout << answer;
	
}

void dfs(int nowNode)
{
	//�湮�� üũ�ϰ�, �ִ�Ÿ� ������ �����ϴٸ� �Ѵ�.
	visited[nowNode] = true;
	if (answer < nowWeight)
		answer = nowWeight;
	//nowNode�� ��� ���� ��带 �湮�Ѵ�.
	for (int i = 0; i < graph[nowNode].size(); ++i)
	{
		int nextNode = graph[nowNode][i].first;
		int nextWeight = graph[nowNode][i].second;
		if (!visited[nextNode])
		{
			//���� ����ġ�� ���ϰ�, �ٽ� ���ƿԴٸ� ����ġ�� ���ش�.
			nowWeight += nextWeight;
			dfs(nextNode);
			nowWeight -= nextWeight;
		}
	}
}

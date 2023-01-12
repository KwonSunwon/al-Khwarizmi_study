/*
https://www.acmicpc.net/problem/1167
����: Ʈ���� ����
�з�: ���� �켱 Ž��
���̵�: ��� 2

���� ���� Ǯ��:
�� ��帶�� edge�� ���� ������ ��������� �־��ش�(node, edge)��
�׸��� ��� ��带 Ž���ϸ� ���� �� �Ÿ��� ã�´�.
->�ð��ʰ�

�ι�° ���� Ǯ��:
cache�� ����� dp������� Ǭ��.
100001*100001 �迭�� �ʹ� ũ��.. �޸� �ʰ�
�׷��� ���ͷ� ���ǥ��?
->������尡 �ʹ� ũ��.

����° ����:
������� �����ΰ�? scanf printf ���� ������ �ֱ��ϳ�,
��� 4�������� 1�ʿ� ����� ����� ���Դ�.. �Է��� 10���̴� �ּ� O(n^2)�̻���
�����α׷����� ������� �ǹ� ����δ�

����
���� ����Ʈ:
https://moonsbeen.tistory.com/101
Ʈ���� ������ ���ϴ� �����, ������ �� �������� ���� �� ��带 ���ѵ�(���� �ܰ���带 ã�°�)
�� �ܰ���忡�� ���� �� ������ ã���� ������ �ȴ�.
*/
#pragma warning(disable:4996)
#include<iostream>
#include<vector>
using namespace std;
int outSideNode = 0;
int nowWeight = 0;
int answer = 0;
vector<pair<int, int>> graph[100001];
bool visited[100001] = { false };

void dfs(int nowNode);


int main()
{
	int nodeNum;

	cin >> nodeNum;

	//�Է�
	int tempFirst ,weight;
	int nowNodeNum;
	for (int i = 1; i <= nodeNum; ++i)
	{
		scanf("%d", &nowNodeNum);
		while (true)
		{
			scanf("%d", &tempFirst);
			if (tempFirst == -1) break;

			scanf("%d", &weight);

			graph[tempFirst].push_back(make_pair(nowNodeNum, weight));
			graph[nowNodeNum].push_back(make_pair(tempFirst, weight));
		}
	}
	dfs(1);
	nowWeight = 0;
	for (int i = 0; i <= nodeNum; ++i)
		visited[i] = false;

	dfs(outSideNode);

	cout << answer;

}

void dfs(int nowNode)
{
	visited[nowNode] = true;
	if (answer < nowWeight)
	{
		answer = nowWeight;
		outSideNode = nowNode;
	}
	for (int i = 0; i < graph[nowNode].size(); ++i)
	{
		int nextNode = graph[nowNode][i].first;
		int nextWeight = graph[nowNode][i].second;
		if (!visited[nextNode])
		{
			nowWeight += nextWeight;
			dfs(nextNode);
			nowWeight -= nextWeight;
		}
	}
}

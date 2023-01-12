/*
https://www.acmicpc.net/problem/11725
제목: 트리의 부모 찾기
분류: 깊이 우선 탐색
난이도: 실버 2

최초 접근 풀이:
우선 그래프를 만들고
1번부터 깊이우선 탐색으로 다음 노드의 부모가 없다면
현재 노드가 부모가 되고, 부모가 있다면 다시 다른 노드로 넘어간다.
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

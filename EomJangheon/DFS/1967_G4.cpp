/*
https://www.acmicpc.net/problem/1967
제목: 트리의 지름
분류: 깊이 우선 탐색
난이도: 골드 4

최초 접근 풀이:
각 노드마다 edge에 대한 정보를 양방향으로 넣어준다(node, edge)로
그리고 모든 노드를 탐색하며 가장 긴 거리를 찾는다.
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

	//입력
	int tempFirst, tempSecond, weight;
	for (int i = 0; i < nodeNum-1; ++i)
	{
		scanf("%d %d %d", &tempFirst, &tempSecond, &weight);
		graph[tempFirst].push_back(make_pair(tempSecond, weight));
		graph[tempSecond].push_back(make_pair(tempFirst, weight));
	}

	//모든 노드에 대해서 dfs
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
	//방문을 체크하고, 최대거리 갱신이 가능하다면 한다.
	visited[nowNode] = true;
	if (answer < nowWeight)
		answer = nowWeight;
	//nowNode의 모든 다음 노드를 방문한다.
	for (int i = 0; i < graph[nowNode].size(); ++i)
	{
		int nextNode = graph[nowNode][i].first;
		int nextWeight = graph[nowNode][i].second;
		if (!visited[nextNode])
		{
			//다음 가중치를 더하고, 다시 돌아왔다면 가중치를 빼준다.
			nowWeight += nextWeight;
			dfs(nextNode);
			nowWeight -= nextWeight;
		}
	}
}

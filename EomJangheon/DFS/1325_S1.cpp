/*
https://www.acmicpc.net/problem/1325
제목: 효율적인 해킹
분류: 깊이 우선 탐색
난이도: 실버 1

최초 접근 풀이:
우선 그래프를 만든뒤,
1번 컴퓨터부터 깊이우선 탐색으로 해킹 가능한 컴퓨터 수를 저장,
n번 컴퓨터까지 진행하며 정답을 채운다.
*/
#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> graph[10001];
vector<int> answer;
int cache[10001] = {0};
int maxNum = 0;
int nowNum = 0;
bool complete = false;
bool visited[10001] = {false};

void dfs(int nowNode);


int main()
{
	int nodeNum,edgeNum;

	cin >> nodeNum>>edgeNum;

	int tempFirst, tempSecond;
	for (int i = 0; i < edgeNum; ++i)
	{
		scanf("%d %d", &tempFirst, &tempSecond);
		graph[tempSecond].push_back(tempFirst);
	}
	for (int i = 1; i <= nodeNum; ++i)
	{
		nowNum = 0;
		for (int i = 1; i <= nodeNum; ++i)
			visited[i] = false;
		dfs(i);
		cache[i] = nowNum;
		if (nowNum > maxNum)
		{
			maxNum = nowNum;
			answer.clear();
			answer.push_back(i);
		}
		else if (nowNum == maxNum)
			answer.push_back(i);
	}
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); ++i)
	{
		printf("%d ", answer[i]);
	}
	

}

void dfs(int nowNode)
{
	visited[nowNode] = true;
	for (int i = 0; i < graph[nowNode].size(); ++i)
	{
		int nextNode = graph[nowNode][i];
		if (!visited[nextNode])
		{
			nowNum++;
			dfs(nextNode);
		}		
	}
}

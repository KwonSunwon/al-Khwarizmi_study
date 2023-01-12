/*
https://www.acmicpc.net/problem/1167
제목: 트리의 지름
분류: 깊이 우선 탐색
난이도: 골드 2

최초 접근 풀이:
각 노드마다 edge에 대한 정보를 양방향으로 넣어준다(node, edge)로
그리고 모든 노드를 탐색하며 가장 긴 거리를 찾는다.
->시간초과

두번째 접근 풀이:
cache를 만들어 dp방식으로 푼다.
100001*100001 배열은 너무 크다.. 메모리 초과
그러면 백터로 경로표시?
->오버헤드가 너무 크다.

세번째 접근:
입출력의 문제인가? scanf printf 보다 빠른게 있긴하나,
골드 4문제에서 1초에 가까운 결과가 나왔다.. 입력이 10배이니 최소 O(n^2)이상인
이프로그램에선 입출력은 의미 없어보인다

실패
참고 사이트:
https://moonsbeen.tistory.com/101
트리의 지름을 구하는 방법은, 임의의 한 지점에서 가장 먼 노드를 구한뒤(가장 외곽노드를 찾는것)
그 외곽노드에서 가장 먼 지점을 찾으면 지름이 된다.
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

	//입력
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

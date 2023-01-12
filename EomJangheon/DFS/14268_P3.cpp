/*
https://www.acmicpc.net/problem/14268
제목: 회사 문화 2
분류: 깊이 우선 탐색
난이도: 플레 3

최초 접근 풀이:
쿼리가 1일때 모든 트리를 갱신해주고, 쿼리가 2일때 바로 출력한다.
시간초과

두번째 접근:
쿼리가 1일때는 해당 직원에만 저장해주고, 쿼리가 2일때 한번에 갱신후, 출력한다
시간초과

세번째 접근:
알고리즘 분류에 오일러경로 테크닉을 확인했고 검색해서 공부했다.
https://garrrruii.tistory.com/57 공부한 블로그
시간초과가 나왔다. 순차적인 증가는 여전히 많은 시간을 잡아먹는다

펜윅트리 공부 사이트
https://www.acmicpc.net/blog/view/21
펜윅트리를 이용하면 적은 연산으로 많은 쿼리를 처리 가능하다.

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

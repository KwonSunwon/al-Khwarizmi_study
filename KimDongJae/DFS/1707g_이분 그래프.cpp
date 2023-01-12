/*
1번 접근 : DFS로 탐색하면서 두 개의 집합에 번갈아가며 넣고, 이미 방문한 정점의 경우 one 혹은 two를 검사해 이분 그래프의 조건이 벗어나면 NO

벡터의 벡터 사용, 방문한 노드는 set으로 정리

문제 : 시간 초과남 일단 cout, cin을 바꿔보고 DFS를 중간에 거짓이라 판별되면 멈출 방법을 찾는게 좋을 듯
     ==> scanf printf 해도 시간초과 남 더 빠른 방법은 없을까?

	 간선이 추가될때 확인하는 방법은 없을까? <== 실패, 간선이 추가될때 둘다 방문 안한 경우, 한곳만 한 경우, 둘 다 한경우를 나눠 처리했으나
	 이미 방문한 적 있는 노드끼리 연결할 때 문제 발생 ex) (1,2) (4,3) (2,3)

	 결국 시간 초과를 해결하는게 관건..인데 이건 잘 모르겠다.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

set<int> visited;
set<int> one, two;
bool res;

void DFS(int, vector<vector<int>>, int);

int main() {
	int case_EA{ 0 };
	vector<bool> result;
	scanf("%d", &case_EA);

	for (int c = 0; c < case_EA; ++c) {
		int vertex, edge;
		vector<vector<int>> edge_list;
		res = true;

		scanf("%d %d", &vertex, &edge);

		for (int i = 0; i < vertex; ++i) {
			vector<int> temp;
			edge_list.emplace_back(temp);
		}

		for (int i = 0; i < edge; ++i) {
			int start, end;
			scanf("%d %d", &start, &end);
			
			start--;
			end--;
			edge_list[start].emplace_back(end);
			edge_list[end].emplace_back(start);
		}

		DFS(0, edge_list, 1);

		result.emplace_back(res);

		visited.clear();
		one.clear();
		two.clear();
	}

	for (int i = 0; i < result.size(); ++i) {
		if (result[i]) printf("YES\n");

		else printf("NO\n");
	}
}


void DFS(int vertex, vector<vector<int>> edges, int group) {
	if (!res) return;

	if (visited.count(vertex)) {
		if (group == 1 && two.count(vertex)) {
			res = false;
		}

		else if(group == 2 && one.count(vertex)) {
			res = false;
		}
		return;
	}

	visited.insert(vertex);

	if (group == 1) 
		one.insert(vertex);
	else 
		two.insert(vertex);

	for (int i = 0; i < edges[vertex].size(); ++i) {
		if (group == 1)
			DFS(edges[vertex][i], edges, 2);
		else
			DFS(edges[vertex][i], edges, 1);
	}
}
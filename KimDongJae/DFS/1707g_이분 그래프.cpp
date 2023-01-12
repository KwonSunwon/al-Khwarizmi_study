/*
1�� ���� : DFS�� Ž���ϸ鼭 �� ���� ���տ� �����ư��� �ְ�, �̹� �湮�� ������ ��� one Ȥ�� two�� �˻��� �̺� �׷����� ������ ����� NO

������ ���� ���, �湮�� ���� set���� ����

���� : �ð� �ʰ��� �ϴ� cout, cin�� �ٲ㺸�� DFS�� �߰��� �����̶� �Ǻ��Ǹ� ���� ����� ã�°� ���� ��
     ==> scanf printf �ص� �ð��ʰ� �� �� ���� ����� ������?

	 ������ �߰��ɶ� Ȯ���ϴ� ����� ������? <== ����, ������ �߰��ɶ� �Ѵ� �湮 ���� ���, �Ѱ��� �� ���, �� �� �Ѱ�츦 ���� ó��������
	 �̹� �湮�� �� �ִ� ��峢�� ������ �� ���� �߻� ex) (1,2) (4,3) (2,3)

	 �ᱹ �ð� �ʰ��� �ذ��ϴ°� ����..�ε� �̰� �� �𸣰ڴ�.
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
// Created by KwonSunwon on 2023-01-07.
// Title: 바이러스
// Rating: S3
// Link: https://www.acmicpc.net/problem/2606
// Language: C++20

// union find
/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int, int>> edges;
int *parents;

int find_parent(int x);
void union_find(int a, int b);

int main()
{
    int vertex, edge;
    scanf("%d %d", &vertex, &edge);

    parents = new int[vertex + 1];
    for (int i = 1; i < vertex + 1; i++)
        parents[i] = i;

    for (int i = 0; i < edge; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        edges.push({a, b});
    }

    while (!edges.empty())
    {
        pair<int, int> edge = edges.front();
        edges.pop();

        union_find(edge.first, edge.second);
    }

    int infected = 0;
    for (int i = 2; i < vertex + 1; i++)
    {
        if (find_parent(i) == 1)
            infected++;
    }

    printf("%d", infected);

    return 0;
}

int find_parent(int x)
{
    if (x != parents[x])
        parents[x] = find_parent(parents[x]);
    return parents[x];
}

void union_find(int a, int b)
{
    int aParent = find_parent(a);
    int bParent = find_parent(b);

    if (aParent > bParent)
    {
        int temp = aParent;
        aParent = bParent;
        bParent = temp;
    }

    parents[bParent] = aParent;
}
*/

// dfs
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int v, e;
bool *visited;
vector<set<int>> adjList;
int infected = 0;

void dfs(int current);

int main()
{
    scanf("%d %d", &v, &e);

    adjList.resize(v + 1);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adjList[u].insert(v);
        adjList[v].insert(u);
    }

    visited = new bool[v + 1]{false};

    dfs(1);

    printf("%d", infected);

    return 0;
}

void dfs(int current)
{
    visited[current] = true;

    while (!adjList[current].empty())
    {
        set<int>::iterator iter = adjList[current].begin();
        int next = *iter;
        adjList[current].erase(iter);

        if (!visited[next])
        {
            infected++;
            dfs(next);
        }
    }
}
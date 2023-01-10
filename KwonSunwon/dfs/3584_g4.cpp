// Created by KwonSunwon on 2023-01-09.
// Title: 가장 가까운 공통 조상
// Rating: G4
// Link: https://www.acmicpc.net/problem/3584
// Language: C++20

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, bool>> tree;
int n, a, b;
int root;
int ancestor;
bool findChild;

void input();
void dfs(int node);
int find_ancestor();

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
        printf("%d\n", find_ancestor());

    return 0;
}

void input()
{
    scanf("%d", &n);

    tree.resize(n + 1);

    for (int i = 1; i < n + 1; i++)
        tree[i].second = false;

    for (int i = 0; i < n - 1; i++)
    {
        int parent, child;
        scanf("%d %d", &parent, &child);
        tree[child].first = parent;
    }

    scanf("%d %d", &a, &b);

    for (int i = 1; i < n + 1; i++)
        if (!tree[i].first)
        {
            root = i;
            break;
        }
}

void dfs(int node)
{
    if (findChild)
        if (tree[node].second)
        {
            ancestor = node;
            return;
        }

    tree[node].second = true;
    if (node == root)
        return;
    dfs(tree[node].first);
}

int find_ancestor()
{
    input();

    dfs(a);
    findChild = true;

    dfs(b);

    tree.clear();

    return ancestor;
}
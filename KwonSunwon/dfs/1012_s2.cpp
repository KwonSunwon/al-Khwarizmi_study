// Created by KwonSunwon on 2023-01-09.
// Title: 유기농 배추
// Rating: S2
// Link: https://www.acmicpc.net/problem/1012
// Language: C++20

#include <iostream>
#include <vector>

using namespace std;

int m, n;
vector<vector<bool>> map;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool is_safe(int x, int y);

void input();
bool dfs(int x, int y);
int count_earthworm();

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
        printf("%d\n", count_earthworm());

    return 0;
}

bool is_safe(int x, int y)
{
    if (x < 0 || x > m - 1 || y < 0 || y > n - 1)
        return false;
    return true;
}

void input()
{
    int k;
    scanf("%d %d %d", &m, &n, &k);

    map.resize(n);
    for (int i = 0; i < n; i++)
        map[i].resize(m);

    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
            map[y][x] = false;

    for (int i = 0; i < k; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        map[y][x] = true;
    }
}

bool dfs(int x, int y)
{
    if (!is_safe(x, y))
        return false;
    if (!map[y][x])
        return false;

    map[y][x] = false;

    for (int i = 0; i < 4; i++)
        dfs(x + dx[i], y + dy[i]);

    return true;
}

int count_earthworm()
{
    input();

    int worm = 0;

    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
            if (dfs(x, y))
                worm++;

    for (int i = 0; i < n; i++)
        map[i].clear();
    map.clear();

    return worm;
}

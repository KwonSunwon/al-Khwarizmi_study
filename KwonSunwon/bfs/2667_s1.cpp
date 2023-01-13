/*
Create by KwonSunwon on 2023-01-13.
Title: 단지번호붙이기
Rating: S1
Link: https://www.acmicpc.net/problem/2667
Language: C++20
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> map;
queue<pair<int, int>> que;
int cnt;
vector<int> complex;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool is_safe(int y, int x);
bool bfs();

int main()
{
    scanf("%d", &n);
    map.resize(n);
    for (int y = 0; y < n; y++)
    {
        map[y].resize(n);
        for (int x = 0; x < n; x++)
            scanf("%1d", &map[y][x]);
    }

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (!map[y][x])
                continue;
            que.push({y, x});
            cnt = 0;
            if (bfs())
                complex.push_back(cnt);
        }
    }

    sort(complex.begin(), complex.end());
    printf("%d\n", complex.size());
    for (int i = 0; i < complex.size(); i++)
        printf("%d\n", complex[i]);

    return 0;
}

bool is_safe(int y, int x)
{
    if (y < 0 || y > n - 1 || x < 0 || x > n - 1)
        return false;
    return true;
}

bool bfs()
{
    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        if (!map[y][x])
            continue;

        map[y][x] = false;
        cnt++;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (is_safe(ny, nx))
                que.push({ny, nx});
        }
    }

    if (cnt)
        return true;
    return false;
}
// Created by KwonSunwon on 2023-01-08.
// Title: 양 한마리... 양 두마리...
// Rating: S2
// Link: https://www.acmicpc.net/problem/11123
// Language: C++20

#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> flock;
int h, w;
int flockCount;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool is_safe(int x, int y);
bool dfs(int x, int y);
int count_sheep();

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
        printf("%d\n", count_sheep());

    return 0;
}

bool is_safe(int x, int y)
{
    if (x < 0 || x > w - 1 || y < 0 || y > h - 1)
        return false;
    return true;
}

bool dfs(int x, int y)
{
    if (!is_safe(x, y))
        return false;

    if (flock[y][x] == '.')
        return false;

    flock[y][x] = '.';

    for (int i = 0; i < 4; i++)
        dfs(x + dx[i], y + dy[i]);

    return true;
}

int count_sheep()
{
    scanf("%d %d", &h, &w);

    flock.resize(h);

    for (int y = 0; y < h; y++)
    {
        flock[y].resize(w);
        for (int x = 0; x < w; x++)
        {
            char temp = cin.get();
            if (temp == '\n')
                temp = cin.get();
            flock[y][x] = temp;
        }
    }

    flockCount = 0;

    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            if (dfs(x, y))
                flockCount++;

    // 모든 과정 끝난 후 양떼 배열 초기화
    for (int i = 0; i < h; i++)
        flock[i].clear();
    flock.clear();

    return flockCount;
}
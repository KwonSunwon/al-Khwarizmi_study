// Created by KwonSunwon on 2023-01-09.
// Title: 빙산
// Rating: G4
// Link: https://www.acmicpc.net/problem/2573
// Language: C++20

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct MeltInfo
{
    int x, y;
    int melt_count;
};

int n, m;
vector<vector<pair<int, bool>>> map;
int year;
int icebergCount;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void melt();
bool check_split_iceberg();
bool dfs(int x, int y);

int main()
{
    scanf("%d %d", &n, &m);

    map.resize(n);
    for (int i = 0; i < n; i++)
        map[i].resize(m);

    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
        {
            scanf("%d", &map[y][x].first);
            map[y][x].second = false;
        }

    year = 0;
    do
    {
        melt();
        year++;
    } while (!check_split_iceberg());

    if (icebergCount)
        printf("%d", year);
    else
        printf("%d", 0);

    return 0;
}

void melt()
{
    vector<MeltInfo> meltInfo;

    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
        {
            map[y][x].second = false;

            if (!map[y][x].first)
                continue;

            int meltCount = 0;
            for (int i = 0; i < 4; i++)
                if (!map[y + dy[i]][x + dx[i]].first)
                    meltCount++;

            if (meltCount)
                meltInfo.push_back({x, y, meltCount});
        }

    for (int i = 0; i < meltInfo.size(); i++)
        map[meltInfo[i].y][meltInfo[i].x].first = max(0, map[meltInfo[i].y][meltInfo[i].x].first - meltInfo[i].melt_count);
}

bool check_split_iceberg()
{
    icebergCount = 0;
    bool isIcebergSplit = false;

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (dfs(x, y))
                icebergCount++;

            if (icebergCount >= 2)
            {
                isIcebergSplit = true;
                break;
            }
        }
        if (isIcebergSplit)
            break;
    }

    if (isIcebergSplit || !icebergCount)
        return true;
    return false;
}

bool dfs(int x, int y)
{
    if (!map[y][x].first || map[y][x].second)
        return false;

    map[y][x].second = true;

    for (int i = 0; i < 4; i++)
        dfs(x + dx[i], y + dy[i]);

    return true;
}
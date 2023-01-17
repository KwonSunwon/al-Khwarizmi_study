/*
Create by KwonSunwon on 2023-01-15.
Title: 토마토
Rating: G1
Link: https://www.acmicpc.net/problem/7576
Language: C++20
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> box;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool is_safe(int y, int x);

int main()
{
    scanf("%d %d", &n, &m);

    box.resize(m, vector<int>(n, 0));
    for (int y = 0; y < m; y++)
        for (int x = 0; x < n; x++)
            scanf("%d", &box[y][x]);

    queue<pair<int, int>> q;
    for (int y = 0; y < m; y++)
        for (int x = 0; x < n; x++)
            if (box[y][x] == 1)
                q.push({y, x});

    // bfs
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (is_safe(ny, nx) && box[ny][nx] == 0)
            {
                box[ny][nx] = box[y][x] + 1; // 시간을 저장
                q.push({ny, nx});
            }
        }
    }

    int max = 0;
    for (int y = 0; y < m; y++)
        for (int x = 0; x < n; x++)
            if (box[y][x] == 0)
            {
                printf("-1");
                return 0;
            }
            else if (box[y][x] > max)
                max = box[y][x];

    printf("%d", max - 1);

    return 0;
}

bool is_safe(int y, int x)
{
    return (y >= 0 && y < m && x >= 0 && x < n);
}
// Created by KwonSunwon on 2023-01-07.
// Title: 숫자판 점프
// Rating: S2
// Link: https://www.acmicpc.net/problem/2210
// Language: C++20

#include <iostream>
#include <set>
#include <string>

using namespace std;

int map[5][5];
set<string> numbers;
int mx[4] = {-1, 0, 1, 0};
int my[4] = {0, -1, 0, 1};

void dfs(int x, int y, string num);
bool is_safe(int x, int y);

int main()
{
    for (int y = 0; y < 5; y++)
        for (int x = 0; x < 5; x++)
        {
            int temp;
            scanf("%d", &temp);
            map[y][x] = temp;
        }

    for (int y = 0; y < 5; y++)
        for (int x = 0; x < 5; x++)
            dfs(x, y, "");

    printf("%d", numbers.size());

    return 0;
}

void dfs(int x, int y, string num)
{
    if (!is_safe(x, y))
        return;

    num += map[y][x];

    if (num.size() == 6)
        numbers.insert(num);

    for (int i = 0; i < 4; i++)
        dfs(x + mx[i], y + my[i], num);
}

bool is_safe(int x, int y)
{
    if (x < 0 || x > 4 || y < 0 || y > 4)
        return false;
    return true;
}
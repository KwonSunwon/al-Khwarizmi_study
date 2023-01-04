// Created by KwonSunwon on 2023-01-03.
// Title: 도영이가 만든 맛있는 음식
// Rating: S2
// Link: https://www.acmicpc.net/problem/2961
// Language: C++20

#include <iostream>

using namespace std;

int N;
int S[10];
int B[10];
int min_diff = 1000000000;

void dfs(int idx, int s, int b);

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &S[i], &B[i]);
    }

    dfs(0, 1, 0);

    printf("%d", min_diff);

    return 0;
}

void dfs(int idx, int s, int b)
{
    if (idx == N)
    {
        if (s == 1 && b == 0)
            return;

        int diff = abs(s - b);
        if (diff < min_diff)
            min_diff = diff;

        return;
    }

    dfs(idx + 1, s * S[idx], b + B[idx]);
    dfs(idx + 1, s, b);
}
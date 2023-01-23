/*
Created by kwonSunwon on 2023-01-
Title: 소형기관차
Rating: G3
Link: https://www.acmicpc.net/problem/2616
Language: C++20
*/

#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int people[50001];
int dp[4][50001];

int main()
{
    scanf("%d", &n);

    for (int i = 1; i < n + 1; i++)
    {
        scanf("%d", &people[i]);
        people[i] += people[i - 1];
    }

    scanf("%d", &k);

    for (int i = 1; i < 4; i++)
    {
        for (int j = k; j < n + 1; j++)
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - k] + people[j] - people[j - k]);
    }

    printf("%d", dp[3][n]);

    return 0;
}

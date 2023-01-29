/*
Create by KwonSunwon on 2023-01-29.
Title: 부녀회장이 될테야
Rating: B1
Link: https://www.acmicpc.net/problem/2775
Language: C++20
*/

#include <iostream>

using namespace std;

int k, n;
long long dp[15][15];

long long result(int k, int n);

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < 15; i++)
        dp[0][i] = i;
    for (int i = 1; i < 15; i++)
        dp[i][1] = 1;
    for (int i = 1; i < 15; i++)
        for (int j = 2; j < 15; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &k, &n);
        printf("%lld\n", dp[k][n]);
    }

    return 0;
}
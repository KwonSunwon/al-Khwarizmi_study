/*
Create by KwonSunwon on 2023-01-30.
Title: 동전 2
Rating: G5
Link: https://www.acmicpc.net/problem/2294
Language: C++20
*/

#include <iostream>

using namespace std;

int n, k;
int coin[101];
int dp[10001];

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &coin[i]);

    for (int i = 1; i < k + 1; i++)
        dp[i] = 10001;

    for (int i = 1; i < k + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coin[j] > i)
                continue;

            dp[i] = min(dp[i - coin[j]] + 1, dp[i]);
        }
    }

    if (dp[k] > 10000)
        printf("-1");
    else
        printf("%d", dp[k]);
    return 0;
}

/*
Create by KwonSunwon on 2023-01-29.
Title: 1, 2, 3 더하기
Rating: S3
Link: https://www.acmicpc.net/problem/9095
Language: C++20
*/

#include <iostream>

using namespace std;

int dp[11];

int main()
{
    int t;
    scanf("%d", &t);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i < 11; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);

        printf("%d\n", dp[n]);
    }

    return 0;
}

/*
Create by KwonSunwon on 2023-01-30.
Title: LCS
Rating: G5
Link: https://www.acmicpc.net/problem/9251
Language: C++20
*/

/*
문자열을 비교해가면서 같은 경우 dp[i][j] = dp[i][j - 1] + 1; 같은 행의 이전 값에 +1 을 하여 저장
-> 연속된 같은 값이 있을 경우를 고려하지 못함
-> 반례 : df, ffd (출력 : 2, 정답 : 1)
-> df의 f행을 비교할 때 ffd 첫 f를 만나고 1이 저장된 다음 바로 다음 f에서 이미 확인한 문자의 값을 중복으로 더하게됨

문자가 같은 경우 dp[i][j] = dp[i - 1][j - 1] + 1; 왼쪽 위 대각선 값에 +1 을 하여 저장해야함
-> 그래야 한 문자가 연속된 경우를 고려할 수 있음
*/

#include <iostream>
#include <string>

using namespace std;

int dp[1001][1001];

int main()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;

    for (int i = 1; i < s1.length() + 1; i++)
    {
        for (int j = 1; j < s2.length() + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    for (int i = 0; i < s1.length() + 1; i++)
    {
        for (int j = 0; j < s2.length() + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << dp[s1.length()][s2.length()];

    return 0;
}
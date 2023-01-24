/*
Created by kwonSunwon on 2023-01-
Title: 두 배열의 합
Rating: G3
Link: https://www.acmicpc.net/problem/2143
Language: C++20
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t, n, m;
long long result;
vector<int> a, b;
vector<int> aSum, bSum;

int main()
{
    scanf("%d", &t);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        a.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            aSum.push_back(sum);
        }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int temp;
        scanf("%d", &temp);
        b.push_back(temp);
    }
    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = i; j < m; j++)
        {
            sum += b[j];
            bSum.push_back(sum);
        }
    }

    sort(aSum.begin(), aSum.end());
    sort(bSum.begin(), bSum.end());

    for (int i = 0; i < aSum.size(); i++)
    {
        int findNum = t - aSum[i];
        auto lower = lower_bound(bSum.begin(), bSum.end(), findNum);
        auto upper = upper_bound(bSum.begin(), bSum.end(), findNum);
        result += upper - lower;
    }

    printf("%lld", result);

    return 0;
}

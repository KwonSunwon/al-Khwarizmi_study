// Created by KwonSunwon on 2023-01-03.
// Title: 한수
// Rating: S4
// Link: https://www.acmicpc.net/problem/1065
// Language: C++20

#include <iostream>

using namespace std;

bool is_hansu(int n);

int main()
{
    int n;
    int result = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        if (is_hansu(i))
            result++;
    }

    printf("%d", result);

    return 0;
}

bool is_hansu(int n)
{
    if (n < 100)
        return true;

    int a = n / 100;
    int b = (n % 100) / 10;
    int c = n % 10;

    if (a - b == b - c)
        return true;
    else
        return false;
}
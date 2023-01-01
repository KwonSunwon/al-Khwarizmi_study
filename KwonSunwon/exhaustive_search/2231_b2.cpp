// Created by KwonSunwon on 2023-01-02.
// Title: 분해합
// Rating: B2
// Link: https://www.acmicpc.net/problem/2231
// Language: C++20

#include <iostream>
#include <vector>

using namespace std;

int find_digit_sum(int);

int main()
{
    int n, result;
    scanf("%d", &n);

    result = 1;
    while (true)
    {
        int temp = find_digit_sum(result);
        if (temp == n)
            break;
        if (result == n)
        {
            result = 0;
            break;
        }
        result++;
    }

    printf("%d", result);

    return 0;
}

int find_digit_sum(int a)
{
    int result = a;

    while (a)
    {
        result += a - ((a / 10) * 10);
        a = a / 10;
    }

    return result;
}
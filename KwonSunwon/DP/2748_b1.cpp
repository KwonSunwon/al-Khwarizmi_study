/*
Create by KwonSunwon on 2023-01-29.
Title: 피보나치 수 2
Rating: B1
Link: https://www.acmicpc.net/problem/2748
Language: C++20
*/

#include <iostream>

using namespace std;

long long fibonacci[91];

int main()
{
    int n;
    scanf("%d", &n);

    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for (int i = 2; i < n + 1; i++)
    {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    printf("%lld", fibonacci[n]);

    return 0;
}
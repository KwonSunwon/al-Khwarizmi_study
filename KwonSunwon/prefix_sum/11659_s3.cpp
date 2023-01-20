/*
Create by KwonSunwon on 2023-01-21.
Title: 구간 합 구하기 4
Rating: S3
Link: https://www.acmicpc.net/problem/11659
Language: C++20
*/

#include <iostream>

using namespace std;

int n, m;
int arr[100001];

int main()
{
    scanf("%d %d", &n, &m);

    scanf("%d", &arr[0]);
    for (int i = 1; i < n; i++)
    {
        int input;
        scanf("%d", &input);
        arr[i] = input + arr[i - 1];
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a == 1)
            printf("%d\n", arr[b - 1]);
        else
            printf("%d\n", arr[b - 1] - arr[a - 2]);
    }

    return 0;
}
/*
Created by kwonSunwon on 2023-01-21
Title: 기상청 인턴 신현수
Rating: B1
Link: https://www.acmicpc.net/problem/2435
Language: C++20
*/

#include <iostream>

using namespace std;

int n, k;
int temp[100];
int maxTemp = -1000;
int sum;

int main()
{
    scanf("%d %d", &n, &k);

    scanf("%d", &temp[0]);
    for (int i = 1; i < n; i++)
    {
        int input;
        scanf("%d", &input);
        temp[i] = input + temp[i - 1];
    }

    for (int i = 0; i < n - k + 1; i++)
    {
        if (i == 0)
            sum = temp[i + k - 1];
        else
            sum = temp[i + k - 1] - temp[i - 1];
        if (sum > maxTemp)
            maxTemp = sum;
    }

    printf("%d", maxTemp);

    return 0;
}
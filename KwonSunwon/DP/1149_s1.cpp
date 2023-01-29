/*
Create by KwonSunwon on 2023-01-30.
Title: RGB거리
Rating: S1
Link: https://www.acmicpc.net/problem/1149
Language: C++20
*/

#include <iostream>

using namespace std;

int n;
int rgb[1001][3];

int main()
{
    scanf("%d", &n);

    rgb[0][0] = 0;
    rgb[0][1] = 0;
    rgb[0][2] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        int r, g, b;
        scanf("%d %d %d", &r, &g, &b);

        rgb[i][0] = min(rgb[i - 1][1], rgb[i - 1][2]) + r;
        rgb[i][1] = min(rgb[i - 1][0], rgb[i - 1][2]) + g;
        rgb[i][2] = min(rgb[i - 1][0], rgb[i - 1][1]) + b;
    }

    int min = 1000000;
    for (int i = 0; i < 3; i++)
    {
        if (rgb[n][i] < min)
            min = rgb[n][i];
    }

    printf("%d", min);

    return 0;
}
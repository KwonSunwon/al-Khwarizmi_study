// Created by KwonSunwon on 2022-12-22.
// Title: ATM
// Rating: S4
// Link: https://www.acmicpc.net/problem/11399
// Language: C++20

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    vector<int> P;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int buffer;
        scanf("%d", &buffer);
        P.push_back(buffer);
    }

    sort(P.begin(), P.end());

    int T = 0;

    for (int i = 0; i < N; ++i)
        T += (N - i) * P[i];

    cout << T;

    return 0;
}
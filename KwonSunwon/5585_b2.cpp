// Created by KwonSunwon on 2022-12-21.
// Title: 거스름돈
// Rating: B2
// Link: https://www.acmicpc.net/problem/5585
// Language: C++20

#include <iostream>

using namespace std;

int coins[6] = {500, 100, 50, 10, 5, 1};

int main()
{
    const int money = 1000;
    int price = 0;
    int cnt = 0;

    cin >> price;

    int changes = money - price;

    for (int coin = 0; coin < 6; ++coin)
    {
        cnt += changes / coins[coin];
        changes = changes % coins[coin];
    }

    cout << cnt;

    return 0;
}
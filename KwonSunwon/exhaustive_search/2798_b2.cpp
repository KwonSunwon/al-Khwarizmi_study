// Created by KwonSunwon on 2023-01-02.
// Title: 블랙잭
// Rating: B2
// Link: https://www.acmicpc.net/problem/2798
// Language: C++20

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, maxNumber;
    vector<int> cards;
    int result = 0;
    bool isMaxNumber = false;

    scanf("%d %d", &n, &maxNumber);

    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        cards.emplace_back(temp);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            for (int k = 0; k < n; k++)
            {
                if (j == k || i == k)
                    continue;

                int tempResult = cards[i] + cards[j] + cards[k];

                if (tempResult > result && tempResult <= maxNumber)
                    result = tempResult;

                if (result == maxNumber)
                {
                    isMaxNumber = true;
                    break;
                }
            }
            if (isMaxNumber)
                break;
        }
        if (isMaxNumber)
            break;
    }

    printf("%d", result);

    return 0;
}
/*
Created by kwonSunwon on 2023-01-21
Title: 슈퍼 마리오
Rating: B1
Link: https://www.acmicpc.net/problem/2851
Language: C++20
*/

#include <iostream>

using namespace std;

int mushroom[10];

int main()
{
    scanf("%d", &mushroom[0]);
    if (mushroom[0] >= 100)
    {
        printf("%d", mushroom[0]);
        return 0;
    }

    for (int i = 1; i < 10; i++)
    {
        int temp;
        scanf("%d", &temp);
        mushroom[i] = temp + mushroom[i - 1];

        if (mushroom[i] >= 100)
        {
            if (abs(mushroom[i] - 100) <= abs(mushroom[i - 1] - 100))
                printf("%d", mushroom[i]);
            else
                printf("%d", mushroom[i - 1]);
            return 0;
        }
    }

    printf("%d", mushroom[9]);
    return 0;
}
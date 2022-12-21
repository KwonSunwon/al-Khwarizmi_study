// Created by KwonSunwon on 2022-12-21.
// Title: 캠핑
// Rating: B1
// Link: https://www.acmicpc.net/problem/4796
// Language: C++20

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int L = 0, P = 0, V = 0;
    int caseCounter = 0;
    unsigned int result = 0;

    while (true)
    {
        scanf("%d %d %d", &L, &P, &V);
        if (!L && !P && !V)
            break;
        if (V % P < L)                  // 남은 기간이 L(사용 가능한 일수) 보다 작은 경우
            result = V / P * L + V % P; // V % P 일수를 그대로 덧셈
        else                            // 남은 기간이 L 보다 큰 경우
            result = V / P * L + L;     // 나누고 남은 일수가 아닌 L 일수만큼 덧셈
        cout << "Case " << ++caseCounter << ": " << result << "\n";
    }

    return 0;
}

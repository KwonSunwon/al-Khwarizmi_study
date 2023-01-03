// Created by KwonSunwon on 2023-01-04.
// Title: 암호 만들기
// Rating: G5
// Link: https://www.acmicpc.net/problem/1759
// Language: C++20

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int L, C;
vector<char> alpha;
priority_queue<string, vector<string>, greater<string>> passwords;

void dfs(int idx, string password, int vowel, int consonant);

int main()
{
    scanf("%d %d", &L, &C);

    for (int i = 0; i < C; i++)
    {
        char c;
        scanf(" %c", &c);
        alpha.push_back(c);
    }
    sort(alpha.begin(), alpha.end());

    for (int i = 0; i < C; i++)
        dfs(i, "", 0, 0);

    while (!passwords.empty())
    {
        printf("%s\n", passwords.top().c_str());
        passwords.pop();
    }

    return 0;
}

void dfs(int idx, string password, int vowel, int consonant)
{
    password += alpha[idx];

    if (alpha[idx] == 'a' || alpha[idx] == 'e' || alpha[idx] == 'i' || alpha[idx] == 'o' || alpha[idx] == 'u')
        vowel++;
    else
        consonant++;

    // idx가 C를 넘어가는 경우
    if (idx >= C)
        return;
    // 비밀번호가 L 개인 경우
    if (password.length() == L)
    {
        // 모음이 최소 1개, 자음이 최소 2개인 경우
        if (vowel >= 1 && consonant >= 2)
            passwords.push(password);
        return;
    }

    for (int i = 1; i < C - idx || idx + i < C; i++)
        dfs(idx + i, password, vowel, consonant);
}
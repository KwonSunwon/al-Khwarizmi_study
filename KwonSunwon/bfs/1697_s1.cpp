/*
Create by KwonSunwon on 2023-01-14.
Title: 숨바꼭질
Rating: S1
Link: https://www.acmicpc.net/problem/1697
Language: C++20
*/

#include <iostream>
#include <queue>
#include <set>

using namespace std;

int n, k;
set<int> visited;
queue<pair<int, int>> q;

void bfs(int tagger, const int target, int depth);

int main()
{
    scanf("%d %d", &n, &k);

    bfs(n, k, 0);

    return 0;
}

void bfs(int tagger, const int target, int depth)
{
    q.push({tagger, depth});
    visited.insert(tagger);

    while (!q.empty())
    {
        tagger = q.front().first;
        depth = q.front().second;
        q.pop();

        if (tagger == target)
        {
            printf("%d", depth);
            return;
        }

        if (tagger - 1 >= 0 && !visited.count(tagger - 1))
        {
            q.push({tagger - 1, depth + 1});
            visited.insert(tagger - 1);
        }
        if (tagger + 1 <= 100000 && !visited.count(tagger + 1))
        {
            q.push({tagger + 1, depth + 1});
            visited.insert(tagger + 1);
        }
        if (tagger * 2 <= 100000 && !visited.count(tagger * 2))
        {
            q.push({tagger * 2, depth + 1});
            visited.insert(tagger * 2);
        }
    }
}
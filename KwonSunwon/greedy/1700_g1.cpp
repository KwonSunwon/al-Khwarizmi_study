// Created by KwonSunwon on 2022-12-25.
// Title: 멀티탭 스케줄링
// Rating: G1
// Link: https://www.acmicpc.net/problem/1700
// Language: C++20

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct Object
{
    int id;
    bool isPlugged;
    bool isExistNextList;

    Object(int id, bool p, bool e) : id(id), isPlugged(p), isExistNextList(e) {}
};

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);

    // 멀티탭의 구의 개수가 전기용품의 수 보다 많거나 같은 경우
    if (n >= k)
    {
        printf("%d", 0); // 모든 전기용품을 멀티탭에 연결하면 해결되므로 플러그를 빼는 횟수는 0이다
        return 0;
    }

    vector<int> objectSequence;
    for (int i = 0; i < k; i++)
    {
        int temp;
        scanf("%d ", &temp);
        objectSequence.push_back(temp);
    }

    set<int> pluggedList;
    set<int>::iterator plugIter;
    vector<int>::iterator objSeqIter = objectSequence.begin();

    while (objSeqIter != objectSequence.end())
    {
        pluggedList.insert(*objSeqIter);
        objSeqIter++;

        if (pluggedList.size() <= n)
            continue;

        vector<int>::iterator tempIter = objSeqIter;

        for (tempIter; tempIter != objectSequence.end(); tempIter++)
        {
        }
    }

    return 0;
}
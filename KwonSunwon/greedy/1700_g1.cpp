// Created by KwonSunwon on 2022-12-25.
// Title: 멀티탭 스케줄링
// Rating: G1
// Link: https://www.acmicpc.net/problem/1700
// Language: C++20

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

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

    // 플러그 받는 순서를 vector로 입력받음
    vector<int> objectSequence;
    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        objectSequence.push_back(temp);
    }

    // set 구조를 이용해 꽃힌 전자용품의 인덱스를 관리(중복 허용 x, 탐색하는 시간이 짧음)
    set<int> pluggedList;

    // iterator를 이용해 seq를 탐색
    vector<int>::iterator objSeqIter = objectSequence.begin();
    vector<int>::iterator tempIter;

    int unPluggedCount = 0;

    // seq의 끝까지
    while (objSeqIter != objectSequence.end())
    {
        set<int> tempPluggedList = pluggedList; // 현재 멀티탭에 연결된 전자용품 리스트를 복사

        pluggedList.insert(*objSeqIter); // 다음에 나올 전자용품을 연결 -> set 구조이기 때문에 중복은 들어가지 않음
        objSeqIter++;                    // 다음 순서로 넘어감

        if (pluggedList.size() <= n) // 만약 연결된 전자용품이 구의 수보다 많다면
            continue;

        tempIter = objSeqIter; // 현재 순서부터 다음 전자용품들을 확인
        int pluggedCount = 0;

        for (tempIter; tempIter != objectSequence.end(); tempIter++)
        {
            if (pluggedCount == (n - 1)) // 뒤에 나오는 전자용품 중에 이미 연결된 전자용품을 찾은 수가 (구의 개수 - 1)이면 남아 있는 찾지 못한 플러그를 연결 해제
                break;
            if (tempPluggedList.count(*tempIter)) // 다음 나올 전자용품 중에 연결되어 있는 것인지 확인
            {
                pluggedCount++;
                tempPluggedList.erase(*tempIter); // 다음 나올 것이라면 임시 리스트에서 지움
            }
        }

        pluggedList.erase(*(tempPluggedList.begin())); // 임시 리스트에 남은 전자용품(뒤에 순서에서 찾지 못한 제품)을 연결된 전자용품 리스트에서 제거
        ++unPluggedCount;                              // 언플러그 개수 증가
    }

    printf("%d", unPluggedCount);

    return 0;
}
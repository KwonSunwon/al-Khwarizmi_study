// Created by KwonSunwon on 2022-12-24
// Title: 강의실 배정
// Rating: G5
// Link: https://www.acmicpc.net/problem/11000
// Language: C++20

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX_TIME 1000000000

typedef unsigned int uint;
using namespace std;

struct Course
{
    uint startTime;
    uint endTime;
};

struct cmp
{
    bool operator()(Course a, Course b) const
    {
        if (a.startTime > b.startTime) // 시작 시간으로 정렬
            return true;
        if (a.startTime == b.startTime)
            if (a.endTime > b.endTime)
                return true;
        return false;
    }
};

// void show_courses(int n, priority_queue<Course, vector<Course>, cmp> courses)
// {
//     for (int i = 0; i < n; i++)
//     {
//         cout << courses.top().startTime << " " << courses.top().endTime << "\n";
//         courses.pop();
//     }
// }

int main()
{
    int n = 0;
    scanf("%d", &n);

    priority_queue<Course, vector<Course>, cmp> courses; // 우선순위 큐를 이용해 시작 시간을 기준으로 오름차순 정렬

    for (int i = 0; i < n; i++)
    {
        Course temp;
        scanf("%d %d", &temp.startTime, &temp.endTime);
        courses.push(temp);
    }

    priority_queue<int, vector<int>, greater<int>> timeTable; // 교실의 수업 종료 시간을 오름차순으로 정렬한 우선순위 큐
    timeTable.push(0);                                        // 0번째 교실의 수업 끝 시간을 0으로 초기화

    while (!courses.empty()) // 모든 수업을 할당 할 때까지
    {
        // 시작 시간이 가장 빠른 수업 선택
        Course temp = courses.top();
        courses.pop();

        if (timeTable.top() <= temp.startTime) // 교실들 중에 종료 시간이 가장 빠른 시간과 새로운 수업의 시작 시간을 비교
            timeTable.pop();                   // 만약 할당이 가능한 경우 기존 시간을 새로운 수업의 종료 시간으로 변경
        timeTable.push(temp.endTime);
    }

    printf("%d", timeTable.size());

    return 0;
}

// 예시
// 0) 3,5
// 1) 1,4
// 이고 새로운 수업이 5,9 인 경우
// 최적의 경우는 0)에 들어가야 하지만, 1)에 들어감 하지만 사용되는 교실의 개수는 최소가 됨
// 그 이유는 모든 수업 입력을 오름차순으로 저장하였기 때문에 5,9 수업이 나왔다는건
// 시작 시간잉 4인 수업이 더 이상 없다는 뜻이기 때문에
// 0), 1) 둘 다 최적의 경우가 됨
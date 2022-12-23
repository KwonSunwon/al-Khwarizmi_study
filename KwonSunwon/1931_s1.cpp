// Created by KwonSunwon on 2022-12-22.
// Title: 회의실 배정
// Rating: S1
// Link: https://www.acmicpc.net/problem/1931
// Language: C++20

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Meeting
{
    unsigned int start;
    unsigned int end;
} Meeting;

bool compare(Meeting a, Meeting b)
{
    if (a.end < b.end)
        return true;
    if (a.end == b.end)        // 이 조건이 없다면 2/3 3/3 이 입력으로 오는 경우
        if (a.start < b.start) // 3/3 2/3 으로 정렬이 된다면 베스트 케이스가 나오지 않을 수 있음
            return true;
    return false;
}

int main()
{
    int N = 0;
    cin >> N;

    vector<Meeting> meetings;

    for (int i = 0; i < N; i++)
    {
        Meeting temp;
        scanf("%d %d", &temp.start, &temp.end);
        meetings.push_back(temp);
    }

    sort(meetings.begin(), meetings.end(), compare);

    // cout << "sorted meeting\n";
    // for (int i = 0; i < N; i++)
    //     cout << meetings[i].start << " " << meetings[i].end << "\n";

    vector<Meeting> meetingTimeTable;
    meetingTimeTable.push_back(meetings[0]);
    for (int i = 1; i < N; i++)
    {
        if (meetings[i].start >= meetingTimeTable.back().end)
            meetingTimeTable.push_back(meetings[i]);
    }

    // cout << "time table\n";
    // for (int i = 0; i < meetingTimeTable.size(); i++)
    //     cout << meetingTimeTable[i].start << " " << meetingTimeTable[i].end << "\n";

    // cout << "maximum count\n";
    cout << meetingTimeTable.size();

    return 0;
}

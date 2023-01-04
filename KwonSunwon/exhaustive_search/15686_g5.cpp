// Created by KwonSunwon on 2023-01-04.
// Title: 치킨 배달
// Rating: G5
// Link: https://www.acmicpc.net/problem/15686
// Language: C++20

#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
int minDistance = 1000000000;

int get_distance(pair<int, int> a, pair<int, int> b);
int get_house_distance(pair<int, int> house, vector<pair<int, int>> chicken);
int get_city_distance(vector<pair<int, int>> chicken);
void dfs(int idx, int cnt, vector<pair<int, int>> selected);

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int temp;
            scanf("%d", &temp);
            if (temp == 1)
                house.push_back({i, j});
            else if (temp == 2)
                chicken.push_back({i, j});
        }
    }

    for (int i = 0; i < chicken.size(); i++)
        dfs(i, 0, {});

    printf("%d", minDistance);

    return 0;
}

int get_distance(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int get_house_distance(pair<int, int> house, vector<pair<int, int>> chicken)
{
    int min = 1000000000;
    for (int i = 0; i < chicken.size(); i++)
    {
        int dis = get_distance(house, chicken[i]);
        if (dis < min)
            min = dis;
        if (min == 1)
            break;
    }
    return min;
}

int get_city_distance(vector<pair<int, int>> chicken)
{
    int distance = 0;
    for (int h = 0; h < house.size(); h++)
    {
        distance += get_house_distance(house[h], chicken);
    }
    return distance;
}

void dfs(int idx, int cnt, vector<pair<int, int>> selected)
{
    selected.push_back(chicken[idx]);
    cnt++;

    if (cnt == M)
    {
        int tempDis = get_city_distance(selected);
        if (tempDis < minDistance)
            minDistance = tempDis;
        return;
    }

    for (int i = 1; i < chicken.size() - idx; i++)
        dfs(idx + i, cnt, selected);
}
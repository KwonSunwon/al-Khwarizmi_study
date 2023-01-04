// Created by KwonSunwon on 2023-01-04.
// Title: Ignition
// Rating: P5
// Link: https://www.acmicpc.net/problem/13141
// Language: C++20

// 1. 플로이드-워셜로 모든 정점 간의 최단 거리를 구함.
// 2. 모든 정점으로 가는 최단 거리의 합이 최소가 되는 정점을 찾음.
// 3. 해당 정점을 시작점으로 하여 모든 정점이 방문되는 최단 시간을 구함.
// 4. 남은 간선 중 길이 가장 긴 간선이 전부 태워지는 시간을 더함.

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct Edge
{
    int s, e, l;
    int burnPerTime;
};

int N, M;
vector<Edge> edges;
vector<vector<int>> adj;
int startingPoint;
set<int> firedPoints;

void make_adjacency_matrix();
void floyd_warshall();
void find_starting_point();

void add_burn_per_time(int point);

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        int s, e, l;
        scanf("%d %d %d", &s, &e, &l);
        edges.push_back({s, e, l, 0});
    }

    make_adjacency_matrix();
    floyd_warshall();
    find_starting_point();

    firedPoints.insert(startingPoint);
    add_burn_per_time(startingPoint);

    float time = 0;
    while (firedPoints.size() != N)
    {
        vector<int> newBurnPoints;
        for (int i = 0; i < M; i++)
        {
            if (edges[i].burnPerTime == 0 || edges[i].l <= 0)
                continue;
            edges[i].l -= edges[i].burnPerTime;
            if (edges[i].l <= 0)
            {
                newBurnPoints.push_back(edges[i].s);
                newBurnPoints.push_back(edges[i].e);
            }
        }
        for (int i = 0; i < newBurnPoints.size(); i++)
        {
            if (firedPoints.find(newBurnPoints[i]) == firedPoints.end())
            {
                firedPoints.insert(newBurnPoints[i]);
                add_burn_per_time(newBurnPoints[i]);
            }
        }
        time++;
    }

    float max = 0;
    for (int i = 0; i < M; i++)
        if (float(edges[i].l) / float(edges[i].burnPerTime) > max)
            max = float(edges[i].l) / float(edges[i].burnPerTime);

    printf("%.1f", time + max);

    return 0;
}

void make_adjacency_matrix()
{
    adj = vector<vector<int>>(N + 1, vector<int>(N + 1, 987654321));
    for (int i = 0; i < M; i++)
    {
        int s = edges[i].s;
        int e = edges[i].e;
        int l = edges[i].l;
        adj[s][e] = l;
        adj[e][s] = l;
    }
}

void floyd_warshall()
{
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

void find_starting_point()
{
    int min = 987654321;
    startingPoint = 0;
    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        for (int j = 1; j <= N; j++)
            sum += adj[i][j];
        if (sum < min)
        {
            min = sum;
            startingPoint = i;
        }
    }
}

void add_burn_per_time(int point)
{
    for (int i = 0; i < M; i++)
    {
        if (edges[i].burnPerTime == 2)
            continue;
        if (edges[i].s == point || edges[i].e == point)
            edges[i].burnPerTime++;
        if (edges[i].s == point && edges[i].e == point)
            edges[i].burnPerTime = 2;
    }
}

////////////////////////////////////////////////////////////////////////////
// 2. 모든 정점으로 가는 최단 거리의 합이 최소가 되는 정점을 찾음.
// -> 플로이드를 이용해 모든 정점의 거리를 구한것에서 브루트 포스로 모든 경우를 확인해 봐야함
// 틱당 모든 경우를 확인하는게 아닌 간선 당 걸리는 시간을 계산해 최소 시간을 구해야함

#include <vector>
#include <cstdio>
using namespace std;

const int INF = 987654321;
int vertex_num, edge_num;
vector<vector<int>> adj;  // 실제 간선으로 이어진 경우만 저장
vector<vector<int>> dist; // 플로이드로 계산한 최단 경로를 저장

double BurnGraph()
{
    double shortest_time = INF, longest_time, spent_time, remain_len;
    int edge_len;

    for (int start = 1; start <= vertex_num; ++start)
    {
        // start 정점부터 태웠을 때 마지막 간선이 사라지는 시간을 저장
        longest_time = 0;

        for (int from = 1; from <= vertex_num; ++from)
        {
            for (int to = 1; to <= vertex_num; ++to)
            {
                edge_len = adj[from][to];

                if (edge_len != -1)
                { // from 정점과 간선으로 연결되지 않은 경우
                    remain_len = edge_len - (dist[start][to] - dist[start][from]);

                    // remain_len이 0이하이면 이미 불탄 경우를 의미
                    if (remain_len > 0)
                    {
                        spent_time = (remain_len / 2) + dist[start][to];
                        longest_time = max(spent_time, longest_time);
                    }
                }
            }
        }
        // 어떤 정점부터 태워야 가장 빨리 모든 그래프를 태울 수 있는지 저장
        shortest_time = min(longest_time, shortest_time);
    }
    return shortest_time;
}

void Floyd()
{
    for (int k = 1; k <= vertex_num; ++k)
        for (int i = 1; i <= vertex_num; ++i)
            for (int j = 1; j <= vertex_num; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main()
{
    scanf("%d %d", &vertex_num, &edge_num);
    adj = vector<vector<int>>(vertex_num + 1, vector<int>(vertex_num + 1, -1));
    dist = vector<vector<int>>(vertex_num + 1, vector<int>(vertex_num + 1, INF));

    for (int i = 1; i <= vertex_num; ++i)
        dist[i][i] = 0;

    int S, E, L;
    for (int i = 0; i < edge_num; ++i)
    {
        scanf("%d %d %d", &S, &E, &L);
        if (adj[S][E] == -1 || adj[S][E] < L)
        {
            adj[S][E] = L;
            adj[E][S] = L;
        }
        if (dist[S][E] == INF || L < dist[S][E])
        {
            dist[S][E] = L;
            dist[E][S] = L;
        }
    }

    Floyd();

    printf("%.1f\n", BurnGraph());
    return 0;
}
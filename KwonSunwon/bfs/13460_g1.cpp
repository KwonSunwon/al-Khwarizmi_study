/*
Create by KwonSunwon on 2023-01-18.
Title: 구슬 탈출 2
Rating: G1
Link: https://www.acmicpc.net/problem/13460
Language: C++20
*/

#include <iostream>
#include <queue>

using namespace std;

struct Ball
{
    pair<int, int> red;
    pair<int, int> blue;
};

int n, m;
char map[10][10];
Ball ball, nextBall;
pair<int, int> hole;
queue<pair<Ball, int>> q;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void print_map(Ball ball)
{
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (ball.red == make_pair(y, x))
                printf("R");
            else if (ball.blue == make_pair(y, x))
                printf("B");
            else
                printf("%c", map[y][x]);
        }
        printf("\n");
    }
    printf("\n");
}

bool move(int dir, int depth);

int main()
{
    scanf("%d %d", &n, &m);

    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
        {
            scanf(" %c", &map[y][x]);
            if (map[y][x] == 'R')
            {
                ball.red = {y, x};
                map[y][x] = '.';
            }
            else if (map[y][x] == 'B')
            {
                ball.blue = {y, x};
                map[y][x] = '.';
            }
            else if (map[y][x] == 'O')
            {
                hole = {y, x};
            }
        }

    q.push({ball, 0});
    while (!q.empty())
    {
        Ball ball = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (depth >= 10)
        {
            printf("-1");
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            nextBall = ball;
            if (move(i, depth))
            {
                // cout << "depth: " << depth + 1 << endl;
                // print_map(nextBall);
                q.push({nextBall, depth + 1});
            }
        }
    }

    printf("-1");

    return 0;
}

bool move(int dir, int depth)
{
    int moveCnt = 0;
    pair<int, int> nextRed = nextBall.red;
    pair<int, int> nextBlue = nextBall.blue;
    bool goalRed = false;

    while (true)
    {
        bool isRedMoved = true;
        bool isBlueMoved = true;

        nextRed = {nextRed.first + dy[dir], nextRed.second + dx[dir]};
        nextBlue = {nextBlue.first + dy[dir], nextBlue.second + dx[dir]};

        if (map[nextRed.first][nextRed.second] == '#' || goalRed)
        {
            nextRed = {nextRed.first - dy[dir], nextRed.second - dx[dir]};
            isRedMoved = false;
        }
        if (map[nextBlue.first][nextBlue.second] == '#')
        {
            nextBlue = {nextBlue.first - dy[dir], nextBlue.second - dx[dir]};
            isBlueMoved = false;
        }

        if (nextRed == nextBlue && !goalRed)
        {
            if (!isRedMoved)
            {
                nextBlue = {nextBlue.first - dy[dir], nextBlue.second - dx[dir]};
                isBlueMoved = false;
            }
            else if (!isBlueMoved)
            {
                nextRed = {nextRed.first - dy[dir], nextRed.second - dx[dir]};
                isRedMoved = false;
            }
        }

        if (!isBlueMoved && !isRedMoved)
        {
            if (goalRed)
            {
                printf("%d", depth + 1);
                exit(0);
            }

            if (!moveCnt)
                return false;

            nextBall.red = nextRed;
            nextBall.blue = nextBlue;
            return true;
        }

        if (nextBlue == hole && isBlueMoved)
            return false;

        if (nextRed == hole && isRedMoved)
            goalRed = true;

        ++moveCnt;
    }
}
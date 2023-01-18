/*
https://www.acmicpc.net/problem/2206
제목: 벽 부수고 이동하기
분류: 너비우선탐색
난이도: 골드3

최초 접근 풀이:
너비우선탐색
모든벽을 한번씩 제거해보면서 탐색
시간초과

두번째 접근풀이:
포문으로 초기화하는 대신 memset을 사용함
시간초과

세번째:
질문게시판에서 시간초과에 대한 글을 읽음
모든벽을 n^2으로 찾는경우 절대 못 찾는다 하고,
벽을 뚫은경우와 뚫지않은 경우로 3차원배열이라는 힌트를 받음
->해결 후 100%에서 틀렸습니다 뜸

네번째: 1,1 크기로 만들었을때 오류 생김-> 따로 특수한케이스로 처리

*/

#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAX 1001

int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0};

//visited로 방문과, level을 모드 체크
int visited[MAX][MAX][2] = {0};
string map[MAX];

int height, width;

int BFS();

int main()
{
	cin >> height >> width;

	for (int i = 0; i < height; ++i)
		cin >> map[i];

	if (height == 1 && width == 1)
		cout << 1;
	else
		cout << BFS();

}


int BFS()
{
	//((y,x),isbreak) 순서로 담을 예정
	//isBreak가 0 이라면 아직 벽을 뚫지 않은 상태
	//1이라면 벽을 한 번 뚫은 상태
	queue<pair<pair<int, int>,int>> q;
	q.push(make_pair(make_pair(0,0),false));
	visited[0][0][0] = 1;
	

	while (!q.empty())
	{
		pair<int, int> nowPos = q.front().first;
		bool isBrake = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = nowPos.first + dy[i];
			int nx = nowPos.second + dx[i];
			if (ny < 0 || nx < 0 || ny >= height || nx >= width)
				continue;

			//벽이 있는데 아직 벽을 뚫은적이 없다면 벽을 뚫은 배열로 넘어감
			if (map[ny][nx] == '1' && isBrake==0)
			{
				q.push(make_pair(make_pair(ny, nx),isBrake + 1));
				visited[ny][nx][1] = visited[nowPos.first][nowPos.second][0] + 1;
			}

			//갈 수 있는 길이라면 현재 상태 배열로 넘어감
			if (map[ny][nx]=='0' && visited[ny][nx][isBrake] == 0)
			{
				q.push(make_pair(make_pair(ny, nx), isBrake));
				visited[ny][nx][isBrake] = visited[nowPos.first][nowPos.second][isBrake] + 1;
			}

			//도착하면 값 리턴
			if (ny == height - 1 && nx == width - 1)
				return visited[ny][nx][isBrake];
		}
	}

	return -1;
}
/*
https://www.acmicpc.net/problem/3109
제목: 빵집
분류: 그리디 알고리즘
난이도: 골드 2

최초 접근 풀이:
1. 최대한 파이프가 위로 몰리게 한다.
2. 따라서 우선도를 위, 가운데, 아래 순으로
3. 깊이 우선 탐색을 진행한다.(불가능한 위치는 가지치기)
최초 접근으로 성공
*/

#include<iostream>
using namespace std;

void dfs(int y,int x);
bool checkPossible(int y, int x);
bool isComplite = false;

int dy[3] = { -1,0,1 };
int width = 0;
int height = 0;
int ans = 0;
string map[10001];
int main()
{
	cin >> height >> width;
	
	for (int i = 0; i < height; ++i)
		cin >> map[i];

	//한 행당 한번씩 깊이우선 탐색을 진행한다.
	for (int i = 0; i < height; ++i)
	{
		isComplite = false;
		dfs(i, 0);
	}

	cout << ans;
}

//깊이 우선 탐색
void dfs(int y,int x)
{
	//기저사례 끝까지 탐색한경우 성공
	//무의미한 연산을 없애기 위해 플래그 설정
	if (x == width)
	{
		isComplite = true;
		ans++;
		return;
	}

	for (int i = 0; i < 3; ++i)
	{
		//위, 가운데, 아래 순으로 우선도를 주고
		//검사후 가능하면 다음 깊이로 들어간다.
		//만약 진행이 끝났다면 함수를 리턴해준다.
		if (checkPossible(y+dy[i],x+1))
		{
			map[y + dy[i]][x + 1] = 'x';
			dfs(y + dy[i], x + 1);
			if (isComplite)
				return;
		}
	}
}

//다음 좌표를 진행 할 수 있는지 검사
bool checkPossible(int y, int x)
{
	if (y < 0)
		return false;

	if (y >= height)
		return false;

	if (map[y][x] == 'x')
		return false;

	return true;
}
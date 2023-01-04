/*
https://www.acmicpc.net/problem/12100
제목: 2048 (Easy)
분류: 완전탐색 알고리즘
난이도: 골드 2

최초 접근 풀이:

*/

#include<iostream>
using namespace std;
//각 블럭의 정보 구조체
struct block
{
	bool isAdd = false;
	int score = 0;
};
//상하좌우에 대한 설정을 저장한 배열
int calcDi[4] = { 1,-1,1,1 };
int calcDj[4] = { 1,1,1,-1 };
int di[4] = { 1,0,0,0 };
int dj[4] = { 0,0,1,0 };
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

//테이블 정보와 각 레벨별 테이블을 임시저장
block table[20][20];
block tempTable[6][20][20];
int boardSize = 0;
int maxAns = 0;//이거 왜 0으로 바꾸면 안됨?

void move(int order);
bool judgeI(int order,int i);
bool judgeJ(int order,int j);
void simulation(int depth);

int main()
{
	int tempInput;
	cin >> boardSize;

	di[1] = boardSize - 2;
	dj[3] = boardSize - 2;

	//입력
	for (int i = 0; i < boardSize; ++i)
	{
		for (int j = 0; j < boardSize; ++j)
		{
			cin >> tempInput;
			table[i][j].score = tempInput;
			tempTable[0][i][j].score=tempInput;
		}
	}
	simulation(0);
	cout << maxAns;
}
//시뮬레이션 함수
void simulation(int depth)
{
	depth++;
	//각 깊이별로 tempTable에 깊은복사를 해둔다.
	//(백트래킹을 위해 이전 상태를 저장하기 위해서)
	for (int i = 0; i < boardSize; ++i)
	{
		for (int j = 0; j < boardSize; ++j)
		{
			tempTable[depth][i][j].score = table[i][j].score;
		}
	}
	//마지막 깊이에 왔다면 최대값을 갱신한다.
	if (depth == 6)
	{
		for (int i = 0; i < boardSize; ++i)
		{
			for (int j = 0; j < boardSize; ++j)
			{
				if (maxAns < table[i][j].score)
				{
					maxAns=table[i][j].score;
				}
			}
		}
		return;
	}

	//상하좌우 순서로 모든 경우의 수를 돌려본다.
	for (int i = 0; i < 4; ++i)
	{
		move(i);
		simulation(depth);
		for (int i = 0; i < boardSize; ++i)
		{
			for (int j = 0; j < boardSize; ++j)
			{
				table[i][j].score = tempTable[depth][i][j].score;
			}
		}
	}
}

//simulation for문 특수 케이스를 위한 함수
bool judgeI(int num,int i)
{
	if (num == 1) return i >= 0;
	else return i < boardSize;
}

bool judgeJ(int num, int j)
{
	if (num == 3) return j >= 0;
	else return j < boardSize;
}

//이동함수 상하좌우 순서대로 0,1,2,3
void move(int num)
{
	bool isChange = false;
	while (true)
	{
		isChange = false;
		//각각 이동하는 방향부터 탐색하며 처리해줘야 하므로
		//방향마다 for문에 들어가는 값이 다르다.
		for (int i = di[num]; judgeI(num,i); i+=calcDi[num])
		{
			for (int j = dj[num]; judgeJ(num, j); j+=calcDj[num])
			{
				//0이 아닌 숫자앞에 0이 있다면 자리를 바꿔준다.
				if (table[i][j].score!=0 && table[i+dy[num]][j+dx[num]].score == 0)
				{
					table[i + dy[num]][j + dx[num]].score = table[i][j].score;
					table[i][j].score = 0;

					table[i + dy[num]][j + dx[num]].isAdd = table[i][j].isAdd;
					table[i][j].isAdd = false;

					isChange = true;
				}
				//0이 아닌 숫자앞에 같은 숫자가 있다면 합쳐준뒤, isAdd를 true로 바꿔준다.
				else if (table[i + dy[num]][j + dx[num]].score == table[i][j].score && !table[i][j].isAdd && !table[i+dy[num]][j+dx[num]].isAdd)
				{
					table[i + dy[num]][j + dx[num]].score *= 2;
					table[i][j].score *= 0;
					table[i + dy[num]][j + dx[num]].isAdd = true;

					isChange = true;
				}
				
			}
		}
		//하나라도 바뀐 숫자가 없다면 break
		if (!isChange)
			break;
	}

	//한번의 이동이 모두 끝나면 각 블록의 isAdd를 false로 바꿔준다.
	for (int i = 0; i < boardSize; ++i)
		for (int j = 0; j < boardSize; ++j)
			table[i][j].isAdd = false;
}

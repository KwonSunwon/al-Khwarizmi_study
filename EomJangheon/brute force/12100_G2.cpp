/*
https://www.acmicpc.net/problem/12100
제목: 2048 (Easy)
분류: 완전탐색 알고리즘
난이도: 골드 2

최초 접근 풀이:

*/

#include<iostream>
using namespace std;

struct block
{
	bool isAdd = false;
	int score = 0;
};

int calcDi[4] = { 1,-1,1,1 };
int calcDj[4] = { 1,1,1,-1 };
int di[4] = { 1,0,0,0 };
int dj[4] = { 0,0,1,0 };
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

//상하좌우
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
void simulation(int depth)
{
	depth++;
	for (int i = 0; i < boardSize; ++i)
	{
		for (int j = 0; j < boardSize; ++j)
		{
			tempTable[depth][i][j].score = table[i][j].score;
		}
	}
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

void move(int num)
{
	bool isChange = false;
	while (true)
	{
		isChange = false;
		for (int i = di[num]; judgeI(num,i); i+=calcDi[num])
		{
			for (int j = dj[num]; judgeJ(num, j); j+=calcDj[num])
			{
				if (table[i][j].score!=0 && table[i+dy[num]][j+dx[num]].score == 0)
				{
					table[i + dy[num]][j + dx[num]].score = table[i][j].score;
					table[i][j].score = 0;

					table[i + dy[num]][j + dx[num]].isAdd = table[i][j].isAdd;
					table[i][j].isAdd = false;

					isChange = true;
				}
				else if (table[i + dy[num]][j + dx[num]].score == table[i][j].score && !table[i][j].isAdd && !table[i+dy[num]][j+dx[num]].isAdd)
				{
					table[i + dy[num]][j + dx[num]].score *= 2;
					table[i][j].score *= 0;
					table[i + dy[num]][j + dx[num]].isAdd = true;

					isChange = true;
				}
				
			}
		}
		if (!isChange)
			break;
	}


	for (int i = 0; i < boardSize; ++i)
		for (int j = 0; j < boardSize; ++j)
			table[i][j].isAdd = false;
}

/*
https://www.acmicpc.net/problem/12100
����: 2048 (Easy)
�з�: ����Ž�� �˰���
���̵�: ��� 2

���� ���� Ǯ��:

*/

#include<iostream>
using namespace std;
//�� ���� ���� ����ü
struct block
{
	bool isAdd = false;
	int score = 0;
};
//�����¿쿡 ���� ������ ������ �迭
int calcDi[4] = { 1,-1,1,1 };
int calcDj[4] = { 1,1,1,-1 };
int di[4] = { 1,0,0,0 };
int dj[4] = { 0,0,1,0 };
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

//���̺� ������ �� ������ ���̺��� �ӽ�����
block table[20][20];
block tempTable[6][20][20];
int boardSize = 0;
int maxAns = 0;//�̰� �� 0���� �ٲٸ� �ȵ�?

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

	//�Է�
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
//�ùķ��̼� �Լ�
void simulation(int depth)
{
	depth++;
	//�� ���̺��� tempTable�� �������縦 �صд�.
	//(��Ʈ��ŷ�� ���� ���� ���¸� �����ϱ� ���ؼ�)
	for (int i = 0; i < boardSize; ++i)
	{
		for (int j = 0; j < boardSize; ++j)
		{
			tempTable[depth][i][j].score = table[i][j].score;
		}
	}
	//������ ���̿� �Դٸ� �ִ밪�� �����Ѵ�.
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

	//�����¿� ������ ��� ����� ���� ��������.
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

//simulation for�� Ư�� ���̽��� ���� �Լ�
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

//�̵��Լ� �����¿� ������� 0,1,2,3
void move(int num)
{
	bool isChange = false;
	while (true)
	{
		isChange = false;
		//���� �̵��ϴ� ������� Ž���ϸ� ó������� �ϹǷ�
		//���⸶�� for���� ���� ���� �ٸ���.
		for (int i = di[num]; judgeI(num,i); i+=calcDi[num])
		{
			for (int j = dj[num]; judgeJ(num, j); j+=calcDj[num])
			{
				//0�� �ƴ� ���ھտ� 0�� �ִٸ� �ڸ��� �ٲ��ش�.
				if (table[i][j].score!=0 && table[i+dy[num]][j+dx[num]].score == 0)
				{
					table[i + dy[num]][j + dx[num]].score = table[i][j].score;
					table[i][j].score = 0;

					table[i + dy[num]][j + dx[num]].isAdd = table[i][j].isAdd;
					table[i][j].isAdd = false;

					isChange = true;
				}
				//0�� �ƴ� ���ھտ� ���� ���ڰ� �ִٸ� �����ص�, isAdd�� true�� �ٲ��ش�.
				else if (table[i + dy[num]][j + dx[num]].score == table[i][j].score && !table[i][j].isAdd && !table[i+dy[num]][j+dx[num]].isAdd)
				{
					table[i + dy[num]][j + dx[num]].score *= 2;
					table[i][j].score *= 0;
					table[i + dy[num]][j + dx[num]].isAdd = true;

					isChange = true;
				}
				
			}
		}
		//�ϳ��� �ٲ� ���ڰ� ���ٸ� break
		if (!isChange)
			break;
	}

	//�ѹ��� �̵��� ��� ������ �� ����� isAdd�� false�� �ٲ��ش�.
	for (int i = 0; i < boardSize; ++i)
		for (int j = 0; j < boardSize; ++j)
			table[i][j].isAdd = false;
}

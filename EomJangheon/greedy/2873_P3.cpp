/*
https://www.acmicpc.net/problem/2873
제목: 롤러코스터
분류: 그리디 알고리즘
난이도: 플래 3

최초 풀이:
1.가로 또는 세로가 홀수라면 모든 칸을 지날 수 있다.
2.가로 세로 모두 짝수라면 특정 칸을 버려야한다.(특정칸은 밑의 결과)
  2.1)4*4에서 최선의 경우를 모두 찾아봤다.
  2.2)결과 특이한 패턴을 발견했다.
  0 1 3 1
  1 3 1 3
  3 1 3 1
  1 3 1 0
  2.3)위의 표는 4*4에서 최선을 찾기 위해
	  해당 좌표를 버렸을때 버려지는 모든 좌표의 수다.
	  지그재그 모양으로 버려지는 좌표의 수가 최소 였고
	  반대 지그재그 모양으로 항상 옆의 좌표가 같이 버려졌다.
  2.4)이를 2*4,4*6 으로 진행했을때 똑같은 결과였다.
  즉 행과 열의 합이 홀수인 칸중 가장 작은 칸을 버린다.
3.버리면서 경로찾기
  1.각 방향에 우선도를 주며 찾으려했으나 잘 안됨
  2.특정 방향으로 만났을때 패턴을 찾아봤으나 잘 안됨
  3.결국 하나씩 다 해보다가, 해당 좌표가 있는 줄만 지그재그처럼 움직이고,
    나머지 줄은 스캔하듯이 가면 되는것을 찾음
	ex)0번째행 또는 1번째행이라면 0,1행만 지그재그
	   4번째행 또는 5번째행이라면 4,5행만 지그재그
  4.오답 후 수정 사항->지그재그 라인 위쪽은 우, 좌 순으로 스캔
                                 아래쪽은 좌, 우 순으로 스캔

오답 이후 
수정1: 특수 케이스에 대한 처리를 안일하게함
수정2: 단순 배열 인덱스 실수

정답 이후 다른 코드 리뷰
1.대부분 결과를 바로 출력하는 대신 문자열에 저장해두는 방법 사용
2.따로 지나간 부분을 체크 할 필요없이 아래 오른쪽, 위 오른쪽을
  한번에 추가하는 방법이 있었음
3.의외로 대부분 함수를 사용하지 않았음
4.짝수*짝수 경우 나는 하나씩 넣어보며 규칙을 찾았지만 증명방식이 있었음
https://suhwanc.tistory.com/23 의 풀이 3을 보면 이동횟수를 통해 증명
*/

#include<iostream>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int table[1000][1000] = { 0 };

void classifyCase(int, int);
void processOddxEven(int, int);
void processEvenxOdd(int, int);
void processEvenxEven(int, int);

int main()
{
	int height = 0, width = 0;
	int tempIn = 0;
	scanf("%d %d", &height,&width);
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			scanf("%d", &table[i][j]);
		}
	}
	classifyCase(height, width);
}
//가로 세로 크기에 따란 풀이 분류
void classifyCase(int height, int width)
{
	if (height % 2 == 1)
	{
		processOddxEven(height, width);
		return;
	}
	else if (width % 2 == 1)
	{
		processEvenxOdd(height, width);
		return;
	}
	else
		processEvenxEven(height, width);
}
//세로의 크기가 홀수일경우
void processOddxEven(int height, int width)
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width - 1; ++j)
		{
			if (i % 2 == 0)
				printf("R");
			else
				printf("L");
		}
		if(i!=height-1)
			printf("D");
	}
	
}
//세로가 짝수이며 가로의 크기가 홀수일경우
void processEvenxOdd(int height, int width)
{
	for (int i = 0; i < width; ++i)
	{
		for (int j = 0; j < height - 1; ++j)
		{
			if (i % 2 == 0)
				printf("D");
			else
				printf("U");
		}
		if (i != width - 1)
			printf("R");
	}
}
//가로 세로 모두 짝수일경우
void processEvenxEven(int height, int width)
{
	int targetY = 0, targetX = 0,targetNum=1000;
	int zigzagLine = 0;
	//최소 지점을 찾는다
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if ((i + j) % 2 == 1 && (targetNum>table[i][j]))
			{
				targetY = i;
				targetX = j;
				targetNum = table[i][j];
			}
		}
	}
	//최소지점, 그 지점의 라인 체크
	table[targetY][targetX] = -1;

	if (targetY % 2 == 0)
		zigzagLine = targetY;
	else
		zigzagLine = targetY - 1;

	//모든 라인을 두줄씩 보면서
	for (int i = 0; i < height; ++++i)
	{
		//타겟 라인보다 위에있다면, 우,좌 순서
		if (i < zigzagLine)
		{
			for (int j = 0; j < width - 1; ++j)
				printf("R");
			printf("D");
			for (int j = 0; j < width - 1; ++j)
				printf("L");
			//2차 제출 후, 범위 실수로 인한 오답 수정
			if (i+1 != height - 1)
				printf("D");
		}
		//타겟 라인보다 아래있다면, 좌,우 순서
		//1차 제출 후, 추가한 부분 지그재그 이후에는 뒤에서 시작해야하게 수정
		else if (i > zigzagLine)
		{
			for (int j = 0; j < width - 1; ++j)
				printf("L");
			printf("D");
			for (int j = 0; j < width - 1; ++j)
				printf("R");
			if (i+1 != height - 1)
				printf("D");
		}
		//타겟라인이라면 지그재그로
		else
		{
			int nowY = zigzagLine;
			int nowX = 0;
			table[nowY][nowX] = -1;
			while (nowY!=zigzagLine+1 || nowX!=width-1)
			{
				if (nowY == zigzagLine)
				{
					if (table[nowY + 1][nowX] > 0)
					{
						table[nowY + 1][nowX] = -1;
						nowY++;
						printf("D");
					}
					else
					{
						table[nowY][nowX+1] = -1;
						nowX++;
						printf("R");
					}
				}
				else
				{
					if (table[nowY - 1][nowX] > 0)
					{
						table[nowY - 1][nowX] = -1;
						nowY--;
						printf("U");
					}
					else
					{
						table[nowY][nowX + 1] = -1;
						nowX++;
						printf("R");
					}
				}
			}
			if(zigzagLine+1!=height-1)
				printf("D");
		}
	}
}
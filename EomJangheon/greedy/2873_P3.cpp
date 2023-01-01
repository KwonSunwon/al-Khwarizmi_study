/*
https://www.acmicpc.net/problem/2873
����: �ѷ��ڽ���
�з�: �׸��� �˰���
���̵�: �÷� 3

���� Ǯ��:
1.���� �Ǵ� ���ΰ� Ȧ����� ��� ĭ�� ���� �� �ִ�.
2.���� ���� ��� ¦����� Ư�� ĭ�� �������Ѵ�.(Ư��ĭ�� ���� ���)
  2.1)4*4���� �ּ��� ��츦 ��� ã�ƺô�.
  2.2)��� Ư���� ������ �߰��ߴ�.
  0 1 3 1
  1 3 1 3
  3 1 3 1
  1 3 1 0
  2.3)���� ǥ�� 4*4���� �ּ��� ã�� ����
	  �ش� ��ǥ�� �������� �������� ��� ��ǥ�� ����.
	  ������� ������� �������� ��ǥ�� ���� �ּ� ����
	  �ݴ� ������� ������� �׻� ���� ��ǥ�� ���� ��������.
  2.4)�̸� 2*4,4*6 ���� ���������� �Ȱ��� �������.
  �� ��� ���� ���� Ȧ���� ĭ�� ���� ���� ĭ�� ������.
3.�����鼭 ���ã��
  1.�� ���⿡ �켱���� �ָ� ã���������� �� �ȵ�
  2.Ư�� �������� �������� ������ ã�ƺ����� �� �ȵ�
  3.�ᱹ �ϳ��� �� �غ��ٰ�, �ش� ��ǥ�� �ִ� �ٸ� �������ó�� �����̰�,
    ������ ���� ��ĵ�ϵ��� ���� �Ǵ°��� ã��
	ex)0��°�� �Ǵ� 1��°���̶�� 0,1�ุ �������
	   4��°�� �Ǵ� 5��°���̶�� 4,5�ุ �������
  4.���� �� ���� ����->������� ���� ������ ��, �� ������ ��ĵ
                                 �Ʒ����� ��, �� ������ ��ĵ

���� ���� 
����1: Ư�� ���̽��� ���� ó���� �����ϰ���
����2: �ܼ� �迭 �ε��� �Ǽ�

���� ���� �ٸ� �ڵ� ����
1.��κ� ����� �ٷ� ����ϴ� ��� ���ڿ��� �����صδ� ��� ���
2.���� ������ �κ��� üũ �� �ʿ���� �Ʒ� ������, �� ��������
  �ѹ��� �߰��ϴ� ����� �־���
3.�ǿܷ� ��κ� �Լ��� ������� �ʾ���
4.¦��*¦�� ��� ���� �ϳ��� �־�� ��Ģ�� ã������ �������� �־���
https://suhwanc.tistory.com/23 �� Ǯ�� 3�� ���� �̵�Ƚ���� ���� ����
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
//���� ���� ũ�⿡ ���� Ǯ�� �з�
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
//������ ũ�Ⱑ Ȧ���ϰ��
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
//���ΰ� ¦���̸� ������ ũ�Ⱑ Ȧ���ϰ��
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
//���� ���� ��� ¦���ϰ��
void processEvenxEven(int height, int width)
{
	int targetY = 0, targetX = 0,targetNum=1000;
	int zigzagLine = 0;
	//�ּ� ������ ã�´�
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
	//�ּ�����, �� ������ ���� üũ
	table[targetY][targetX] = -1;

	if (targetY % 2 == 0)
		zigzagLine = targetY;
	else
		zigzagLine = targetY - 1;

	//��� ������ ���پ� ���鼭
	for (int i = 0; i < height; ++++i)
	{
		//Ÿ�� ���κ��� �����ִٸ�, ��,�� ����
		if (i < zigzagLine)
		{
			for (int j = 0; j < width - 1; ++j)
				printf("R");
			printf("D");
			for (int j = 0; j < width - 1; ++j)
				printf("L");
			//2�� ���� ��, ���� �Ǽ��� ���� ���� ����
			if (i+1 != height - 1)
				printf("D");
		}
		//Ÿ�� ���κ��� �Ʒ��ִٸ�, ��,�� ����
		//1�� ���� ��, �߰��� �κ� ������� ���Ŀ��� �ڿ��� �����ؾ��ϰ� ����
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
		//Ÿ�ٶ����̶�� ������׷�
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
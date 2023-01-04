/*
https://www.acmicpc.net/problem/14500
����: ��Ʈ�ι̳�
�з�: ����Ž�� �˰���
���̵�: ��� 4

���� ���� Ǯ��:
�� ������ ��ǥ���� �����ϰ� ���̺��� ��ĭ�� ��ȸ�ϸ� ��� ������
���ϸ� �־��.
*/

#include<iostream>
using namespace std;
//�� ������ �����ǥ�� ����
int dx[19][4] = {
	{0,1,2,3},{0,0,0,0},//1
	{0,1,0,1},//��
	{0,0,0,1},{0,1,2,2},{0,1,1,1},{0,0,1,2},//L
	{0,-1,-1,-1},{0,1,2,2},{0,1,1,1},{0,0,1,2},//������L
	{0,0,1,1},{0,1,1,2},{0,0,1,1},{0,1,1,2},//Z
	{0,0,0,1},{0,0,0,-1},{0,1,2,1},{0,1,2,1}//��

};
int dy[19][4] = {
	{0,0,0,0},{0,1,2,3},//1
	{0,0,1,1},//��
	{0,1,2,2},{0,0,0,-1},{0,0,1,2},{0,-1,-1,-1},//L
	{0,0,1,2},{0,0,0,1},{0,0,-1,-2},{0,1,1,1},//������L
	{0,1,1,2},{0,0,-1,-1},{0,-1,-1,-2},{0,0,1,1},
	{0,1,2,1},{0,1,2,1},{0,0,0,-1},{0,0,0,1}//��
};
int ans = 0;
int height, width;
int table[500][500];
int calcSum(int y,int x,int shape);
int main()
{
	cin >> height >> width;
	//���̺��� �Է�
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
			cin >> table[i][j];

	//���̺��� ��� ĭ�� ��ĭ�� ������
	//��� ����� ĭ���� �־��.
	for (int i = 0; i < height;++i)
	{
		for (int j = 0; j < width; ++j)
		{
			for (int k = 0; k < 19; ++k)
			{
				int tempSum = calcSum(i,j,k);
				if (tempSum > ans)
					ans = tempSum;	
			}
		}
	}
	cout << ans;
}
int calcSum(int y, int x,int shape)
{
	//���� �����ǥ�� �ϳ��� ���̺��� ����� 0�� �����Ѵ�.
	for (int i = 0; i < 4; ++i)
	{
		if (y + dy[shape][i] < 0 || y + dy[shape][i] >= height
			|| x + dx[shape][i] < 0 || x + dx[shape][i] >= width)
			return 0;
	}

	//��� �����ǥ�� ���̺� �ִٸ� �ش� ĭ�� ���ڵ��� ���ѵ� �����Ѵ�.
	int ret = 0;
	for (int i = 0; i < 4; ++i)
		ret += table[y + dy[shape][i]][x + dx[shape][i]];
	
	return ret;
}


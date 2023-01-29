/*
https://www.acmicpc.net/problem/3020
����: ���˹���
�з�: ������
���̵�: ��� 5

���� ���� Ǯ��:
���� �����̶�� 1~ũ������� ���� 1 �ø���.
���� �������̶�� ����-ũ��+1 ���� ���̱��� ���� 1 �ø���.
���ӵ� ������ �ѹ��� ���� ���� �ø���? �ٷ� ����Ʈ�� ����
�ڵ�� ������ ����Ʈ�� �ڵ忡�� �ܾ���.
*/

#include<iostream>
#define MAX 2000000000
#pragma warning(disable:4996)
using namespace std;
int fen[500001];
int width, height;

//���� ����Ʈ�� �Լ�
void upd_(int i, int j, int x) {
	while (i < height + 1)
	{
		fen[i] += x;
		i += (i & -i);
	}
	while (j < height + 1)
	{
		fen[j] -= x;
		j += (j & -j);
	}
}

int sum_(int i) {
	int ret = 0;
	while (i)
	{
		ret += fen[i];
		i -= (i & -i);
	}
	return ret;
}

int main()
{
	int temp;
	int ans = 0;
	int min_break = MAX;
	cin >> width >> height;
	for (int i = 0; i < width / 2; ++i)
	{
		//1~ũ����� ������Ʈ
		scanf("%d", &temp);
		upd_(1, temp + 1, 1);

		//~���̱��� ������Ʈ
		scanf("%d", &temp);
		upd_(height - temp + 1, height + 1, 1);
	}

	for (int i = 1; i < height + 1; ++i)
	{
		//���� �ش������ �浹�� �ּ��浹���� ���ٸ�
		//�� ������ ���� ����
		if (sum_(i) < min_break)
		{
			min_break = sum_(i);
			ans = 1;
		}
		//���ٸ� ���� �ø���
		else if (sum_(i) == min_break)
			ans++;
	}
	cout << min_break << " " << ans;
}
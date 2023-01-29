/*
https://www.acmicpc.net/problem/11658
����: ���� �� ���ϱ� 3
�з�: ������
���̵�: �÷� 5

���� ���� Ǯ��:
���� �� ���ϱ� 5���� ����� �κи� �ٲ㺼��?
??�̰� �ǳ�
*/

#include<iostream>
#pragma warning(disable:4996)
using namespace std;
int pre_sum[1025][1025];

int main()
{
	int size, test_case, temp;
	cin >> size >> test_case;
	for (int i = 1; i < size+1; ++i)
	{
		for (int j = 1; j < size+1; ++j)
		{
			scanf("%d", &temp);
			pre_sum[i][j] = pre_sum[i][j-1] + temp;
		}
	}
	int beginX, endX, beginY, endY, ans = 0;
	int input, change, dif;

	for (int i = 0; i < test_case; ++i)
	{
		ans = 0;
		scanf("%d", &input);
		if (input == 1)
		{
			//�̺κ��� �ǹ������� ����.
			//�� �ึ�� �������� ���� �̿��ؼ� ���Ͽ� ��� ���Ѱ�
			scanf("%d %d %d %d", &beginY, &beginX, &endY, &endX);
			for (int j = beginY; j <= endY; ++j)
			{
				ans += (pre_sum[j][endX] - pre_sum[j][beginX - 1]);
			}
			printf("%d\n", ans);
		}
		else
		{
			//�̺κ��� �߰��Ȱ�
			//�� ��ġ�� ���Ұ��� ����Ǵ� ������ ���� �̿��� �� ������ �������ش�.
			scanf("%d %d %d", &beginY, &beginX, &change);
			dif = pre_sum[beginY][beginX] - pre_sum[beginY][beginX - 1] - change;
			for (int j = beginX; j < size + 1; ++j)
			{
				pre_sum[beginY][j] -= dif;
			}

		}
		
	}
}
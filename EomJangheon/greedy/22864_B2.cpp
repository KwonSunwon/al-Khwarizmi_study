/*
https://www.acmicpc.net/problem/22864
����: �Ƿε�
�з�: �׸��� �˰���
���̵�: �����2

Ǯ��:
�Ϸ翡 ������ ���� ���̹Ƿ� 24���� ������Ѵ�.
���� ������ �Ѱ��Ƿε��� �ѱ��� �ʴ´ٸ� �� ���Ǿ�� �Ƿε��� �ø���
�׷��� �ʴٸ� �Ƿε��� ���� ���δ�.
*/

#include<iostream>
using namespace std;

int main()
{
	int fatigue = 0, ans = 0;
	int upFatigue = 0, task=0, downFatigue=0, maxFatigue=0;
	cin >> upFatigue >> task >> downFatigue >> maxFatigue;
	
	for (int i = 0; i < 24; ++i)
	{
		if (fatigue + upFatigue <= maxFatigue)
		{
			fatigue += upFatigue;
			ans += task;
		}
		else
			fatigue -= downFatigue;

		if (fatigue < 0)
			fatigue = 0;
	}
	cout << ans;

}
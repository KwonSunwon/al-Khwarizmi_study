/*
https://www.acmicpc.net/problem/2501
����: ������ϱ�
�з�: ����Ž�� �˰���
���̵�: ����� 3

���� ���� Ǯ��:
1���� num���� ������ ������ �ϸ� ������� �����Ѵ�.
*/

#include<iostream>
using namespace std;


int main()
{
	int nowOrder = 0;
	int num, order;
	cin >> num >> order;

	for (int i = 1; i <= num; ++i)
	{
		if (num % i == 0)
			nowOrder++;

		if (nowOrder == order)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << 0;
}
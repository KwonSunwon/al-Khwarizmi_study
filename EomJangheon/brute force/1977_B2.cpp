/*
https://www.acmicpc.net/problem/1977
����: ����������
�з�: ����Ž�� �˰���
���̵�: ����� 2

���� ���� Ǯ��:
�̸� 1���� 100������ �������� ���ϸ� ���� ����� ����Ѵ�.
*/

#include<iostream>
using namespace std;


int main()
{
	int table[101];
	int ansMin = 0;
	int ansSum = 0;
	bool isGetSmall = false;
	int inputMin, inputMax;
	cin >> inputMin >> inputMax;

	for (int i = 0; i < 101; ++i)
	{
		if (i * i >= inputMin && i * i <= inputMax)
		{
			if (!isGetSmall)
			{
				isGetSmall = true;
				ansMin = i * i;
			}
			ansSum += i * i;
		}
	}
	if (!isGetSmall)
	{
		cout << -1 << endl;
		return 0;
	}

	cout << ansSum << endl;
	cout << ansMin << endl;
}
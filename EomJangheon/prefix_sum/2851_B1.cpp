/*
https://www.acmicpc.net/problem/2851
����: ���� ������
�з�: ������
���̵�: ����� 1

���� ���� Ǯ��:

*/

#include<iostream>
using namespace std;
#define MAX 2000000000

int pre_sum[11];

int main()
{
	int temp;
	int ans = MAX;
	cin >> pre_sum[0];
	for (int i = 1; i < 10; ++i)
	{
		cin >> temp;
		pre_sum[i] = pre_sum[i - 1] + temp;
	}


	for (int i = 0; i<10; ++i)
	{
		if (abs(pre_sum[i]- 100) == abs(ans - 100))
		{
			ans = max(pre_sum[i], ans);
		}
		else if (abs(pre_sum[i] - 100) < abs(ans - 100))
		{
			ans = pre_sum[i];
		}
	}
	
	cout << ans;


}
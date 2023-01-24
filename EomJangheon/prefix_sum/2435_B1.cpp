/*
https://www.acmicpc.net/problem/2435
����: ���û ���� ������
�з�: ������
���̵�: ����� 1

���� ���� Ǯ��:

*/

#include<iostream>
using namespace std;
#define MAX 2000000000

int pre_sum[100];

int main()
{
	
	int days, continueity_day;
	cin >> days >> continueity_day;
	cin >> pre_sum[0];
	for (int i = 1; i < days; ++i)
	{
		cin >> pre_sum[i];
		pre_sum[i] += pre_sum[i - 1];
	}

	int ans = pre_sum[continueity_day-1];
	for (int i = continueity_day; i < days; ++i)
		ans = max(ans, pre_sum[i] - pre_sum[i - continueity_day]);


	cout << ans;


}
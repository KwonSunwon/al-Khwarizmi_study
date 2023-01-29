/*
https://www.acmicpc.net/problem/11659
����: ���� �� ���ϱ� 4
�з�: ������
���̵�: �ǹ� 3

���� ���� Ǯ��:

*/

#include<iostream>
#pragma warning(disable:4996)
using namespace std;
int pre_sum[100001];

int main()
{
	int temp;
	int num, test_case;
	cin >> num >> test_case;
	for (int i = 1; i < num+1; ++i)
	{
		scanf("%d", &temp);
		pre_sum[i] = pre_sum[i - 1] + temp;
	}

	
	for (int i = 0; i < test_case; ++i)
	{
		int begin, end;
		scanf("%d %d", &begin, &end);
		printf("%d\n", pre_sum[end] - pre_sum[begin - 1]);
	}
}
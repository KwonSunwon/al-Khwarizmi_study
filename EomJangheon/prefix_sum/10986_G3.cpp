/*
https://www.acmicpc.net/problem/10986
����: ������ ��
�з�: ������
���̵�: ��� 3

���� ���� Ǯ��:
������ ���� �� �׳� �� �غôµ� �ɱ�?...
�翬�ϰԵ� �ȵȴ�.

�ι�° ����: ������ ������ ������ �����ϸ�
�ǽð����� �������� ������Ʈ�ϸ鼭?
������ �ȵȴ�

����° ����:
���� �𸣴� ������ �ִ�.. �˰��� �з� ���� ������ �ִ�.
100% ������������ ���� �ִ�
https://cocoon1787.tistory.com/396
���� ���� ����
(PrefixSum[j] - PrefixSum[i] ) % MOD = 0 �� �����Ѵٸ�
PrefixSum[j] % MOD = PrefixSum[i] % MOD �� �����ϰ� �ȴ�.
��� �Ǿ��ִ�... ������ ã�ƺ���
������ ������ �й��Ģ�� ����ȴٰ� �Ѵ�.
�� �̰��� ����ϸ� �������� ���� ������ �� �� ã���� �ȴ�.
�׷��� �������� ������ ���� �Ǵϱ�
*/

#include<iostream>
#define MAX 2000000000
#pragma warning(disable:4996)
using namespace std;

long long int pre_sum[1000001];
long long int table[1000];
int main()
{
	long long int num, mod, temp;
	long long int ans = 0;
	long long int sum = 0;
	cin >> num >> mod;
	for (int i = 0; i < num; ++i)
	{
		//�ǽð����� �ش� �ε����� �������� �����ϴ� ���̺� ����
		scanf("%d", &temp);
		sum = (sum + temp) % mod;
		table[sum]++;
	}

	//0~�ε������� �������� 0�̸� ������ ��������
	ans += table[0];

	//0~�ε���1����, 0~�ε���2������ �������� ���ٸ�
	//�ε���1~�ε���2������ ���� �������� 0�̵ȴ�.
	//��ⷯ���� �й��Ģ Ȯ��
	//���� Ȯ���� ������ �̿��ؼ� ����Ѵ�.
	for (int i = 0; i < mod; ++i)
	{
		if (table[i] >= 2)
			ans += table[i] * (table[i] - 1) / 2;
	}
	cout << ans;
}
/*
https://www.acmicpc.net/problem/1449
����: ������ �׽�
�з�: �׸��� �˰���
���̵�: �ǹ�3

Ǯ��:
�켱 �Է°��� ��� �����Ѵ�.
�׸��� ���� �������� ������ ���⼭ tapeLen-1�� �Ÿ��� ����
��� ���峭 �κ��� ��ģ��.
�̸� �ݺ��Ѵ�.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int tapeLen = 0;
	int breakNum = 0;
	int tempInput = 0;
	int ans = 0;
	vector<int> breakPos;

	cin >> breakNum >> tapeLen;

	for (int i = 0; i < breakNum; ++i)
	{
		cin >> tempInput;
		breakPos.push_back(tempInput);
	}
	sort(breakPos.begin(), breakPos.end(),greater<>());

	while (!breakPos.empty())
	{
		int firstPos = breakPos.back();
		breakPos.pop_back();

		while (!breakPos.empty())
		{
			if (breakPos.back() > (firstPos + tapeLen - 1))
				break;
			else breakPos.pop_back();
		}
		ans++;
	}
	cout << ans;
}
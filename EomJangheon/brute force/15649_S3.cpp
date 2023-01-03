/*
https://www.acmicpc.net/problem/15649
����: N��M (1)
�з�: ����Ž�� �˰���
���̵�: �ǹ� 3

���� ���� Ǯ��:
��� ȣ���� ���� �ϳ��� ���� �����̳ʿ� ��� ����Ѵ�.
*/

#include<iostream>
#include<vector>
using namespace std;
int num, arrLen;
void NM(int num);
bool checkInAns(int n);
vector<int> ans;

int main()
{
	cin >> num >> arrLen;

	for (int i = 1; i <= num; ++i)
	{
		ans.clear();
		NM(i);
	}
}

void NM(int n)
{
	ans.push_back(n);
	if (ans.size() == arrLen)
	{
		for (int i = 0; i < ans.size(); ++i)
		{
			printf("%d ", ans[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= num; ++i)
	{
		if (!checkInAns(i))
		{

			NM(i);
			ans.pop_back();
		}
	}
}

bool checkInAns(int n)
{
	for (int i = 0; i < ans.size(); ++i)
	{
		if (ans[i] == n)
			return true;
	}
	return false;
}
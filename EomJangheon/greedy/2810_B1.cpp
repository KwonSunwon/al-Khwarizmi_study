/*
https://www.acmicpc.net/problem/2810
����: ��Ȧ��
�з�: �׸��� �˰���
���̵�: �����1

Ǯ��: 
�⺻������ 1���� ��Ȧ�尡 1�� �ִٰ� �����Ѵ�.
���� S�� 1��, LL�� 1���� �þ��.
�� ����Ҽ� �ִ� ��Ȧ��� 1+num(S)+num(LL)
*/

#include<iostream>
using namespace std;

int main()
{
	int ans = 0+2;
	int numOfInput = 0;
	string input;
	cin >> numOfInput >> input;
	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] == 'S')
			ans += 2;
		else
			ans += 1;
	}
	ans=min(ans/2,(int)input.size());
	cout << ans;
}
/*
https://www.acmicpc.net/problem/1783
����: ���� ����Ʈ
�з�: �׸��� �˰���
���̵�: �ǹ�3

Ǯ��:
�켱 ���� ������, �� �Ʒ��� �̵��� �����ϴ�.
���ΰ� 1�϶� ���� 1�� �����̴�.
���ΰ� 2�϶��� ������ ���������� ��ĭ�� �̵��Ѵ�. �̶� �������� 4���̻��϶� 4�� ����
���ΰ� 3�̻��̶��, ���θ� ���࿡ ���߾� �ϳ��� �����Ѵ�.
*/

#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	int ans = 0;
	int height = 0, width = 0;
	cin >> height >> width;
	if (height == 1)
		ans = 1;
	else if (height == 2)
	{
		ans = (width + 1) / 2;
		if (ans > 4)
			ans = 4;
	}
	else if (width < 5)
		ans = width;
	else if (width == 5)
		ans = width - 1;
	else
		ans = width - 2;

	cout << ans;
}
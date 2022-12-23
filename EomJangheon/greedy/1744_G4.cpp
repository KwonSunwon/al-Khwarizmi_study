/*
https://www.acmicpc.net/problem/1744
����: �� ����
�з�: �׸��� �˰���
���̵�: ��� 4

���� ���� Ǯ��:
1.������ 2�� �̻� �ִٸ� �׻� ���� ū �������� ������Ѵ�.
2.������ 1��, 0�� 1�� �ִٸ� �׻� ������Ѵ�.
3.����� 2�� �̻� �ִٸ� �׻� ���� ū ������� ������Ѵ�.
�̸� ���� ����� �ִ���, ������ �ּ����� ����ϸ� 0�� ���縸�� üũ�ϴ� bool Ÿ��

�ι�° Ǯ��:
���� �������δ� Ʋ�� ���� ���Դ�.
�ݷʸ� ã�ƺ��� 1�� ������ �� ū���� ������ ����� �۾���
ex)1+20=21-->1*20=20
4.�Է��� 1�� ������ ans�� �״�� ���ϴ� ���� �߰�
*/

#include<iostream>
#include<queue>
using namespace std;


int main()
{
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;
	int ans = 0;
	int numOfInput = 0;
	int tempInput = 0;
	bool isZeroExist = false;

	cin >> numOfInput;

	//������ �ּ���, ¦���� �ִ������� �־��ش�(���밪�� ū ���� �̱� ����)
	//0�� �ִ����� üũ�Ѵ�.
	for (int i = 0; i < numOfInput; ++i)
	{
		cin >> tempInput;
		//�߰��� 4��° �����̴�.
		if (tempInput == 1)
			ans += 1;

		else if (tempInput < 0)
			min_heap.push(tempInput);
		else if (tempInput > 1)
			max_heap.push(tempInput);
		else if(tempInput==0)
			isZeroExist = true;
	}
	//1. ������ 2�� �̻� �ִٸ� �׻� ���� ū �������� ���´�.
	//�ݺ����� ��� min_heap�� 0���Ǵ� 1���� ���Ҹ� ���´�.
	while (!min_heap.empty())
	{
		if (min_heap.size() >= 2)
		{
			int first = min_heap.top();
			min_heap.pop();
			int second = min_heap.top();
			min_heap.pop();
			ans += first * second;
		}
		//2. ������ 1��, 0�� ���� �Ѵٸ� �׻� ���´�.
		//   ������ 1�� ������ 0�� ���� ���� �ʴ´ٸ� �״�� ���Ѵ�.
		else
		{
			if (isZeroExist)
				ans += 0;
			else
				ans += min_heap.top();
			min_heap.pop();
		}
	}

	//3. ����� 2�� �̻� �ִٸ� �׻� ���� ū ������� ���´�.
	//�ݺ����� ��� max_heap�� 0���Ǵ� 1���� ���Ҹ� ���´�.
	while (!max_heap.empty())
	{
		if (max_heap.size() >= 2)
		{
			int first = max_heap.top();
			max_heap.pop();
			int second = max_heap.top();
			max_heap.pop();
			ans += first * second;
		}
		//4. ���������� ���� ����� �ִٸ� �����ش�.
		else
		{
			ans += max_heap.top();
			max_heap.pop();
		}
	}

	cout << ans;

}
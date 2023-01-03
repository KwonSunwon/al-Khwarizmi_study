/*
https://www.acmicpc.net/problem/2501
제목: 약수구하기
분류: 완전탐색 알고리즘
난이도: 브론즈 3

최초 접근 풀이:
1부터 num까지 나머지 연산을 하며 약수인지 구분한다.
*/

#include<iostream>
using namespace std;


int main()
{
	int nowOrder = 0;
	int num, order;
	cin >> num >> order;

	for (int i = 1; i <= num; ++i)
	{
		if (num % i == 0)
			nowOrder++;

		if (nowOrder == order)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << 0;
}
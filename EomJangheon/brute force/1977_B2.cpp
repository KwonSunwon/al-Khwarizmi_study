/*
https://www.acmicpc.net/problem/1977
제목: 완전제곱수
분류: 완전탐색 알고리즘
난이도: 브론즈 2

최초 접근 풀이:
미리 1부터 100까지의 제곱수를 구하며 범위 내라면 계산한다.
*/

#include<iostream>
using namespace std;


int main()
{
	int table[101];
	int ansMin = 0;
	int ansSum = 0;
	bool isGetSmall = false;
	int inputMin, inputMax;
	cin >> inputMin >> inputMax;

	for (int i = 0; i < 101; ++i)
	{
		if (i * i >= inputMin && i * i <= inputMax)
		{
			if (!isGetSmall)
			{
				isGetSmall = true;
				ansMin = i * i;
			}
			ansSum += i * i;
		}
	}
	if (!isGetSmall)
	{
		cout << -1 << endl;
		return 0;
	}

	cout << ansSum << endl;
	cout << ansMin << endl;
}
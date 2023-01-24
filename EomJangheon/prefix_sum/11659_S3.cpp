/*
https://www.acmicpc.net/problem/11659
제목: 구간 합 구하기 4
분류: 누적합
난이도: 실버 3

최초 접근 풀이:

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
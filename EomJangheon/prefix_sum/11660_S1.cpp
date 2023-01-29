/*
https://www.acmicpc.net/problem/11660
제목: 구간 합 구하기 5
분류: 누적합
난이도: 실버 1

최초 접근 풀이:

*/

#include<iostream>
#pragma warning(disable:4996)
using namespace std;
int pre_sum[1025][1025];

int main()
{
	int size, test_case, temp;
	cin >> size >> test_case;
	for (int i = 1; i < size+1; ++i)
	{
		for (int j = 1; j < size+1; ++j)
		{
			scanf("%d", &temp);
			pre_sum[i][j] = pre_sum[i][j-1] + temp;
		}
	}


	for (int i = 0; i < test_case; ++i)
	{
		int beginX, endX, beginY, endY, ans = 0;
		scanf("%d %d %d %d", &beginY, &beginX, &endY, &endX);
		for (int j = beginY; j <= endY; ++j)
		{
			ans += (pre_sum[j][endX] - pre_sum[j][beginX-1]);
		}
		printf("%d\n", ans);
	}
}
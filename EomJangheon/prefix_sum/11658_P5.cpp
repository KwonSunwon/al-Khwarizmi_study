/*
https://www.acmicpc.net/problem/11658
제목: 구간 합 구하기 3
분류: 누적합
난이도: 플레 5

최초 접근 풀이:
구간 합 구하기 5에서 변경된 부분만 바꿔볼까?
??이게 되네
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
	int beginX, endX, beginY, endY, ans = 0;
	int input, change, dif;

	for (int i = 0; i < test_case; ++i)
	{
		ans = 0;
		scanf("%d", &input);
		if (input == 1)
		{
			//이부분은 실버문제와 같다.
			//각 행마다 구간합의 차를 이용해서 구하여 모두 더한것
			scanf("%d %d %d %d", &beginY, &beginX, &endY, &endX);
			for (int j = beginY; j <= endY; ++j)
			{
				ans += (pre_sum[j][endX] - pre_sum[j][beginX - 1]);
			}
			printf("%d\n", ans);
		}
		else
		{
			//이부분이 추가된곳
			//그 위치의 원소값과 변경되는 숫자의 차를 이용해 뒷 구간을 갱신해준다.
			scanf("%d %d %d", &beginY, &beginX, &change);
			dif = pre_sum[beginY][beginX] - pre_sum[beginY][beginX - 1] - change;
			for (int j = beginX; j < size + 1; ++j)
			{
				pre_sum[beginY][j] -= dif;
			}

		}
		
	}
}
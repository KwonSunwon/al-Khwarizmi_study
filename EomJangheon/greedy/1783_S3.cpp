/*
https://www.acmicpc.net/problem/1783
제목: 병든 나이트
분류: 그리디 알고리즘
난이도: 실버3

풀이:
우선 말은 오른쪽, 위 아래만 이동이 가능하다.
세로가 1일때 답은 1로 고정이다.
세로가 2일때는 무조건 오른쪽으로 두칸씩 이동한다. 이때 제약으로 4번이상일때 4로 고정
세로가 3이상이라면, 가로를 제약에 맞추어 하나씩 구분한다.
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
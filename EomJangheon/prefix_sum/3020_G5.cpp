/*
https://www.acmicpc.net/problem/3020
제목: 개똥벌레
분류: 누적합
난이도: 골드 5

최초 접근 풀이:
만약 석순이라면 1~크기까지의 값을 1 올린다.
만약 종유석이라면 높이-크기+1 부터 높이까지 값을 1 올린다.
연속된 구간이 한번에 같은 값을 올린다? 바로 펜윅트리 적용
코드는 이전에 펜윅트리 코드에서 긁었다.
*/

#include<iostream>
#define MAX 2000000000
#pragma warning(disable:4996)
using namespace std;
int fen[500001];
int width, height;

//이전 펜윅트리 함수
void upd_(int i, int j, int x) {
	while (i < height + 1)
	{
		fen[i] += x;
		i += (i & -i);
	}
	while (j < height + 1)
	{
		fen[j] -= x;
		j += (j & -j);
	}
}

int sum_(int i) {
	int ret = 0;
	while (i)
	{
		ret += fen[i];
		i -= (i & -i);
	}
	return ret;
}

int main()
{
	int temp;
	int ans = 0;
	int min_break = MAX;
	cin >> width >> height;
	for (int i = 0; i < width / 2; ++i)
	{
		//1~크기까지 업데이트
		scanf("%d", &temp);
		upd_(1, temp + 1, 1);

		//~높이까지 업데이트
		scanf("%d", &temp);
		upd_(height - temp + 1, height + 1, 1);
	}

	for (int i = 1; i < height + 1; ++i)
	{
		//만약 해당높이의 충돌이 최소충돌보다 적다면
		//값 변경후 정답 갱신
		if (sum_(i) < min_break)
		{
			min_break = sum_(i);
			ans = 1;
		}
		//같다면 정답 늘리기
		else if (sum_(i) == min_break)
			ans++;
	}
	cout << min_break << " " << ans;
}
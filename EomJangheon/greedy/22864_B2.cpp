/*
https://www.acmicpc.net/problem/22864
제목: 피로도
분류: 그리디 알고리즘
난이도: 브론즈2

풀이:
하루에 가능한 일의 양이므로 24번의 계산을한다.
일을 했을때 한계피로도를 넘기지 않는다면 총 일의양과 피로도를 늘린다
그렇지 않다면 피로도의 양을 줄인다.
*/

#include<iostream>
using namespace std;

int main()
{
	int fatigue = 0, ans = 0;
	int upFatigue = 0, task=0, downFatigue=0, maxFatigue=0;
	cin >> upFatigue >> task >> downFatigue >> maxFatigue;
	
	for (int i = 0; i < 24; ++i)
	{
		if (fatigue + upFatigue <= maxFatigue)
		{
			fatigue += upFatigue;
			ans += task;
		}
		else
			fatigue -= downFatigue;

		if (fatigue < 0)
			fatigue = 0;
	}
	cout << ans;

}
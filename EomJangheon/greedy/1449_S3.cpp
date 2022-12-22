/*
https://www.acmicpc.net/problem/1449
제목: 수리공 항승
분류: 그리디 알고리즘
난이도: 실버3

풀이:
우선 입력값을 모두 정렬한다.
그리고 가장 가까운것을 꺼내고 여기서 tapeLen-1의 거리를 가진
모든 고장난 부분을 고친다.
이를 반복한다.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int tapeLen = 0;
	int breakNum = 0;
	int tempInput = 0;
	int ans = 0;
	vector<int> breakPos;

	cin >> breakNum >> tapeLen;

	for (int i = 0; i < breakNum; ++i)
	{
		cin >> tempInput;
		breakPos.push_back(tempInput);
	}
	sort(breakPos.begin(), breakPos.end(),greater<>());

	while (!breakPos.empty())
	{
		int firstPos = breakPos.back();
		breakPos.pop_back();

		while (!breakPos.empty())
		{
			if (breakPos.back() > (firstPos + tapeLen - 1))
				break;
			else breakPos.pop_back();
		}
		ans++;
	}
	cout << ans;
}
/*
https://www.acmicpc.net/problem/2810
제목: 컵홀더
분류: 그리디 알고리즘
난이도: 브론즈1

풀이: 
기본적으로 1개의 컵홀드가 1개 있다고 가정한다.
이후 S당 1개, LL당 1개가 늘어난다.
즉 사용할수 있는 컵홀드는 1+num(S)+num(LL)
*/

#include<iostream>
using namespace std;

int main()
{
	int ans = 0+2;
	int numOfInput = 0;
	string input;
	cin >> numOfInput >> input;
	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] == 'S')
			ans += 2;
		else
			ans += 1;
	}
	ans=min(ans/2,(int)input.size());
	cout << ans;
}
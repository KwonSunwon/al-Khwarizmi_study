/*
https://www.acmicpc.net/problem/10986
제목: 나머지 합
분류: 누적합
난이도: 골드 3

최초 접근 풀이:
누적합 적용 후 그냥 다 해봤는데 될까?...
당연하게도 안된다.

두번째 접근: 나머지 연산을 찬찬히 생각하며
실시간으로 나머지를 업데이트하면서?
구현이 안된다

세번째 접근:
내가 모르는 뭔가가 있다.. 알고리즘 분류 보니 수학이 있다.
100% 정수론적으로 뭔가 있다
https://cocoon1787.tistory.com/396
여기 글을 보면
(PrefixSum[j] - PrefixSum[i] ) % MOD = 0 이 만족한다면
PrefixSum[j] % MOD = PrefixSum[i] % MOD 도 만족하게 된다.
라고 되어있다... 왜인지 찾아보니
나머지 연산은 분배법칙이 적용된다고 한다.
즉 이것을 사용하면 나머지가 같은 구간을 두 개 찾으면 된다.
그러면 구간에서 구간을 빼면 되니까
*/

#include<iostream>
#define MAX 2000000000
#pragma warning(disable:4996)
using namespace std;

long long int pre_sum[1000001];
long long int table[1000];
int main()
{
	long long int num, mod, temp;
	long long int ans = 0;
	long long int sum = 0;
	cin >> num >> mod;
	for (int i = 0; i < num; ++i)
	{
		//실시간으로 해당 인덱스의 나머지를 저장하는 테이블 갱신
		scanf("%d", &temp);
		sum = (sum + temp) % mod;
		table[sum]++;
	}

	//0~인덱스까지 나머지가 0이면 나누어 떨어진다
	ans += table[0];

	//0~인덱스1까지, 0~인덱스2까지의 나머지가 같다면
	//인덱스1~인덱스2까지의 합은 나머지가 0이된다.
	//모듈러연산 분배법칙 확인
	//이후 확통의 조합을 이용해서 계산한다.
	for (int i = 0; i < mod; ++i)
	{
		if (table[i] >= 2)
			ans += table[i] * (table[i] - 1) / 2;
	}
	cout << ans;
}
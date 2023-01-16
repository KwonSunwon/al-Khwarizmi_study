/*
1번 접근 : ski 수열을 진행하다 중복되는 수가 나오는 순간 사이클이 발생한다. 그러니 발생하기 전까지만 확인하고 그 최소값을 더한다.


*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
long long dp[1000001]; // dp[i]:Sk(i)의 최소값
bool visit[1000001];
long long ski[1000001];
long long p[10];

long long calc(long long x) {
	if (x <= 1000000 && ski[x]) return ski[x];
	long long ret = 0;

	while (x) {
		ret += p[x % 10];
		x /= 10;
	}

	if (ret > 1000000) return calc(ret);

	return ret;
}

void f(vector<long long> acc) {
	long long cur = acc.back();

	if (!dp[cur] && visit[cur]) { // cur부터 시작하는 사이클을 이 사이클의 최솟값으로 모두 채움.
		long long tmp = ski[cur];
		long long minn = cur;

		while (tmp != cur) {
			minn = min(minn, tmp);
			tmp = ski[tmp];
		}

		dp[cur] = minn;
		tmp = ski[cur];

		while (tmp != cur) {
			dp[tmp] = minn;
			tmp = ski[tmp];
		}

		for (int i = acc.size() - 1; i >= 0; --i) {
			if (!dp[acc[i]]) {
				minn = min(minn, acc[i]);
				dp[acc[i]] = minn;
			}

		}
		return;
	}

	if (dp[cur]) {
		long long minn = dp[cur];

		for (int i = acc.size() - 1; i >= 0; --i) {
			if (!dp[acc[i]]) {
				minn = min(minn, acc[i]);
				dp[acc[i]] = minn;
			}
		}

		return;
	}

	acc.push_back(ski[cur]);
	visit[cur] = true;
	f(acc);
}

int main() {
	long long A, B, K; 
	
	cin >> A >> B >> K;

	for (int i = 0; i < 10; ++i) {
		p[i] = pow(i, K);
	}

	for (int i = 1; i <= 1000000; ++i) {
		ski[i] = calc(i);
	}

	long long res = 0;

	for (long long i = A; i <= B; ++i) {
		if (!dp[i]) {
			vector<long long> temp;
			temp.push_back(i);
			f(temp);
		}

		res += dp[i];
	}

	cout << res << '\n';

}
/*
	접근법 1: 원소를 하나씩 추가하면서 해당 원소로 끝나는 부분배열중 그 합이 가장 크고 S보다 큰 것의 길이를 저장, 가장 짧은 것을 선택한다.
	         -해당 줄의 크기와 길이를 저장하기 위해 pair를 원소로 하는 vector 사용
	>> 틀렸음.
	틀린 이유 : 아마 가장 크지 않은 부분 배열중에 S보다 크고 더 짧은 부분 배열이 존재하는듯 함

	알고리즘 분류에 두 포인터가 있어서 찾아봄
	>> 찾다보니 이 문제 자체가 투 포인터의 대표격이란 사실을 알게됨 ㄴㅇㄱ

	접근법2 : 투 포인터 기법을 사용해서 가장 짧은 거리 구하기 (총합이 S보다 작으면 high 증가 아니면 low 증가)

	vector 범위 오류로 인한 런타임 오류 발생. >> while문의 조건을 N-1로 수정

	틀렸습니다? >> 범위는 high - low가 아니라 high - low + 1임

	또 틀렷따 뭐가 문제노 >> 질문 게시판에 반례 찾음
	10 10
	1 1 1 1 1 1 1 1 1 10
	일전에 바꿨던 N => N-1이 문제였음 N으로 바꾸니 맞춤
*/

#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> list;
int res{100001};
int low{ 0 }, high{ 0 };
int sum;

int main() {
	cin >> N >> S;

	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;

		list.emplace_back(temp);
	}

	sum = list[0];

	while (low <= high && high < N) {
		if (sum < S) {
			sum += list[++high];
		}

		else {
			res = min(res, high - low + 1);
			sum -= list[low++];
		}
	}

	if (res == 100001) res = 0;
	cout << res;
}
/*
	���ٹ� 1: ���Ҹ� �ϳ��� �߰��ϸ鼭 �ش� ���ҷ� ������ �κй迭�� �� ���� ���� ũ�� S���� ū ���� ���̸� ����, ���� ª�� ���� �����Ѵ�.
	         -�ش� ���� ũ��� ���̸� �����ϱ� ���� pair�� ���ҷ� �ϴ� vector ���
	>> Ʋ����.
	Ʋ�� ���� : �Ƹ� ���� ũ�� ���� �κ� �迭�߿� S���� ũ�� �� ª�� �κ� �迭�� �����ϴµ� ��

	�˰��� �з��� �� �����Ͱ� �־ ã�ƺ�
	>> ã�ٺ��� �� ���� ��ü�� �� �������� ��ǥ���̶� ����� �˰Ե� ������

	���ٹ�2 : �� ������ ����� ����ؼ� ���� ª�� �Ÿ� ���ϱ� (������ S���� ������ high ���� �ƴϸ� low ����)

	vector ���� ������ ���� ��Ÿ�� ���� �߻�. >> while���� ������ N-1�� ����

	Ʋ�Ƚ��ϴ�? >> ������ high - low�� �ƴ϶� high - low + 1��

	�� Ʋ�ǵ� ���� ������ >> ���� �Խ��ǿ� �ݷ� ã��
	10 10
	1 1 1 1 1 1 1 1 1 10
	������ �ٲ�� N => N-1�� �������� N���� �ٲٴ� ����
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
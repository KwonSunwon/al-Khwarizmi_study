/*===================
1�� ���� : �־��� �� �߿��� k���� ���� ��� ������� �����ϰ�, �� ���� ���Ͽ� �ּҰ����� ����

���� �߻� : �־��� ������ ���� ������ �ʿ䰡 �ִ�.
          --> temp vector�� ���� ���縦 ���� ���� <<�޸𸮸� �ʹ� ���� ���� �ȴ�.

1�� ���� ���� : k���� üĿ �� �� �������� ��ƾ� ���� ���� �� ���� --> ���� �غ��� �Ѵ�. �̰� �������� �ʹ� ����
               n���� üĿ �߿� k���� üĿ�� ���°� �ֹٴ�. n�� Ŀ���� �ٷ� �״´�. �ٸ� ����� �ʿ�
              

2�� ���� : ���� �����ϰ� �� �߿� ������ ���� �߽� üĿ�� �����ϰ� �α��� ����� üĿ�� �̵���Ų��.

���� �߻� : ���� Ʋ��. ������ ����?
          --> �̰� üĿ�� �߽����� ��°� �ƴ϶� Ư�� ���� �߽����� ��°� �� ������ ���� ������ ��찡 �����Ѵ�. ��...

3�� ���� : �߽����� ã��, �� �ڸ��� �߽����� �� ����� ���� ���Ѵ�. 

���� �߻� : �׷��� �߽����� ��� ã��?
           -->��Ȯ�� �߽����� ã�°� �Ұ����ϰ� �ĺ��� ���� ���غ��� �Ѵ� �̰Ž� ���Ʈ����..?

��¥ ���� �߻�!!! : �� Ʋ�ȴµ�?
                  --> res�� �ʱⰪ�� �ʹ� ���� ��ҳ�����.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class spot {
public:
	long long x;
	long long y;

	spot(long long _x, long long _y) {
		x = _x; y = _y;
	}

	void print() {
		cout << "x = " << x << " y = " << y << endl;
	}
};

long long get_move(int, spot);

int EA{ 0 };
vector<spot> midle;
long long x[50], y[50];

int main() {

	cin >> EA;

	for (int i = 0; i < EA; ++i) {
		int temp_x, temp_y;
		cin >> x[i] >> y[i];
	}

	for (int i = 0; i < EA; ++i) {
		for (int j = 0; j < EA; ++j) {
			midle.emplace_back(x[i], y[j]);
		}
	}

	for (int i = 0; i < EA; ++i) {
		long long res{(long long) 2e9};

		for (int j = 0; j < midle.size(); ++j) {
			res = min(res, get_move(i, midle[j]));
		}

		cout << res << " ";
	}
}

long long get_move(int ea, spot mid) {
	vector<long long> dis;
	long long total{ 0 };

	for (int i = 0; i < EA; ++i) {
		dis.emplace_back(abs(x[i] - mid.x) + abs(y[i] - mid.y));
	}

	sort(dis.begin(), dis.end());

	for (int i = 0; i <= ea; ++i) {
		total += dis[i];
	}

	return total;
}
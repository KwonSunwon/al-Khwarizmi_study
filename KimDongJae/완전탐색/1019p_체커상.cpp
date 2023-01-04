/*===================
1차 접근 : 주어진 점 중에서 k개의 점을 골라서 결과값을 도출하고, 각 값을 비교하여 최소값으로 선택

문제 발생 : 주어진 점들을 따로 관리할 필요가 있다.
          --> temp vector를 만들어서 복사를 통해 관리 <<메모리를 너무 많이 쓰게 된다.

1차 접근 실패 : k개의 체커 중 뭘 기준으로 모아야 할지 정할 수 없다 --> 전부 해봐야 한다. 이거 가지수가 너무 많다
               n개의 체커 중에 k개의 체커를 고르는거 애바다. n이 커지니 바로 죽는다. 다른 방법이 필요
              

2차 접근 : 점을 선택하고 그 중에 모으지 말고 중심 체커를 선택하고 인근의 가까운 체커를 이동시킨다.

문제 발생 : 답이 틀림. 이유가 뭘까?
          --> 이거 체커를 중심으로 잡는게 아니라 특정 점을 중심으로 잡는게 더 최적의 값을 가지는 경우가 존재한다. 즉...

3차 접근 : 중심점을 찾고, 그 자리를 중심으로 할 경우의 값을 구한다. 

문제 발생 : 그래서 중심점은 어떻게 찾지?
           -->정확한 중심점을 찾는건 불가능하고 후보에 대해 구해봐야 한다 이거시 브루트포스..?

진짜 문제 발생!!! : 왜 틀렸는데?
                  --> res의 초기값을 너무 낮게 잡았나보다.
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
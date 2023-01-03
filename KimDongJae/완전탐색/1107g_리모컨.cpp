/*==============================
1차 접근 : 사용할 수 있는 버튼으로 만들 수 있는 가장 가까운 수를 구한 뒤, 거기서 +,- 버튼을 눌러 이동한다.
1차 접근 개선점 : 채널이 몇자리인지 알기 쉽도록 string으로 받아서 int로 변환하자
-->2차 접근에서 자리수별로 접근하는 의미가 사라짐

문제 발생 : 가까운 수를 구할 때 숫자가 연속으로 사용할 수 없는 경우 최적의 수를 찾지 못함
           --> 쓰지 못하는 숫자가 아니라 쓸수 있는 숫자를 저장하면 어떨까?
		   --> set에서 bool array로 변경

1차 접근 실패 : 각 자리수에서 가까운 숫자를 찾는 방법은 연속된 고장과 인접한 수 찾기에 부적합하다.
2차 접근 : +나 -버튼은 둘 중 하나만 누를 수 있다. 이 때문에 첫 수를 만드는것에 집중해야한다. 최악의 경우(모든 버튼이 고장)을 준비하고
           모든 경우를 확인하면서(브루트 포스) 현재의 결과값보다 나은 결과를 발견하면 채택하는것을 반복한다.
		   즉, 특정 버튼을 만드는 경우 + 그 버튼에서 목표까지 +or- 하는 경우를 전부 구한다.

문제 발생 : 틀렸다. 이유를 살펴보며 예제 값들을 대입하다보니 문제 발견 --> 500000같은 큰 수는 작은 수에서 더해가는 것 보다 훨씬 큰
           수에서 빼나가는게 더 좋다. 즉 0 ~ 500000까지의 범위가 아니라 더 큰 범위여야 한다. 
문제 해결 : 목표 채널의 최대값은 500000 이다. 이 녀석의 두배값 1000000보다 큰 값은 빼는데 500000보다 더 많이 눌러야 해서 탐색할 의미가 없다.
            즉, 범위를 1 ~ 1000000 으로 잡자
	      
*/

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int channel{ 0 };
	int digit{ 0 };
	int target{ 0 };
	bool button[10]{ true,true ,true ,true,true ,true ,true ,true ,true ,true };
	int EA{ 0 };
	int res{ 0 };

	cin >> target;
	cin >> EA;

	for (int i = 0; i < EA; ++i) {
		int temp;
		cin >> temp;

		button[temp] = false;
	}

	res = abs(target - 100); //최악의 경우

	for (int i = 0; i <= 1000000; ++i) {
		int press = 0;
		int temp = i;
		if (temp == 0) {
			if (!button[temp]) {
				press = 0;
			}

			else {
				press = 1;
			}
		}

		while (temp > 0) {
			if (!button[temp % 10]) {
				press = 0;
				break;
			}

			temp = temp / 10;
			++press;
		}

		if (press > 0) {
			int repeat = abs(i - target);

			if (res > press + repeat) res = press + repeat;
		}
	}

	cout << res;
}
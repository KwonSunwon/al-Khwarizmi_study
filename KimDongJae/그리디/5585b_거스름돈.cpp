//백준 5585번 거스름돈 문제
#include <iostream>

int main() {
	int pay, EA{ 0 };
	std::cin >> pay;
	int change{ 1000 - pay };
	int money_list[6]{ 500,100,50,10,5,1 };

	for (int i = 0; i < 6; i++) {
		while (change >= money_list[i]) {
			change -= money_list[i];
			++EA;
		}

		if (change == 0) break;
	}

	std::cout << EA;
}
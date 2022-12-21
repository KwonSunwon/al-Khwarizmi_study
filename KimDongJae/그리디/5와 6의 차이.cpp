#include <iostream>

int main() {
    int A;
    int B;

    std::cin >> A;
    std::cin >> B;

    int maxA{ 0 }, maxB{ 0 };
    int minA{ 0 }, minB{ 0 };

    for (int i = 100000; i > 0; i /= 10) {
        int tempA = A / i;
        int tempB = B / i;

        if (tempA != 0) {
            if (tempA == 5 || tempA == 6) {
                minA += 5 * i; maxA += 6 * i;
            }

            else {
                minA += tempA * i; maxA += tempA * i;
            }
            A -= tempA * i;
        }

        if (tempB != 0) {
            if (tempB == 5 || tempB == 6) {
                minB += 5 * i; maxB += 6 * i;
            }

            else {
                minB += tempB * i; maxB += tempB * i;
            }
            B -= tempB * i;
        }
    }

    std::cout << minA + minB << ' ' << maxA + maxB;
}
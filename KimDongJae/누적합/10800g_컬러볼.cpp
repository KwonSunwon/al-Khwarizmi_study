/*
1차 접근법 : 보자마자 떠올릴 수 있는 순차 탐색하며 조건에 맞으면 합산하는 방식 사용
==> 역시나 시간 초과 발생

2차 접근법 : 정렬한 뒤 나보다 작으면서 색이 다른 녀석만 먹으면 된다. << 출력을 위해 순서를 보관해야 함
            vector를 sort를 해도 주소값은 변하지 않는다는 가정 하에, 주소값을 따로 저장하는 방법이 유효할 거 같다.
문제 발생 : 너무 복잡하다. 이렇게까지 할 필요는 없을거 같은데..

3차 접근법 : 정렬을 하고난 뒤에 나와 색이 같은 녀석의 무게와 무게가 같은 녀석의 무게를 빼야한다. 

틀렸습니다. >> 내 무게를 color와 weight에 둘 다 더해놓고 둘 다 빼니 내 무게만큼 손실이 발생한다.
           >> 식 끝에 내 무게를 더한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ball {
public:
    int weight, color, idx;
};

int res[200000] = { 0, };
int C[200001] = { 0, };
int S[2000] = { 0, };
int EA;

bool comp(ball& a, ball& b) {

    if (a.weight == b.weight) {
        return a.color < b.color;
    }

    return a.weight < b.weight;
}

int main(void) {
    vector <ball> v;

    cin >> EA;
    for (int i = 0; i < EA ; ++ i) {
        int weight, color;
        cin >> color >> weight;
        v.push_back({ weight,color,i });
    }

    sort(v.begin(), v.end(), comp);

    int sum = 0;

    for (int i = 0;i < EA ; ++i) {

        int weight = v[i].weight;
        int color = v[i].color;
        int idx = v[i].idx;

        C[color] += weight;
        S[weight] += weight;
        sum += weight;

        res[idx] = sum - C[color] - S[weight] + weight;

        if (i != 0 && (v[i - 1].color == color) && (v[i - 1].weight == weight))    res[idx] = res[v[i - 1].idx];
    }

    for (int i = 0; i < EA; ++i) {
        cout << res[i] << "\n";
    }

}
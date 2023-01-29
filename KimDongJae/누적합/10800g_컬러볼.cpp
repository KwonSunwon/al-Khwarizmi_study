/*
1�� ���ٹ� : ���ڸ��� ���ø� �� �ִ� ���� Ž���ϸ� ���ǿ� ������ �ջ��ϴ� ��� ���
==> ���ó� �ð� �ʰ� �߻�

2�� ���ٹ� : ������ �� ������ �����鼭 ���� �ٸ� �༮�� ������ �ȴ�. << ����� ���� ������ �����ؾ� ��
            vector�� sort�� �ص� �ּҰ��� ������ �ʴ´ٴ� ���� �Ͽ�, �ּҰ��� ���� �����ϴ� ����� ��ȿ�� �� ����.
���� �߻� : �ʹ� �����ϴ�. �̷��Ա��� �� �ʿ�� ������ ������..

3�� ���ٹ� : ������ �ϰ� �ڿ� ���� ���� ���� �༮�� ���Կ� ���԰� ���� �༮�� ���Ը� �����Ѵ�. 

Ʋ�Ƚ��ϴ�. >> �� ���Ը� color�� weight�� �� �� ���س��� �� �� ���� �� ���Ը�ŭ �ս��� �߻��Ѵ�.
           >> �� ���� �� ���Ը� ���Ѵ�.
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
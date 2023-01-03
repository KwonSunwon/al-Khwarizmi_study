/*---------------------------------
1�� ���� : ���Ϸ��� �ڸ��� ���� ��, ĭ�� ���� ���ڸ� ã�Ƽ� �������� (9x9�� �迭 �ϳ��� ���, ��� ����)

���� �߻� : ��Ÿ�� ���� �߻� ==> int ���� input �޴µ� �����Ͱ� 103000509 << �̷� �������� �̾����� ���� �߻�
     �ذ� : ���ڷ� �޾Ƽ� ������ ��ȯ�Ͽ� ���� �ذ�

1�� ������ ������ : ���� ĭ�� ���ڸ� �˻��ϱ� ���������� �������� ���� �ٲ�� �� �� ��������.
2�� ���� : ���� ��, ĭ�� ����ִ� ���ڵ��� bool ������ ����ؼ� �� ã�� ������ ��.
           ���ȣ���� �̿��ؼ� ���� �ٲ�� �� ��츦 ó��.

���� �߻� : ��� �ʰ� ���� �߻� ==> ���ȣ��� ���� ������ ����� 1ȸ �̻� �ϴ� ��찡 �߻�
    �ذ� :  ��� �Ŀ� exit(0)�� ����.
����.
*/


#include <iostream>
#include <string>
#define MAX 9

using namespace std;

int MAP[MAX][MAX];
bool row[MAX][MAX];
bool col[MAX][MAX];
bool square[MAX][MAX];

void DFS(int);

int main(void) {

    for (int i = 0; i < MAX; i++) {
        string temp;
        cin >> temp;

        for (int j = 0; j < temp.length(); j++) {

            MAP[i][j] = temp[j] - '0';

            if (MAP[i][j] != 0) {
                row[i][MAP[i][j]] = true;
                col[j][MAP[i][j]] = true;
                square[(i / 3) * 3 + (j / 3)][MAP[i][j]] = true;
            }
        }
    }

    DFS(0);

    return 0;
}

void DFS(int count)
{
    int x = count / MAX;    // x ��ǥ
    int y = count % MAX;    // y ��ǥ

    if (count == 81) {
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                cout << MAP[i][j];
            }
            cout << endl;
        }

        exit(0);
    }

    if (MAP[x][y] == 0) {
        for (int i = 1; i <= 9; i++) {
            if (row[x][i] == false && col[y][i] == false && square[(x / 3) * 3 + (y / 3)][i] == false) {
                row[x][i] = true;
                col[y][i] = true;
                square[(x / 3) * 3 + (y / 3)][i] = true;

                MAP[x][y] = i;

                DFS(count + 1);
                MAP[x][y] = 0;
                row[x][i] = false;
                col[y][i] = false;
                square[(x / 3) * 3 + (y / 3)][i] = false;
            }
        }
    }

    else DFS(count + 1);
}
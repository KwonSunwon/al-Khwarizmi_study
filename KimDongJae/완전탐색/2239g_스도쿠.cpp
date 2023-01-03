/*---------------------------------
1차 접근 : 정하려는 자리의 열과 행, 칸에 없는 숫자를 찾아서 대입하자 (9x9의 배열 하나만 사용, 재귀 없이)

문제 발생 : 런타임 에러 발생 ==> int 값을 input 받는데 데이터가 103000509 << 이런 형식으로 이어져서 문제 발생
     해결 : 문자로 받아서 정수로 변환하여 문제 해결

1차 접근의 문제점 : 같은 칸의 숫자를 검색하기 귀찮아지고 무엇보다 답을 바꿔야 할 때 복잡해짐.
2차 접근 : 열과 행, 칸에 들어있는 숫자들을 bool 값으로 기록해서 더 찾기 쉽도록 함.
           재귀호출을 이용해서 답을 바꿔야 할 경우를 처리.

문제 발생 : 출력 초과 문제 발생 ==> 재귀호출로 인한 문제로 출력을 1회 이상 하는 경우가 발생
    해결 :  출력 후에 exit(0)로 종료.
정답.
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
    int x = count / MAX;    // x 좌표
    int y = count % MAX;    // y 좌표

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
/*
접근법 : 직접 배수를 구하고 그 수를 판정하는건 메모리 상으로나 시간상으로나 문제가 크다. 따라서 0 또는 1로 만들어진 1자리 ~ 100자리 수를
        전부 만들어서 트리 형태로 만들고, 순회하면서 그 수가 배수인지 판정한다.

문제 발생 : long long int도 100자리 숫자는 저장 못한다 << string 형태로 써야한다. 
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;
int N;
bool visited[20001] = { 0 };
pair<int, char> arr[20001]; //first에 부모, second에 붙일 숫자를 저장

void BFS() {
    queue<int> que;
    que.push(1);

    arr[1].first = -1;   //부모 노드 번호 표시 (부모가 -1이면 루트 노드인 것)
    arr[1].second = '1'; //N의 배수는 1부터 시작하므로

    visited[1] = true;


    while (!que.empty()) {

        int cur = que.front();
        que.pop();

        //1을 붙인 자식과 0을 붙인 자식을 만듦
        int node[2];
        node[0] = (cur * 10 + 0) % N;
        node[1] = (cur * 10 + 1) % N;

        for (int i = 0; i < 2; i++) {
            if (visited[node[i]]) continue;

            arr[node[i]].first = cur;
            arr[node[i]].second = i + '0'; //숫자를 문자열로 만들어 저장한다.   

            if (node[i] == 0) return;

            visited[node[i]] = true;
            que.push(node[i]);
        }
    }
}

void print(int parent) {
    if (parent == -1) return; //부모 노드가 -1이면 루트 노드

    print(arr[parent].first);
    cout << arr[parent].second;

}

int main() {
    int C; 
    cin >> C;

    for (int i= 1; i <= C; ++i) {

        cin >> N;

        memset(visited, false, sizeof(visited));
        BFS();
        print(0);
        cout << endl;

    }

    return 0;
}
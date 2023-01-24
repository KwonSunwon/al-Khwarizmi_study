/*
���ٹ� : ���� ����� ���ϰ� �� ���� �����ϴ°� �޸� �����γ� �ð������γ� ������ ũ��. ���� 0 �Ǵ� 1�� ������� 1�ڸ� ~ 100�ڸ� ����
        ���� ���� Ʈ�� ���·� �����, ��ȸ�ϸ鼭 �� ���� ������� �����Ѵ�.

���� �߻� : long long int�� 100�ڸ� ���ڴ� ���� ���Ѵ� << string ���·� ����Ѵ�. 
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;
int N;
bool visited[20001] = { 0 };
pair<int, char> arr[20001]; //first�� �θ�, second�� ���� ���ڸ� ����

void BFS() {
    queue<int> que;
    que.push(1);

    arr[1].first = -1;   //�θ� ��� ��ȣ ǥ�� (�θ� -1�̸� ��Ʈ ����� ��)
    arr[1].second = '1'; //N�� ����� 1���� �����ϹǷ�

    visited[1] = true;


    while (!que.empty()) {

        int cur = que.front();
        que.pop();

        //1�� ���� �ڽİ� 0�� ���� �ڽ��� ����
        int node[2];
        node[0] = (cur * 10 + 0) % N;
        node[1] = (cur * 10 + 1) % N;

        for (int i = 0; i < 2; i++) {
            if (visited[node[i]]) continue;

            arr[node[i]].first = cur;
            arr[node[i]].second = i + '0'; //���ڸ� ���ڿ��� ����� �����Ѵ�.   

            if (node[i] == 0) return;

            visited[node[i]] = true;
            que.push(node[i]);
        }
    }
}

void print(int parent) {
    if (parent == -1) return; //�θ� ��尡 -1�̸� ��Ʈ ���

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
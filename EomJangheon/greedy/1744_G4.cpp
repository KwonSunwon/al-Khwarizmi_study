/*
https://www.acmicpc.net/problem/1744
제목: 수 묶기
분류: 그리디 알고리즘
난이도: 골드 4

최초 접근 풀이:
1.음수가 2개 이상 있다면 항상 가장 큰 음수끼리 묶어야한다.
2.음수가 1개, 0이 1개 있다면 항상 묶어야한다.
3.양수가 2개 이상 있다면 항상 가장 큰 양수끼리 묶어야한다.
이를 위해 양수는 최대힙, 음수는 최소힙을 사용하며 0은 존재만을 체크하는 bool 타입

두번째 풀이:
최초 접근으로는 틀린 답이 나왔다.
반례를 찾아보니 1이 있을때 더 큰수와 묶으면 결과가 작아짐
ex)1+20=21-->1*20=20
4.입력중 1이 나오면 ans에 그대로 더하는 조건 추가
*/

#include<iostream>
#include<queue>
using namespace std;


int main()
{
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;
	int ans = 0;
	int numOfInput = 0;
	int tempInput = 0;
	bool isZeroExist = false;

	cin >> numOfInput;

	//음수는 최소힙, 짝수는 최대힙으로 넣어준다(절대값이 큰 것을 뽑기 위해)
	//0은 있는지만 체크한다.
	for (int i = 0; i < numOfInput; ++i)
	{
		cin >> tempInput;
		//추가된 4번째 조건이다.
		if (tempInput == 1)
			ans += 1;

		else if (tempInput < 0)
			min_heap.push(tempInput);
		else if (tempInput > 1)
			max_heap.push(tempInput);
		else if(tempInput==0)
			isZeroExist = true;
	}
	//1. 음수가 2개 이상 있다면 항상 가장 큰 음수끼리 묶는다.
	//반복문의 결과 min_heap은 0개또는 1개의 원소만 남는다.
	while (!min_heap.empty())
	{
		if (min_heap.size() >= 2)
		{
			int first = min_heap.top();
			min_heap.pop();
			int second = min_heap.top();
			min_heap.pop();
			ans += first * second;
		}
		//2. 음수가 1개, 0이 존재 한다면 항상 묶는다.
		//   음수가 1개 있지만 0이 존재 하지 않는다면 그대로 더한다.
		else
		{
			if (isZeroExist)
				ans += 0;
			else
				ans += min_heap.top();
			min_heap.pop();
		}
	}

	//3. 양수가 2개 이상 있다면 항상 가장 큰 양수끼리 묶는다.
	//반복문의 결과 max_heap은 0개또는 1개의 원소만 남는다.
	while (!max_heap.empty())
	{
		if (max_heap.size() >= 2)
		{
			int first = max_heap.top();
			max_heap.pop();
			int second = max_heap.top();
			max_heap.pop();
			ans += first * second;
		}
		//4. 마지막으로 남은 양수가 있다면 더해준다.
		else
		{
			ans += max_heap.top();
			max_heap.pop();
		}
	}

	cout << ans;

}
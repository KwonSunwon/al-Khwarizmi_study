/*
https://www.acmicpc.net/problem/14500
제목: 테트로미노
분류: 완전탐색 알고리즘
난이도: 골드 4

최초 접근 풀이:
각 도형의 좌표값을 저장하고 테이블을 한칸씩 순회하며 모든 도형을
비교하며 넣어본다.
*/

#include<iostream>
using namespace std;
//각 도형을 상대좌표로 저장
int dx[19][4] = {
	{0,1,2,3},{0,0,0,0},//1
	{0,1,0,1},//ㅁ
	{0,0,0,1},{0,1,2,2},{0,1,1,1},{0,0,1,2},//L
	{0,-1,-1,-1},{0,1,2,2},{0,1,1,1},{0,0,1,2},//뒤집힌L
	{0,0,1,1},{0,1,1,2},{0,0,1,1},{0,1,1,2},//Z
	{0,0,0,1},{0,0,0,-1},{0,1,2,1},{0,1,2,1}//ㅗ

};
int dy[19][4] = {
	{0,0,0,0},{0,1,2,3},//1
	{0,0,1,1},//ㅁ
	{0,1,2,2},{0,0,0,-1},{0,0,1,2},{0,-1,-1,-1},//L
	{0,0,1,2},{0,0,0,1},{0,0,-1,-2},{0,1,1,1},//뒤집힌L
	{0,1,1,2},{0,0,-1,-1},{0,-1,-1,-2},{0,0,1,1},
	{0,1,2,1},{0,1,2,1},{0,0,0,-1},{0,0,0,1}//ㅗ
};
int ans = 0;
int height, width;
int table[500][500];
int calcSum(int y,int x,int shape);
int main()
{
	cin >> height >> width;
	//테이블을 입력
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
			cin >> table[i][j];

	//테이블의 모든 칸을 한칸씩 가보며
	//모든 모양을 칸마다 넣어본다.
	for (int i = 0; i < height;++i)
	{
		for (int j = 0; j < width; ++j)
		{
			for (int k = 0; k < 19; ++k)
			{
				int tempSum = calcSum(i,j,k);
				if (tempSum > ans)
					ans = tempSum;	
			}
		}
	}
	cout << ans;
}
int calcSum(int y, int x,int shape)
{
	//만약 상대좌표중 하나라도 테이블을 벗어나면 0을 리턴한다.
	for (int i = 0; i < 4; ++i)
	{
		if (y + dy[shape][i] < 0 || y + dy[shape][i] >= height
			|| x + dx[shape][i] < 0 || x + dx[shape][i] >= width)
			return 0;
	}

	//모든 상대좌표가 테이블에 있다면 해당 칸의 숫자들을 더한뒤 리턴한다.
	int ret = 0;
	for (int i = 0; i < 4; ++i)
		ret += table[y + dy[shape][i]][x + dx[shape][i]];
	
	return ret;
}


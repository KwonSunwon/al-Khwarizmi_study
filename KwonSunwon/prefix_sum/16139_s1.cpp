/*
Create by KwonSunwon on 2023-01-21.
Title: 인간-컴퓨터 상호작용
Rating: S1
Link: https://www.acmicpc.net/problem/16139
Language: C++20
*/

#include <iostream>
#include <string>

using namespace std;

int alphabet[26][200001] = {0};
string s;
int q;
char c;
int a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        alphabet[s[i] - 'a'][i]++;
        for (int j = 0; j < 26; j++)
        {
            alphabet[j][i + 1] = alphabet[j][i];
        }
    }

    cin >> q;

    for (int i = 0; i < q; i++)
    {
        cin >> c;
        cin >> a >> b;
        if (a == 0)
            cout << alphabet[c - 'a'][b] << "\n";
        else
            cout << alphabet[c - 'a'][b] - alphabet[c - 'a'][a - 1] << "\n";
    }

    return 0;
}
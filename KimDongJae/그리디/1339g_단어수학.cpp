#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

set<char> pool;

int index_finder(char);

int main() {
	int EA{ 0 };
	int value[10]{ 0, };
	int large[10];
	long long result{ 0 };
	vector<string> words;

	//get Input
	cin >> EA;
	for (int i = 0; i < EA; i++) {
		string temp;
		cin >> temp;
		words.emplace_back(temp);
	}

	//make words pool
	for (int i = 0; i < EA; i++) {
		for (int j = 0; j < words[i].length(); j++) {
			pool.insert(words[i][j]);
		}
	}

	//give each words value
	for (int i = 0; i < EA; i++) {
		for (int j = 0; j < words[i].length(); j++) {
			value[index_finder(words[i][j])] += pow(10, (words[i].length() - 1) - j);
		}
	}

	//by value, give each words real value(9~0) ..poor work..
	for (int i = 0; i < 10; i++) {
		int max = 0;
		int index = 0;
		for (int j = 0; j < 10; j++) {
			if (value[j] > max) {
				max = value[j];
				index = j;
			}
		}
		if (max == 0) {
			for (int k = i; k < 10; k++) {
				large[k] = 10;
			}
			break;
		}
		value[index] = 0;
		large[i] = index;
	}

	for (int i = 0; i < 10; i++) {
		if (large[i] == 10) break;
		value[large[i]] = (9 - i);
	}

	for (int i = 0; i < EA; i++) {
		for (int j = 0; j < words[i].length(); j++) {
			result += value[index_finder(words[i][j])] * pow(10, (words[i].length() - 1) - j);
		}
	}

	cout << result;
}


//func for find index for word in 10 words
int index_finder(char target) {
	int index{ 0 };
	int word{ 65 };

	while (char(word) != target) {
		if (pool.find(char(word)) != pool.end()) {
			++index;
		}

		++word;
	}

	return index;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int length;
int arr[1000];
vector<int> res;

int main() {
	cin >> T;

	for (int t = 0; t < T; ++t) {
		cin >> length;
		vector<int> tem_res;
		int temp{-1001};

		for (int i = 0; i < length; ++i) {
			cin >> arr[i];
		}

		for (int i = 0; i < length; ++i) {
			temp = max((temp + arr[i]), arr[i]);
			tem_res.emplace_back(temp);
		}

		sort(tem_res.begin(), tem_res.end());

		res.emplace_back(tem_res[length - 1]);
	}

	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}
}
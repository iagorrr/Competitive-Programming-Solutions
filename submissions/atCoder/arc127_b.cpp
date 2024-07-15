#include <bits/stdc++.h>
using namespace std;

vector<int> b3(int x) {
	cerr << x << '\n';
	vector<int> ret;
	for (int i = x; i ; i /= 3) {
		ret.push_back((i % 3));
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, l;
	cin >> n >> l;

	vector<vector<int>> xs;
	int p3 =1;
	for (int i = 0; i < l-1; i++, p3*=3);

	for (int i = 0; i < n; i++) {
		xs.push_back(b3(p3 * 2 + i));
	}

	for (int i = 0; i < 3; i++) {
		for (auto num : xs) {
			for (auto j : num) {
				cout << (j + i) % 3;
			}
			cout << '\n';
		}
	}
}

// AC, strings, math

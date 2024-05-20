#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod = 1'000'000'000 + 7;

auto run() {
	string s;
	cin >> s;

	string p = "chokudai";
	map<string,ll> hist;

	hist[""] = 1;

	for (auto c : s) {
		string tmp = "";
		for (auto c2 : p) {
			string prev = tmp;
			tmp.push_back(c2);
			if (c2 == c) {
				hist[tmp] = (hist[tmp] + hist[prev]) % mod;
			}

		}
	}

	cout << (hist[p] % mod) << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}

// AC, strings, combinatorics

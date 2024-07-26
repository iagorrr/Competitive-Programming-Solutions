#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	string t;
	cin >> t;

	vector<int> xs;
	for (auto c : s) xs.emplace_back((int)c-'a');
	vector<int> ys;
	for (auto c : t) ys.emplace_back((int)c-'a');


	int m = 'z'-'a'+1;
	for (int i = 0; i <= 30; i++) {
		bool ok = true;
		for (int j = 0; j < s.size(); j++) {
			ok &= (((xs[j]+i) % (m)) == ys[j]);
		}

		if (ok) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";

}

// AC, brute force, strings

#include <bits/stdc++.h>
using namespace std;

auto run() {
	int n, k;
	cin >> n >> k;

	bitset<30> b(n);

	if (b.count() > k) {
		cout << "NO\n";
	}
	else {
		multiset<int> ans;
		for (int i = 0; i < 30; i++) {
			if (b[i]) ans.insert(1<<i);
		}

		while(ans.size() != k) {
			auto m = *ans.rbegin();
			ans.erase(ans.find(m));

			if (m == 1) {
				cout << "NO\n";
				return;
			}

			ans.insert(m/2);
			ans.insert(m/2);
		}

		cout << "YES\n";
		for (auto i : ans) {
			cout << i << ' ';
		}
		cout << '\n';

	}
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}

// AC, math, greddy

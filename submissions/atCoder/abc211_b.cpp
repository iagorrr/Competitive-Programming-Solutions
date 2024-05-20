#include <bits/stdc++.h>
using namespace std;

using ll = long long;

auto run() {
	vector<string> ps({
			"H", "2B", "3B", "HR"
		});

	bool ans = false;
	set<string> st;
	for (int i = 0; i < 4; i++) {
		string xi;
		cin >> xi;
		for (auto pi  :ps) {
			if (xi == pi) {
				st.emplace(pi);
			}
		}
	}

	if (st.size() == 4) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}

}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}

// AC, ad-hoc, strings

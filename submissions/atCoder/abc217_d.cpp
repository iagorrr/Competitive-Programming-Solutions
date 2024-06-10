#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int l, q;
	cin >> l >> q;

	set<pair<int,int>> st;
	st.emplace(1, l);

	while(q--) {
		int o, xi;
		cin >> o >> xi;

		auto it = st.lower_bound({xi,2*1e9});
		it = prev(it);

		auto [l, r] = *it;

		if (o == 1) {
			st.erase({l,r});
			st.emplace(l, xi);

			if (xi + 1 <= r)
				st.emplace(xi+1, r);
		}
		else {
			cout << r-l + 1 << '\n';
		}
	}
}

// AC, data structures, binary search


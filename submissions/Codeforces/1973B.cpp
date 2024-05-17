#include <bits/stdc++.h>
using namespace std;

auto run() {
	int n;
	cin >> n;
	vector<int> xs(n);
	for (auto &xi : xs) cin >> xi;

	int ans = n;

	auto eval = [&](array<int,22> hs) -> int {
		int ans = 0;
		for (int j = 0; j < 22; j++) {
			if (hs[j]) ans += (1<<j);
		}
		return ans;
	};

	auto check = [&](int sz) -> bool {
		//cerr << "sz: " << sz << '\n';;
		set<int> st;
		array<int, 22> hs;
		for (int i =0 ;i < 22; i++) hs[i] = 0;
		for (int i = 0; i < sz; i++) {
			auto xi = xs[i];
			for(int j =0; j < 22; j++) {
				if (xi & (1<<j)) {
					hs[j]++;
				}
			}
		}
		//cerr << "	eval: " << eval(hs) << '\n';
		st.emplace(eval(hs));
		for (int l = 0, r = sz; r < n; l++, r++) {
			auto xl = xs[l];
			auto xr = xs[r];


			for(int j =0; j < 22; j++) {
				if (xl & (1<<j)) {
					hs[j]--;
				}

				if (xr & (1<<j)) {
					hs[j]++;
				}
			}

			//cerr << "	eval: " << eval(hs) << '\n';
			st.emplace(eval(hs));
		}
		return st.size() == 1;
	};

	for (int l = 1, r = n-1; l<=r;) {
		int mid = midpoint(l,r);

		if (check(mid)) {
			ans = min(ans, mid);
			r = mid -1;
		}
		else l = mid +1;
	}

	cout << ans << '\n';

}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;

	while (tt--) {
		run();
	}
}
 

// AC, binary search, bitwise

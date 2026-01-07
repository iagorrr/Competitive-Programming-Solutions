#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<ll> cs(n);
	for (int i = 0; i < n; i++) {
		cin >> cs[i];
	}

	vector<ll> as(n);
	for (int i = 0; i < n; i++) {
		cin >> as[i];
	}

	vector<ll> bs(n);
	for (int i = 0; i < n; i++) {
		cin >> bs[i];
	}

	vector<vector<ll>> memo(n, vector<ll>(2, -1));
	auto f = [&](auto&& _f, int i, bool c) {
		if (i == n) return 0ll;

		auto& ret = memo[i][c];
		if (~ret) return ret;

		ret = 0;
		if (c) {
			if (i + 1 < n)
				ret = max(ret, 
						2 + 
						abs(as[i+1] - bs[i+1]) +
						_f(_f, i + 1, 0));
		}
		else {
			ret = max(ret, cs[i] - 1);
			if (i + 1 < n and as[i+1] != bs[i+1])
				ret = max(ret, 
						2 +
						cs[i] - abs(as[i+1] - bs[i+1]) - 1 +
					       	_f(_f, i + 1, 0));
		}


		return ret;
	};

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, f(f, i, 1));
	}
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(!cin.tie(0));
	int t;
	cin >> t;
	while(t--) solve();
}

// dp, graphs

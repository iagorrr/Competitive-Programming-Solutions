#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> xs(n+1);
	xs[0] = 1'000'000'000 + 1;
	for (int i = 1; i <= n; i++) cin >> xs[i];


	vector<int> gecl(n+1);

	vector<ll> stk;
	stk.push_back(0);
	for (int i = 1; i <= n; i++) {
		while (xs[stk.back()] <= xs[i]) stk.pop_back();
		gecl[i] = stk.back();
		stk.push_back(i);
	}

	vector<ll> ans(n+1);
	ll cur = 1;
	for (ll i = 1; i <= n; i++) {
		if (xs[i] > xs[i-1]) {
			auto gi = gecl[i];
			cur = ans[gi] + (i-gi)*xs[i] + (gi == 0);
			ans[i] = cur;
		}
		else {
			cur = cur + xs[i];
			ans[i] = cur;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " \n"[i==n];
	}
}

// AC, math, stack, data structures

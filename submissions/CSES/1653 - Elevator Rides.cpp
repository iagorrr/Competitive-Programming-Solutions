#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int n, k;
	cin >> n >> k;

	vector<int> xs(n);
	for (auto &xi : xs) cin >> xi;

	vector<pair<int,int>> dp(1<<n, {n+1, k+1});
	dp[0] = {1, 0};

	for (int m = 1; m < 1<<n; m++) {
		for (int i = 0; i < n; i++) {
			if (!(m&(1<<i))) continue;

			int pm = m ^ (1<<i);
			auto [pr, pw] = dp[pm];

			if (pw + xs[i] <= k) {
				dp[m] = min(dp[m], {pr, pw + xs[i]});
			}
			else {
				dp[m] = min(dp[m], {pr+1, xs[i]});
			}
		}
	}

	auto [ans, _] = dp[(1<<n)-1]; 
	cout << ans << '\n';
}

// AC, bitmask dp

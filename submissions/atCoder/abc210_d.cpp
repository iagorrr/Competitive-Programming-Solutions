#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<ll>> grid;
int h, w;
ll c;
ll solve() {
	vector<vector<ll>> dp(h, vector<ll>(w));
	dp[0][0] = grid[0][0];
	for (int i = 0; i < h; i++) {
		for (int j = 0 + !i; j < w; j++) {
			dp[i][j] = grid[i][j];
			if (j-1 >= 0) 
				dp[i][j] = min(dp[i][j], dp[i][j-1] + c);

			if (i-1 >= 0) 
				dp[i][j] = min(dp[i][j], dp[i-1][j] + c);

		}
	}


	ll ans = numeric_limits<ll>::max();

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (j-1 >= 0) 
				ans = min(ans, grid[i][j] + dp[i][j-1] + c);

			if (i-1 >= 0) 
				ans = min(ans, grid[i][j] + dp[i-1][j] + c);

		}
	}
	return ans;
}

auto run() {
	cin >> h >> w;
	cin >> c;

	grid = vector<vector<ll>>(h, vector<ll>(w));
	for (auto &i : grid) {
		for (auto &j : i) cin >> j;
	}
	auto ans1 = solve();

	for (auto &i : grid) {
		reverse(i.begin(), i.end());
	}
	auto ans2 = solve();

	auto ans = min(ans1, ans2);

	cout << ans << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}

// AC, dynamic programming

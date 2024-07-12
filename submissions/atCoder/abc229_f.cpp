#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll oo = 1e16;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> as(n+1);
	for (int i = 1; i <= n; i++)
		cin >> as[i];

	vector<int> bs(n+1);
	for (int i = 1; i <= n; i++)
		cin >> bs[i];

	vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(2, vector<ll>(2, oo)));
	dp[1][0][0] = as[1];
	dp[1][1][1] = 0;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				for (int pj = 0; pj < 2; pj++) {
					dp[i][j][k] = min({
							dp[i][j][k],
							dp[i-1][pj][k] + (pj == j?bs[i-1]:0) + (j?0:as[i])
					});
				}
			}
		}
	}

	ll ans = oo;
	for (int j = 0; j < 2; j++) {
		for (int k = 0; k < 2; k++) {
			ans = min({
				ans,
				dp[n][j][k] + (j == k ? bs[n] : 0)
			});

		}
	}

	cout << ans << '\n';
}

// AC, dynamic programming, graphs

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 50 + 2;
ll grid[MAXN][MAXN];
ll pre[MAXN][MAXN];
ll cur[MAXN][MAXN];

ll n, m, k, si, sj;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	cin >> si >> sj;
	si--, sj--;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	vector<pair<int,int>> dc({{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {0, 0}});

	for (auto [di, dj] : dc) {
		int i2 = si+di;
		int j2 = sj+dj;

		if (i2 >= 0 and j2 >= 0 and i2 < n and j2 < m)
			pre[i2][j2] = grid[i2][j2];
	}

	k--;
	for (int h = 0; h<n*m and k ;h++ ) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ll mx = 0;
				for (auto [di, dj] : dc) {
					int i2 = i + di;
					int j2 = j + dj;
					if (i2 >= 0 and j2 >= 0 and i2 < n and j2 < m)
						mx = max(mx, pre[i2][j2]);

				}
				cur[i][j] = mx!=0 ? grid[i][j] + mx : 0;
				cnt += cur[i][j] != 0;
			}
		}
		swap(pre, cur);
		k--;
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (pre[i][j]) {
				ans = max(ans, pre[i][j] + grid[i][j]*k);
			}
			
		}
	}
	cout << ans << '\n';
}

// AC, dynamic programming

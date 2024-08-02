#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<string> GRID(7);
	for (auto& s : GRID)
		cin >> s;

	int D, H;
	cin >> D >> H;

	using ld = long double;
	ld ans = 0.0;
	for (int mask = 0; mask < (1<<7); mask++) {
		vector perhour(24, 0);

		if (__builtin_popcount(mask) != D)
			continue;

		for (int d = 0; d < 7; d++) {
			if (mask & (1<<d)) {
				for (int h = 0; h < 24; h++) {
					perhour[h] += (GRID[d][h] == '.');
				}
			}
		}

		sort(perhour.rbegin(), perhour.rend());
		int tot = accumulate(perhour.begin(), perhour.begin() + H, 0);

		ans = max(ans, (ld)tot / (ld)(H*D));
	}

	cout << fixed << setprecision(10) << ans << '\n';
}

// AC, brute force

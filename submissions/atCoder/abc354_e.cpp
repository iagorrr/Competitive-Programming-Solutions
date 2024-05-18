#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
vector<pair<ll,ll>> xs;
int memo[(1ll<<20)];

int solve(int mask) {
	auto &ans = memo[mask];
	if (ans != -1) return ans;

	ans = false;

	for (int i = 0; i < n; i++) {
		if (mask&(1<<i)) continue;
		for (int j = i + 1; j < n; j++) {
			if (mask&(1<<j)) continue;
			int new_mask = mask;
			new_mask |= (1<<i);
			new_mask |= (1<<j);
			if (xs[i].first == xs[j].first) {

				ans |= !solve(new_mask);
			}
			if (xs[i].second == xs[j].second) {
				ans |= !solve(new_mask);
			}
		}
	}

	return ans;
}

auto run() {
	memset(memo, -1, sizeof memo);

	cin >> n;
	
	xs.resize(n);
	for (auto &[a, b] : xs) cin >> a >> b;

	cout << (solve(0) ? "Takahashi" : "Aoki") << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}


// AC, dp, dynamicp programming

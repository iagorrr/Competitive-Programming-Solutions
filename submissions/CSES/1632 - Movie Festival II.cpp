#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	
	vector<pair<int,int>> xs(n);
	for (auto &[l, r] : xs) cin >> l >> r;

	sort(xs.begin(), xs.end(), [&](const pair<int,int> &a, const pair<int,int>& b) {
		return a.second == b.second ? a.first <= b.first : a.second < b.second;
	});



	multiset<int> free_at;
	for (int i = 0; i < k; i++) free_at.emplace(0);
	
	int ans = 0;
	for (auto &[l, r] : xs ) {
		auto best = free_at.lower_bound(l+1);

		if (best != free_at.begin()) {
			best = prev(best);
			free_at.extract(*best);
			free_at.emplace(r);
			ans++;
		}
	}


	cout << ans << '\n';
}

// AC, greddy, sorting, data structures, lower bound

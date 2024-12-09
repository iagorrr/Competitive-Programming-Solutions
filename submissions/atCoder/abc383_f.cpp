#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll memo[50000 + 1][500+1][2];

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(0));
	memset(memo, -1, sizeof memo);

	int N, X, K;
	cin >> N >> X >> K;

	vector<array<int,3>> items(N);
	for (auto &[c, p, u] : items) {
		cin >> p >> u >> c;
	}
	sort(items.begin(), items.end());

	items.push_back(array<int,3>{-1, 0, 0});
	function<ll(int, int, int)> solve =
		[&](int x, int i, int t) {
			if (i == N) return 0ll;

			auto &ret = memo[x][i][t];
			if (~ret) return ret;
			
			auto &[c, p, u] = items[i];
			if (p <= x) {
				ret = u + !t*K + solve(x-p, i+1, c==items[i+1][0]);
			}

			return ret = max(ret, solve(x, i + 1, (t and c==items[i+1][0])));

		};

	cout << solve(X, 0, 0) << '\n';
}

/*
	AC, dynamic programming
 */

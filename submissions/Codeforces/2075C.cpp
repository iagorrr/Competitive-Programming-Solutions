#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	ll N, M;
	cin >> N >> M;

	vector<ll> AS(M);
	for (auto &ai : AS) {
		cin >> ai;
		ai = min(ai, N-1);
	}

	sort(begin(AS), end(AS));

	vector<ll> psum(AS);
	partial_sum(begin(psum), end(psum), begin(psum));

	ll ans = 0;

	for (int i = 1; i < M; i++) {
		if (AS[i] + AS[i-1] < N) continue;

		int j = i-1;
		for (int l = 0, r = i -1; l <= r; ) {
			int m = midpoint(l, r);
			if (AS[m] + AS[i] >= N) {
				j = min(j, m);
				r = m - 1;
			}
			else l = m + 1;
		}



		ll acc = psum[i-1] - (j ? psum[j-1] : 0ll);
		ll sz = ((i-1) - j) + 1;
		ll dec = sz * (-(N-AS[i]) + 1);
		//cerr << "acc: " << acc << '\n';

		ans += (acc+dec) * 2;
	}

	cout << ans << '\n';

}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		solve();
	}

}

/*
 * naive way yould be N^2
 * but we just need to see that for two colors if we can pain't all the fences we have
 * n ways of do it, just rotate the current paiting
 *
 * a := 1 
 * b := N - 1
 *
 * we have N possible ways...
 *
 * N = 5
 * a := 5, b := 5
 *
 * N - 1 ways varying the amount of a
 * for each way we have n ways to position it
 *
 * make a accmuluate for how many the quantity can vary
 * and multiply this by N always
 *
 * we can fix the quantity of the first
 * see how muc hwe have with this quantity
 *
 * see how much we have with the quantity of the complement
 *
 * for a specifc color i can only chose colors that have more or equal
 * it's complement
 * 
 * it must be O(M)
 *
 * combinatorics
 * */

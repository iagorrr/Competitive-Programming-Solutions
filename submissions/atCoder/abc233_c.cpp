#include <bits/stdc++.h>
using namespace std;

/*
   só interessa os que são divisores de X
 */
using ll = long long;
auto run() {
	ll N, X;
	cin >> N >> X;

	vector<vector<ll>> XS(N);
	for (int i = 0; i < N; i++) {
		ll L;
		cin >> L;

		for (int l = 0; l < L; l++) {
			ll aij;
			cin >> aij;
			if (X%aij==0) XS[i].emplace_back(aij);
		}

	}

	map<ll, ll> ways;
	for (auto j : XS[0])
		ways[j]++;

	for (int i = 1; i < N; i++) {
		map<ll,ll> nways;
		for (auto [v, q] : ways) {
			for (auto j : XS[i]) {
				if (v*j <= X)
				nways[v*j] += q;
			}
		}
		ways = nways;
	}

	cout << ways[X] << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	// cin >> T;

	for (int i = 1; i <= T; i++) {
		run();
	}

}

// AC, math, brute force

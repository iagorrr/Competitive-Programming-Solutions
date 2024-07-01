#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n,  k;
	cin >> n >> k;

	vector<ll> xs(n);
	multiset<pair<ll,int>> st;
	for (int i = 0; i < n; i++) {
		auto &xi = xs[i];
		cin >> xi;
		if (xi) st.emplace(xi, i);
	}

	// paro quando não consigo remover alguem
	// decremento do mundo até onde der
	// e o restin eu simulo
	vector<ll> ans(n);

	ll k2 = 0, all = 0;
	multiset<pair<int, ll>> pending;
	while (!st.empty() and k2 < k) {
		// galera que ja foi removida antes
		while (!st.empty()) {
			auto [v, idx] = *st.begin();
			if (v <= all)
				st.erase(st.begin());
			else break;
		}

		auto [v, idx] = *st.begin();
		v -= all;

		// da pra remover ele ?
		if (v * (ll)st.size() + k2 <= k) { // sim
			k2 += v * (ll)st.size();
			all += v;

		}
		else { // no kkk
			// remover o quanto der de todos
			ll all2 = (k-k2)/(ll)st.size();
			k2 = k2 + (k-k2)/(ll)st.size() * (ll)st.size();
			for (auto [ v, idx ] : st) {
				v -= all;
				v -= all2;
				pending.emplace(idx, v);
			}

		
			break;
			
		}

	}

	// simular comçando do de menor indice !
	for (auto [idx, v] : pending) {
		if (k2 < k) {
			v--;
			k2++;
		}
		ans[idx] =  v;
	}

	for (auto i : ans) cout << i << ' ';
	cout << '\n';
}

// AC, greddy, simulation

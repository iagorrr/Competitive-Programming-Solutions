#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> as(n);
	for (auto &ai : as) cin >> ai;


	sort(as.begin(), as.end());

	vector<ll> dg(n, 2);
	dg[n-1] = dg[n-2] = 1;


	set<pair<ll,ll>> decre, incre;
	for (int i = 0; i < n; i++) {
		auto cur = (ll)dg[i]*dg[i]*as[i];

		dg[i]--;
		auto pre = dg[i] ? cur - (ll)dg[i]*dg[i]*as[i] : -1;

		dg[i] += 2;
		auto nxt = (ll)dg[i]*dg[i]*as[i] - cur;

		decre.emplace(pre, i);
		incre.emplace(nxt, i);
		dg[i]--;
	}

	for ( ; ; ) {
		auto [de, id] = *decre.rbegin();
		auto [in, ii] = *incre.begin();

		/*
		for (int i = 0; i < n; i++) {
			cerr << dg[i] << ' ';
		}
		cerr << '\n';
		cerr << de << ' ' << in << '\n';
		*/

		if (de <= in) break;

		assert(id != ii);

		decre.erase({de, id});
		incre.erase({in, ii});

		dg[ii]++;
		dg[id]--;

		for (auto i : {ii, id}) {
			auto cur = (ll)dg[i]*dg[i]*as[i];

			dg[i]--;
			auto pre = dg[i] ? cur - (ll)dg[i]*dg[i]*as[i] : -1;

			dg[i] += 2;
			auto nxt = (ll)dg[i]*dg[i]*as[i] - cur;

			decre.emplace(pre, i);
			incre.emplace(nxt, i);
			dg[i]--;
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		auto cur = dg[i]*dg[i]*as[i];
		ans += cur;
	}

	cout << ans << '\n';
}

// AC, greddy, data structures

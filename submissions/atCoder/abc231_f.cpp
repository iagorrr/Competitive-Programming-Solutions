#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;

using ll = long long;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;

	vector<pair<ll,ll>> xs(n);
	for (auto &[a, b] : xs)
		cin >> a;

	for (auto &[a, b] : xs)
		cin >> b;

	map<ll, vector<ll>> mp;
	for (auto &[a, b] : xs)
		mp[a].emplace_back(b);

	ll ans = 0;

	ordered_set<pair<ll,ll>> st;
	int id = 0;
	for (auto& [k, vs] : mp) {
		for (auto& b : vs) {
			st.insert({b, id++});
		}

		for (auto& b : vs) {
			ll cur = (ll)(st.size() - st.order_of_key({b, -1}));
			ans += cur;
		}
		/*

		cerr << a << ' ' << b << ": " ;
		for (auto [k, _] : st) cerr << k << ' ';
		cerr << "cur: " << cur << '\n';
		*/

	}

	cout << ans << '\n';

	
}
o
// AC, data structures, ordered set

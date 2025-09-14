#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	ll k, x;
	cin >> k >> x;

	ll  a = x, b = (1ll<<(k+1)) - x;

	vector<ll> ans;

	while (a != b) {
		if (a > b) {
			ans.push_back(2);
			a -= b;
			b <<= 1ll;
		}
		else {
			ans.push_back(1);
			b -= a;
			a <<= 1ll;
		}
	}

	cout << ans.size() << '\n';
	reverse(ans.begin(), ans.end());
	for (auto ai : ans) cout << ai << ' ';
	cout << '\n';

}

signed main() {
	ios_base::sync_with_stdio(!cin.tie(0));
	int t;
	cin >> t;
	while(t--) solve();
}

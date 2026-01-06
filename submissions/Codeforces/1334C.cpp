#include <vector>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<ll> as(n), bs(n);
	for (int i = 0; i < n; i++) {
		cin >> as[i] >> bs[i];
	}

	ll s = 0;
	for (int i = 0; i < n; i++) {
		int p = i ? i - 1 : n - 1;
		s += max(0ll, as[i] - bs[p]);
	}

	ll v = LLONG_MAX;
	for (int i = 0; i < n; i++) {
		v = min(v, as[i] - max(0ll, as[i] - bs[ i ? i - 1 : n - 1 ]));
	}
	s += v;

	cout << s << '\n';
}

signed main() {
	ios_base::sync_with_stdio(!cin.tie(0));
	int t;
	cin >> t;
	while (t--) solve();
}

// AC, math, greedy, brute force

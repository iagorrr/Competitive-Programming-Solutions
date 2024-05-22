#include <bits/stdc++.h>
using namespace std;

using ll = long long;
auto run() {
	ll n, a, x, y;
	cin >> n >> a >> x >> y;
	ll ans = 0;
	ans += min(n, a)*x;
	n -= a;
	ans += max(0ll, n)*y;
	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}


// AC, ad-hoc

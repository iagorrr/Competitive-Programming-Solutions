#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	string s;
	cin >> s;

	int one = count(begin(s), end(s), '1');
	int ans = one;
	for (int d = 0; d < one; d++) {
		ans -= (s[n-d-1] == '1');

	}

	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(!cin.tie(0));
	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}
/*
 * 110100
 *
 *
 * */


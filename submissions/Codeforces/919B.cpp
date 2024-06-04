#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXLEN = 19;

ll memo[MAXLEN][10 + 1];
ll dp(int p, int sum, bool low, const vector<int> &digits) {
	if (sum > 10) return 0;
	if (p < 0) return sum == 10;

	auto &res = memo[p][sum];
	if (low and res != -1) return res;

	int mx = low ? 9 : digits[p];
	ll ret = 0;
	for (int d = 0; d <= mx; d++) {
		ret += dp(p-1, sum + d, low | (d<digits[p]), digits);
	}
	return low ? res = ret : ret;
}

ll solve(ll n) {
	vector<int> digits;
	for ( ; n; n /= 10) {
		digits.emplace_back(n%10);
	}
	return dp(digits.size() - 1u, 0, false, digits);
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(memo, -1, sizeof memo);

	ll N;
	cin >> N;

	const ll oo = 1e18;
	ll ans = oo;
	for (ll l = 1, r = oo; l <= r;) {
		ll mid = midpoint(l, r);
		if (solve(mid) >= N) {
			ans = min(ans, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}

	cout << ans << '\n';
}

// AC, binary search, dynamic programming digit

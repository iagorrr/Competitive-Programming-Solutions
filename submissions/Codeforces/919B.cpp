#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXLEN = 20;
constexpr int MAXSUM = MAXLEN*9;

ll memo[MAXLEN][MAXSUM+1];
ll _solve(int p, bool lower, int sum, const string &digits) {
	if (p == (int)digits.size()) {
		return (sum == 10);
	}

	ll &ans = memo[p][sum];
	if (lower and ans != -1) return ans;


	ll ret = 0;

	int mx = lower ? 9 : digits[p] - '0';
	for (int d = 0; d <= mx; d++) {
		ret += _solve(p + 1, lower || (d < digits[p]-'0'), sum+d, digits);
	}

	return lower ? ans = ret : ret;
}

ll solve(ll n) {
	string digits = to_string(n);
	memset(memo, -1, sizeof memo);
	return _solve(0, 0, 0, digits);
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

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
